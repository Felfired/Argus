#include "facedetectionthread.h"
#include "facedetection.h"

FaceDetectionThread::FaceDetectionThread(const QString& videoPath, bool saveToVideoFlag,
	bool saveToImageFlag, double scaleFactor, double confidenceThreshold, 
	double yConfidenceThreshold, double nmsThreshold, int detectionCount, const QString& selectedModel, QObject* parent) : QThread(parent),
	videoPath(videoPath), saveToVideoFlag(saveToVideoFlag), saveToImageFlag(saveToImageFlag),
	scaleFactor(scaleFactor), confidenceThreshold(confidenceThreshold),
	yConfidenceThreshold(yConfidenceThreshold), nmsThreshold(nmsThreshold), detectionCount(detectionCount),
	selectedModel(selectedModel)
{
	QSettings settings("config.ini", QSettings::IniFormat);
	QString saveLocation = settings.value("Save_Preferences/Current_Path").toString();
	saveLocationString = saveLocation.toStdString();
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
		selectedModel);

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

int FaceDetectionThread::detectFacesDNN(QString videoPath, bool saveToVideoFlag, bool saveToImageFlag, QString selectedModel)
{
	emit resetProgress();
	emit currentStatus("Προετοιμασία αλγορίθμου...");
	int returnCodeDNN;
	if (selectedModel == "caffe")
	{
		FaceDetectionThread::getDNNFiles();
		returnCodeDNN = FaceDetectionThread::initializeDNNCaffe();
		if (returnCodeDNN == 0)
		{
			FaceDetectionThread::getVideoDimensions();
			FaceDetectionThread::detectFacesCaffe(videoPath, saveToVideoFlag, saveToImageFlag);
			return 0;
		}
		else if (returnCodeDNN == 1)
		{
			QMessageBox::critical(nullptr, tr("Σφάλμα"), tr("Άποτυχία φόρτωσης του νευρωνικού δικτύου."));
			return 1;
		}
	}
	else if (selectedModel == "yunet")
	{
		FaceDetectionThread::getDNNFiles();
		FaceDetectionThread::getVideoDimensions();
		returnCodeDNN = FaceDetectionThread::initializeDNNYunet();
		if (returnCodeDNN == 0)
		{
			FaceDetectionThread::detectFacesYunet();
			return 0;
		}
		else if (returnCodeDNN == 1)
		{
			QMessageBox::critical(nullptr, tr("Σφάλμα"), tr("Άποτυχία φόρτωσης του νευρωνικού δικτύου."));
			return 1;
		}
	}
	return 0;
}

void FaceDetectionThread::getDNNFiles()
{
	QString placeholderString;
	QSettings settings("config.ini", QSettings::IniFormat);
	if (selectedModel == "caffe")
	{
		placeholderString = settings.value("Caffe_Preferences/Config_Path").toString();
		caffePrototxtPath = placeholderString.toStdString();
		placeholderString = settings.value("Caffe_Preferences/Model_Path").toString();
		caffeModelPath = placeholderString.toStdString();
	}
	else if (selectedModel == "yunet")
	{
		placeholderString = settings.value("Yunet_Preferences/Model_Path").toString();
		yunetModelPath = placeholderString.toStdString();
	}
	return;
}

int FaceDetectionThread::initializeDNNCaffe()
{
	DNN = cv::dnn::readNetFromCaffe(caffePrototxtPath, caffeModelPath);
	if (DNN.empty())
	{
		return 1;
	}
	return 0;
}

