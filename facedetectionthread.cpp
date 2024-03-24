#include "facedetectionthread.h"
#include "facedetection.h"

FaceDetectionThread::FaceDetectionThread(const QString& videoPath, bool saveToVideoFlag,
	bool saveToImageFlag, bool saveToTxtFlag, double scaleFactor, double confidenceThreshold, QObject* parent) : QThread(parent),
	videoPath(videoPath), saveToVideoFlag(saveToVideoFlag), saveToImageFlag(saveToImageFlag),
	saveToTxtFlag(saveToTxtFlag), scaleFactor(scaleFactor), confidenceThreshold(confidenceThreshold)
{
	// Constructor does not need implementation currently.
}

FaceDetectionThread::~FaceDetectionThread()
{
	// Destructor may not need implementation.
}

void FaceDetectionThread::run()
{
	returnCode = FaceDetectionThread::detectFacesDNN(videoPath,
		saveToVideoFlag,
		saveToImageFlag,
		saveToTxtFlag);

	if (returnCode == 0)
	{
		emit threadQuitRequested();
		quit();
	}
}

void FaceDetectionThread::threadQuit()
{
	emit threadQuitRequested();
	quit();
}

int FaceDetectionThread::detectFacesDNN(QString videoPath, bool saveToVideoFlag, bool saveToImageFlag, bool saveToTxtFlag)
{
	emit resetProgress();
	emit currentStatus("Προετοιμασία αλγορίθμου...");
	FaceDetectionThread::getDNNFiles();
	int returnCodeDNN = FaceDetectionThread::initializeDNN();
	if (returnCodeDNN == 0)
	{
		FaceDetectionThread::getVideoDimensions();
		FaceDetectionThread::detectFaces(videoPath, saveToVideoFlag, saveToImageFlag, saveToTxtFlag);
		return 0;
	}
	else if (returnCodeDNN == 1)
	{
		QMessageBox::critical(nullptr, tr("Σφάλμα"), tr("Άποτυχία φόρτωσης του νευρωνικού δικτύου."));
		return 1;
	}
	return 0;
}

void FaceDetectionThread::getDNNFiles()
{
	QString placeholderString;
	QSettings settings("config.ini", QSettings::IniFormat);
	placeholderString = settings.value("Caffe_Preferences/Config_Path").toString();
	caffePrototxtPath = placeholderString.toStdString();
	placeholderString = settings.value("Caffe_Preferences/Model_Path").toString();
	caffeModelPath = placeholderString.toStdString();
	return;
}

int FaceDetectionThread::initializeDNN()
{
	DNN = cv::dnn::readNetFromCaffe(caffePrototxtPath, caffeModelPath);
	if (DNN.empty())
	{
		return 1;
	}
	return 0;
}

void FaceDetectionThread::getVideoDimensions()
{
	std::string videoPathString = videoPath.toStdString();
	cv::VideoCapture videoCapture(videoPathString);
	if (!videoCapture.isOpened()) 
	{
		QMessageBox::critical(nullptr, tr("Σφάλμα"), tr("Άποτυχία φόρτωσης του βίντεο."));
		return;
	}
	videoWidth = videoCapture.get(cv::CAP_PROP_FRAME_WIDTH);
	videoHeight = videoCapture.get(cv::CAP_PROP_FRAME_HEIGHT);
	videoCapture.release();
	return;
}

