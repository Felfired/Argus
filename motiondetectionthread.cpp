#include "motiondetectionthread.h"
#include "motiondetection.h"

MotionDetectionThread::MotionDetectionThread(const QString& videoPath, const QString& namesFilePath,
    const QString& weightsFilePath, const QString& configFilePath,
    const QString& outputVideoPath, bool imgsaveFlag, bool timestampFlag, bool fbfFlag, 
    double sensitivity, int frameskipNum, QObject* parent)
    : QThread(parent), m_videoPath(videoPath), m_namesFilePath(namesFilePath),
    m_weightsFilePath(weightsFilePath), m_configFilePath(configFilePath),
    m_outputVideoPath(outputVideoPath), m_imgsaveFlag(imgsaveFlag), 
    m_timestampFlag(timestampFlag), m_fbfFlag(fbfFlag), m_sensitivity(sensitivity),
    m_frameskipNum(frameskipNum)
{
    // Constructor does not contain anything.
}

void MotionDetectionThread::initializeClasses(const std::string& namesFilePath)
{
    emit currentStatus("Αρχικοποιήση ονομάτων...");
    int totalLines = getClassFileSize(namesFilePath);
    int linesProcessed = 0;

    std::ifstream namesFile(namesFilePath);
    std::string line;

    while (namesFile >> line)
    {
        if (line.find("person"))
        {
            classes.push_back(line);
        }
        else if (line.find("car"))
        {
            classes.push_back(line);
        }
        linesProcessed++;
        int progress = static_cast<int>((linesProcessed / static_cast<double>(totalLines)) * 100);
        emit loadingProgress(progress);
    }

    namesFile.close();
    emit resetProgress();
}

int MotionDetectionThread::getClassFileSize(const std::string& namesFilePath)
{
    int totalLines = 0;
    std::ifstream namesFile(namesFilePath);
    std::string line;
    while (namesFile >> line)
    {
        totalLines++;
    }
    namesFile.clear();
    namesFile.seekg(0);
    namesFile.close();
    return totalLines;
}

void MotionDetectionThread::initializeDNN(const std::string& weightsFilePath, const std::string& configFilePath)
{
    DNN = cv::dnn::readNetFromDarknet(configFilePath, weightsFilePath);
    detectionModel = cv::dnn::DetectionModel(DNN);
    detectionModel.setInputParams(1 / 255.0, cv::Size(416, 416), cv::Scalar(), true);
}

void MotionDetectionThread::detectObjects(cv::Mat& frame, std::vector<int>& classIds,
    std::vector<float>& scores, std::vector<cv::Rect>& boxes, const std::vector<std::string>& classes, double sensitivity)
{
    detectionModel.detect(frame, classIds, scores, boxes, sensitivity, 0.4);

    for (int i = 0; i < classIds.size(); i++)
    {
        cv::rectangle(frame, boxes[i], cv::Scalar(0, 255, 0), 2);
        char text[100];
        snprintf(text, sizeof(text), "%s: %.2f", classes[classIds[i]].c_str(), scores[i]);
        cv::putText(frame, text, cv::Point(boxes[i].x, boxes[i].y - 5), cv::FONT_HERSHEY_SIMPLEX, 1,
            cv::Scalar(0, 255, 0), 2);
        // If timestamp flag is enabled write the detected classes to a vector of strings.
        if (m_timestampFlag == true)
        {
            detectedClasses.push_back(classes[classIds[i]].c_str());
        }
    }
}

void MotionDetectionThread::writeToVideo(std::vector<cv::Mat> framesWithObjects, cv::VideoCapture videoCap, QString outputVideoPath)
{
    emit currentStatus("Δημιουργία βίντεο...");
    int frameWidth = videoCap.get(cv::CAP_PROP_FRAME_WIDTH);
    int frameHeight = videoCap.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::string stdOVP = outputVideoPath.toStdString() + "/result.mp4";

    cv::VideoWriter videoWriter(stdOVP, cv::VideoWriter::fourcc('H', '2', '6', '4'), 30, cv::Size(frameWidth, frameHeight));
    int processedFrames = 0;
    int totalFramesWithObjects = framesWithObjects.size();

    // Write frames with detected objects to the output video.
    for (const cv::Mat& outputFrame : framesWithObjects)
    {
        videoWriter.write(outputFrame);
        processedFrames++;
        int progress = static_cast<int>((processedFrames / static_cast<double>(totalFramesWithObjects)) * 100);
        emit loadingProgress(progress);
    }

    // Release the video writer.
    videoWriter.release();
    qDebug() << stdOVP;
}

void MotionDetectionThread::writeToTxt(std::vector<std::string> detectedClasses, std::vector<double> timestampVector, QString outputVideoPath)
{
    emit currentStatus("Εγγραφή χρονικών στιγμών σε αρχείο κειμένου...");
    std::string txtPath = outputVideoPath.toStdString() + "/result.txt";
    int currentLine = 0;
    std::ofstream outputFile;
    outputFile.open(txtPath);

    if (!outputFile.is_open())
    {
        qDebug() << "Failed to open output text file.";
        return;
    }
    
    // Write detected classes and timestamps to the file.
    for (size_t i = 0; i < detectedClasses.size(); ++i)
    {
        currentLine++;
        // Convert timestamp to hh:mm:ss format
        int hours = static_cast<int>(timestampVector[i]) / 3600;
        int minutes = static_cast<int>(timestampVector[i]) % 3600 / 60;
        int seconds = static_cast<int>(timestampVector[i]) % 60;

        // Write to file in the format "detected_class timestamp (hh:mm:ss)".
        outputFile << detectedClasses[i] << " " << " (" << std::setfill('0') << std::setw(2) << hours << ":" << std::setw(2) << minutes << ":" << std::setw(2) << seconds << ")" << std::endl;
        int progress = static_cast<int>((currentLine / static_cast<double>(detectedClasses.size()) * 100));
        emit loadingProgress(progress);
    }

    // Close the file.
    outputFile.close();
}