int FaceDetectionThread::initializeDNNYunet()
{
	cv::Size inputSize(videoWidth, videoHeight);
	yunetDNN = cv::FaceDetectorYN::create(yunetModelPath, 
		"", 
		inputSize, 
		yConfidenceThreshold, 
		nmsThreshold, 
		detectionCount, 
		cv::dnn::Backend::DNN_BACKEND_OPENCV, 
		cv::dnn::DNN_TARGET_CPU);
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

std::vector<cv::Rect> FaceDetectionThread::detectFaceRectanglesCaffe(const cv::Mat& frame)
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

cv::Mat FaceDetectionThread::detectFaceRectanglesYunet(const cv::Mat frame)
{
	cv::Mat res;
	yunetDNN->detect(frame, res);
	return res;
}

cv::Mat FaceDetectionThread::visualizeDetectionsYunet(const cv::Mat& frame, 
													  const cv::Mat& frameWithFaces, 
													  int frameNumber)
{
	static cv::Scalar boxColor{ 0, 255, 0 };
	static cv::Scalar textColor{ 0, 255, 0 };
	auto outputImage = frame.clone();
	int frameCounter = 0;

	for (int i = 0; i < frameWithFaces.rows; ++i)
	{
		// Draw bounding boxes.
		int x1 = static_cast<int>(frameWithFaces.at<float>(i, 0));
		int y1 = static_cast<int>(frameWithFaces.at<float>(i, 1));
		int w = static_cast<int>(frameWithFaces.at<float>(i, 2));
		int h = static_cast<int>(frameWithFaces.at<float>(i, 3));
		cv::rectangle(outputImage, cv::Rect(x1, y1, w, h), boxColor, 2);

		// Confidence as text.
		float conf = frameWithFaces.at<float>(i, 14);
		cv::putText(outputImage, cv::format("%.4f", conf), cv::Point(x1, y1 + 12), cv::FONT_HERSHEY_DUPLEX, 0.5, textColor);

		if (saveToImageFlag == true && frameCounter % 3 == 0)
		{
			FaceDetectionThread::extractImagesYunet(cv::Rect(x1, y1, w, h), frame, frameNumber, i);
		}
		frameCounter++;
	}
	return outputImage;
}

void FaceDetectionThread::detectFacesYunet()
{
	emit currentStatus("Εντοπισμός προσώπων...");
	int processedFrames = 0;
	std::string videoPathString = videoPath.toStdString();
	cv::VideoCapture videoCapture(videoPathString);
	int totalFrames = videoCapture.get(cv::CAP_PROP_FRAME_COUNT);
	std::vector<cv::Mat> framesWithFaces;
	std::vector<double> timestampVector;

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
		cv::Mat frameWithFaces = FaceDetectionThread::detectFaceRectanglesYunet(frame);
		frameWithFaces = FaceDetectionThread::visualizeDetectionsYunet(frame, frameWithFaces, processedFrames);
		framesWithFaces.push_back(frameWithFaces);

		int progress = static_cast<int>((processedFrames / static_cast<double>(totalFrames)) * 100);
		emit loadingProgress(progress);
	}
	videoCapture.release();
	if (saveToVideoFlag == true)
	{
		emit resetProgress();
		FaceDetectionThread::saveToVideo(framesWithFaces);
	}
}

void FaceDetectionThread::detectFacesCaffe(QString videoPath, bool saveToVideoFlag, bool saveToImageFlag)
{
	emit currentStatus("Εντοπισμός προσώπων...");

	int processedFrames = 0;
	std::string videoPathString = videoPath.toStdString();
	cv::VideoCapture videoCapture(videoPathString);
	int totalFrames = videoCapture.get(cv::CAP_PROP_FRAME_COUNT);
	int framesPerSecond = videoCapture.get(cv::CAP_PROP_FPS);
	std::vector<cv::Mat> framesWithFaces;
	std::vector<std::vector<cv::Rect>> detectedRectangles;
	std::vector<double> timestampVector;

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

		auto rectangles = detectFaceRectanglesCaffe(frame);
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
				double currentTime = processedFrames / framesPerSecond;
				timestampVector.push_back(currentTime);
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
		if (selectedModel == "caffe")
		{
			FaceDetectionThread::saveToImage(framesWithFaces, detectedRectangles, timestampVector);
		}
	}
	return;
}

