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
		bool saveToTxtFlag);
	void getDNNFiles();
	void getVideoDimensions();
	int initializeDNN();
	std::vector<cv::Rect> detectFaceRectangles(const cv::Mat& frame);
	void saveToVideo(std::vector<cv::Mat> framesWithFaces);
	void saveToImage(std::vector<cv::Mat> framesWithFaces, std::vector<std::vector<cv::Rect>> detectedRectangles);
	void detectFaces(QString videoPath, bool saveToVideoFlag, bool saveToImageFlag, bool saveToTxtFlag);

private:
	const QString videoPath;
	std::string caffePrototxtPath;
	std::string caffeModelPath;
	cv::dnn::Net DNN;
	int videoWidth;
	int videoHeight;
	double scaleFactor;
	cv::Scalar meanValues;
	double confidenceThreshold;
	const bool saveToVideoFlag;
	const bool saveToImageFlag;
	const bool saveToTxtFlag;
	int returnCode;
};

#endif //FACEDETECTIONTHREAD_H