void MotionDetectionThread::writeToImage(std::vector<cv::Mat> framesWithObjects, std::vector<double> timestampVector, QString outputVideoPath)
{
    emit currentStatus("Αποθήκευση εικόνων στον φάκελο που ορίσατε...");
    int totalFrames = framesWithObjects.size();
    int savedFrames = 0;

    if (framesWithObjects.size() != timestampVector.size()) 
    {
        // Handle error: Size mismatch.
        return;
    }

    // Loop through frames and save each one.
    for (size_t i = 0; i < framesWithObjects.size(); ++i) 
    {
        savedFrames++;
        // Generate filename using timestamp
        QString filename = QString("%1/%2.jpg").arg(outputVideoPath, QString::number(timestampVector[i]));

        // Save the frame
        bool success = cv::imwrite(filename.toStdString(), framesWithObjects[i]);

        // Calculate and emit loading progress.
        int progress = static_cast<int>((savedFrames / static_cast<double>(totalFrames)) * 100);
        emit loadingProgress(progress);

        if (!success) 
        {
            // Handle error: Failed to save frame
        }
    }
}

void MotionDetectionThread::detectMotion(std::string stdVideoPath, bool imgsaveFlag, QString outputVideoPath, bool timestampFlag, double sensitivity, int frameskipNum, bool fbfFlag)
{
    emit currentStatus("Ανίχνευση κίνησης...");
    cv::VideoCapture videoCap(stdVideoPath);
    if (!videoCap.isOpened())
    {
        QMessageBox::critical(nullptr, tr("Σφάλμα"), tr("Άποτυχία φόρτωσης του βίντεο."));
        return;
    }

    else
    {
        int totalFrames = videoCap.get(cv::CAP_PROP_FRAME_COUNT);
        int frameRate = videoCap.get(cv::CAP_PROP_FPS);
        int processedFrames = 0;
        cv::Mat frame;
        while (videoCap.read(frame))
        {
            processedFrames++;
            std::vector<int> classIds;
            std::vector<float> scores;
            std::vector<cv::Rect> boxes;

            MotionDetectionThread::detectObjects(frame, classIds, scores, boxes, classes, sensitivity);

            if (!classIds.empty() && (imgsaveFlag == true || fbfFlag == true))
            {
                // Writing important frames to a vector.
                framesWithObjects.push_back(frame.clone());
            }
            if (!classIds.empty() && (timestampFlag == true || fbfFlag == true))
            {
                // Getting the timestamps.
                double currentTime = processedFrames / frameRate;
                timestampVector.push_back(currentTime);

            }
            // Calculate and emit loading progress.
            int progress = static_cast<int>((processedFrames / static_cast<double>(totalFrames)) * 100);
            emit loadingProgress(progress);
        }
        if (imgsaveFlag == true)
        {
            emit resetProgress();
            MotionDetectionThread::writeToVideo(framesWithObjects, videoCap, outputVideoPath);
        }
        if (timestampFlag == true)
        {
            emit resetProgress();
            MotionDetectionThread::writeToTxt(detectedClasses, timestampVector, outputVideoPath);
        }
        if (fbfFlag == true)
        {
            emit resetProgress();
            MotionDetectionThread::writeToImage(framesWithObjects, timestampVector, outputVideoPath);
        }
    }
}

int MotionDetectionThread::detectMotionDNN(QString videoPath, QString namesFilePath,
    QString weightsFilePath, QString configFilePath, QString outputVideoPath, bool imgsaveFlag,
    bool timestampFlag, bool fbfFlag, double sensitivity, int frameskipNum)
{
    std::string stdNFP = namesFilePath.toStdString();
    std::string stdWFP = weightsFilePath.toStdString();
    std::string stdCFP = configFilePath.toStdString();
    std::string stdVideoPath = videoPath.toStdString();

    MotionDetectionThread::initializeClasses(stdNFP);
    MotionDetectionThread::initializeDNN(stdWFP, stdCFP);
    MotionDetectionThread::detectMotion(stdVideoPath, imgsaveFlag, outputVideoPath,
        timestampFlag, sensitivity, frameskipNum, fbfFlag);

    return 0;
}

void MotionDetectionThread::threadQuit()
{
    emit threadQuitRequested();
    quit();
}

void MotionDetectionThread::run()
{
   returnCode = MotionDetectionThread::detectMotionDNN(m_videoPath, m_namesFilePath, m_weightsFilePath,
        m_configFilePath, m_outputVideoPath, m_imgsaveFlag, m_timestampFlag, m_fbfFlag, m_sensitivity, m_frameskipNum);
   if (returnCode == 0)
   {
       emit threadQuitRequested();
       quit();
   }
}