void FaceDetectionThread::saveToVideo(std::vector<cv::Mat> framesWithFaces)
{
	emit currentStatus("Δημιουργία βίντεο...");
	QSettings settings("config.ini", QSettings::IniFormat);
	QString outputVideoPath = settings.value("Save_Preferences/Current_Path").toString();
	std::string stdOVP = outputVideoPath.toStdString() + "/results_face_detection.mp4";

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

void FaceDetectionThread::saveToImage(std::vector<cv::Mat> framesWithFaces, std::vector<std::vector<cv::Rect>> detectedRectangles, std::vector<double> timestampVector)
{
	emit currentStatus("Αποκοπή προσώπων απο το βίντεο...");
	std::vector<cv::Mat> croppedFaces;
	std::vector<std::pair<int, int>> dictionary;
	for (size_t i = 0; i < framesWithFaces.size(); i+=3)
	{
		const cv::Mat& frame = framesWithFaces[i];
		const std::vector<cv::Rect>& rectangles = detectedRectangles[i];
		int counter = 0;
		// Iterate through the rectangles stored within the frame
		for (const auto& rect : rectangles) 
		{
			// Create a region of interest (ROI) using the rectangle
			cv::Rect roi(rect.x, rect.y, rect.width, rect.height);

			// Crop the face from the frame using the ROI
			cv::Mat croppedFace = frame(roi).clone(); // Ensure to clone to avoid modifying the original frame

			// Store the cropped face in the vector
			croppedFaces.push_back(croppedFace);
			dictionary.push_back(std::make_pair(i + 1, counter + 1));
			++counter;
		}
	}
	FaceDetectionThread::createImageFiles(croppedFaces, timestampVector, dictionary);
}

void FaceDetectionThread::createImageFiles(std::vector<cv::Mat> croppedFaces, std::vector<double> timestampVector, std::vector<std::pair<int, int>> dictionary)
{
	QSettings settings("config.ini", QSettings::IniFormat);
	QString saveLocation = settings.value("Save_Preferences/Current_Path").toString();
	std::string saveLocationString = saveLocation.toStdString();
	for (size_t i = 0; i < croppedFaces.size(); ++i)
	{
		// Get the frame number and rectangle number from the dictionary
		int frameNumber = dictionary[i].first;
		int rectangleNumber = dictionary[i].second;

		// Generate the filename based on frame number, rectangle number, and timestamp
		std::string filename = saveLocationString + "/" + std::to_string(frameNumber) + "_" + std::to_string(rectangleNumber) + "_" + std::to_string(timestampVector[frameNumber - 1]) + ".jpg";

		// Save the cropped face as a JPEG file
		cv::imwrite(filename, croppedFaces[i]);
	}
}

void FaceDetectionThread::extractImagesYunet(cv::Rect roi, const cv::Mat& frame, int frameNumber, int roiNumber)
{
	cv::Rect expandedROI = FaceDetectionThread::expandROI(roi, 0.2);
	cv::Mat faceROI = frame(expandedROI);
	std::string filename = saveLocationString + "/face_" + std::to_string(frameNumber) + "_" + std::to_string(frameNumber) + ".jpg";
	cv::imwrite(filename, faceROI);
}

cv::Rect FaceDetectionThread::expandROI(const cv::Rect& roi, float expansionFactor)
{
	// Calculate expansion amounts.
	int expandX = static_cast<int>(roi.width * expansionFactor);
	int expandY = static_cast<int>(roi.height * expansionFactor);

	// Calculate expanded ROI coordinates.
	int newX = std::max(0, roi.x - expandX);
	int newY = std::max(0, roi.y - expandY);
	int newWidth = roi.width + 2 * expandX;
	int newHeight = roi.height + 2 * expandY;

	// Ensure the expanded ROI stays within the bounds of maxWidth and maxHeight.
	newWidth = std::min(newWidth, videoWidth - newX);
	newHeight = std::min(newHeight, videoHeight - newY);

	return cv::Rect(newX, newY, newWidth, newHeight);
}