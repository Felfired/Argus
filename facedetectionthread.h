#ifndef FACEDETECTIONTHREAD_H
#define FACEDETECTIONTHREAD_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <QThread>
#include <QObject>
#include <QString>
#include <QMessageBox>

class FaceDetectionThread : public QThread
{
	Q_OBJECT

public:
	FaceDetectionThread(const QString& videoPath, 
		bool saveToVideoFlag, 
		bool saveToImageFlag,
		bool saveToTxtFlag,
		double scaleFactor,
		double ConfidenceThreshold,
		double yConfidenceThreshold,
		double nmsThreshold,
		int detectionCount,
		const QString& selectedModel,
		QObject* parent = nullptr);
	~FaceDetectionThread();
	void threadQuit();
	
signals:
	void loadingProgress(int progress);
	void currentStatus(QString status);
	void resetProgress();
	void threadQuitRequested();

protected:
	void run() override;

private slots:
	int detectFacesDNN(QString videoPath,
		bool saveToVideoFlag,
		bool saveToImageFlag,
		bool saveToTxtFlag,
		QString selectedModel);
	void getDNNFiles();
	void getVideoDimensions();
	int initializeDNNCaffe();
	int initializeDNNYunet();
	std::vector<cv::Rect> detectFaceRectanglesCaffe(const cv::Mat& frame);
	void saveToVideo(std::vector<cv::Mat> framesWithFaces);
	void saveToImage(std::vector<cv::Mat> framesWithFaces, std::vector<std::vector<cv::Rect>> detectedRectangles, std::vector<double> timestampVector);
	void detectFacesCaffe(QString videoPath, bool saveToVideoFlag, bool saveToImageFlag, bool saveToTxtFlag);
	void createImageFiles(std::vector<cv::Mat> croppedFaces, std::vector<double> timestampVector, std::vector<std::pair<int, int>> dictionary);
	cv::Mat detectFaceRectanglesYunet(const cv::Mat frame);
	void detectFacesYunet();
	cv::Mat visualizeDetectionsYunet(const cv::Mat& frame, const cv::Mat& frameWithFaces, int frameNumber);
	void extractImagesYunet(cv::Rect roi, const cv::Mat& frame, int frameNumber, int roiNumber);
	cv::Rect expandROI(const cv::Rect& roi, float expansionFactor);

private:
	const QString videoPath;
	std::string caffePrototxtPath;
	std::string caffeModelPath;
	std::string yunetModelPath;
	std::string saveLocationString;
	cv::dnn::Net DNN;
	cv::Ptr<cv::FaceDetectorYN> yunetDNN;
	int videoWidth;
	int videoHeight;
	double scaleFactor;
	cv::Scalar meanValues;
	double confidenceThreshold;
	const bool saveToVideoFlag;
	const bool saveToImageFlag;
	const bool saveToTxtFlag;
	double yConfidenceThreshold;
	double nmsThreshold;
	int detectionCount;
	const QString selectedModel;
	int returnCode;
};

#endif //FACEDETECTIONTHREAD_H