std::vector<cv::Rect> FaceDetectionThread::detectFaceRectangles(const cv::Mat& frame)
{
	meanValues = { 104., 177.0, 123.0 };
	// Transforming the input image into a data blob. 
	// The function cv::dnn::blobFromImage takes care of rescaling the image to 
	// the correct input size for the network. It also subtracts the mean value 
	// in each color channel.
	cv::Mat inputBlob = cv::dnn::blobFromImage(frame, scaleFactor,
		cv::Size(videoWidth, videoHeight), meanValues, false, false);

	// Forwarding the data through the network. Result is saved in the 
	// variable detectionMatrix.
	DNN.setInput(inputBlob, "data");
	cv::Mat detection = DNN.forward("detection_out");
	cv::Mat detectionMatrix(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

	// Iterating through the rows of the matrix. 
	// Each row contains one detection. While iterating,  check if the confidence 
	// value exceeds the threshold. If so, construct a cv::Rect and save it in 
	// the result vector faces.
	std::vector<cv::Rect> faces;

	for (int i = 0; i < detectionMatrix.rows; i++) 
	{
		float confidence = detectionMatrix.at<float>(i, 2);

		if (confidence < confidenceThreshold) 
		{
			continue;
		}
		int x_left_bottom = static_cast<int>(detectionMatrix.at<float>(i, 3) * frame.cols);

		int y_left_bottom = static_cast<int>(detectionMatrix.at<float>(i, 4) * frame.rows);

		int x_right_top = static_cast<int>(detectionMatrix.at<float>(i, 5) * frame.cols);

		int y_right_top = static_cast<int>(detectionMatrix.at<float>(i, 6) * frame.rows);

		faces.emplace_back(x_left_bottom, y_left_bottom, 
			(x_right_top - x_left_bottom), (y_right_top - y_left_bottom));
	}
	return faces;
}

void FaceDetectionThread::detectFaces(QString videoPath, bool saveToVideoFlag, bool saveToImageFlag, bool saveToTxtFlag)
{
	emit currentStatus("Εντοπισμός προσώπων...");
	int processedFrames = 0;
	std::string videoPathString = videoPath.toStdString();
	cv::VideoCapture videoCapture(videoPathString);
	int totalFrames = videoCapture.get(cv::CAP_PROP_FRAME_COUNT);
	std::vector<cv::Mat> framesWithFaces;
	std::vector<std::vector<cv::Rect>> detectedRectangles;
	if (!videoCapture.isOpened())
	{
		QMessageBox::critical(nullptr, tr("Σφάλμα"), tr("Άποτυχία φόρτωσης του βίντεο."));
		return;
	}
	cv::Mat frame;
	while (true)
	{
		videoCapture >> frame;
		processedFrames++;
		if (frame.empty())
		{
			break;
		}

		auto rectangles = detectFaceRectangles(frame);
		cv::Scalar color(0, 105, 205);
		int frameThickness = 4;
		for (const auto& r : rectangles)
		{
			cv::rectangle(frame, r, color, frameThickness);

		}
		if (!rectangles.empty())
		{
			framesWithFaces.push_back(frame.clone());
			if (saveToImageFlag == true)
			{
				detectedRectangles.push_back(rectangles);
			}
		}
		int progress = static_cast<int>((processedFrames / static_cast<double>(totalFrames)) * 100);
		emit loadingProgress(progress);
	}
	videoCapture.release();
	if (saveToVideoFlag == true)
	{
		emit resetProgress();
		FaceDetectionThread::saveToVideo(framesWithFaces);
	}
	if (saveToImageFlag == true)
	{
		emit resetProgress();
		FaceDetectionThread::saveToImage(framesWithFaces, detectedRectangles);
	}
	return;
}

void FaceDetectionThread::saveToVideo(std::vector<cv::Mat> framesWithFaces)
{
	emit currentStatus("Δημιουργία βίντεο...");
	QSettings settings("config.ini", QSettings::IniFormat);
	QString outputVideoPath = settings.value("Save_Preferences/Results_Path").toString();
	std::string stdOVP = outputVideoPath.toStdString() + "/result.mp4";

	cv::VideoWriter videoWriter(stdOVP, cv::VideoWriter::fourcc('H', '2', '6', '4'), 30, cv::Size(videoWidth, videoHeight));
	int processedFrames = 0;
	int totalFramesWithObjects = static_cast<int>(framesWithFaces.size());

	// Write frames with detected objects to the output video.
	for (const cv::Mat& outputFrame : framesWithFaces)
	{
		videoWriter.write(outputFrame);
		processedFrames++;
		int progress = static_cast<int>((processedFrames / static_cast<double>(totalFramesWithObjects)) * 100);
		emit loadingProgress(progress);
	}

	// Release the video writer.
	videoWriter.release();
	qDebug() << stdOVP;
	return;
}

void FaceDetectionThread::saveToImage(std::vector<cv::Mat> framesWithFaces, std::vector<std::vector<cv::Rect>> detectedRectangles)
{
	emit currentStatus("Αποκοπή προσώπων απο το βίντεο...");
	std::vector<cv::Mat> croppedFaces;
	for (size_t i = 0; i < framesWithFaces.size(); ++i)
	{
		const cv::Mat& frame = framesWithFaces[i];
		const std::vector<cv::Rect>& rectangles = detectedRectangles[i];

		// Iterate through the rectangles stored within the frame
		for (const auto& rect : rectangles) 
		{
			// Create a region of interest (ROI) using the rectangle
			cv::Rect roi(rect.x, rect.y, rect.width, rect.height);

			// Crop the face from the frame using the ROI
			cv::Mat croppedFace = frame(roi).clone(); // Ensure to clone to avoid modifying the original frame

			// Store the cropped face in the vector
			croppedFaces.push_back(croppedFace);
		}
	}
}