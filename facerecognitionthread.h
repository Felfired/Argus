#ifndef FACERECOGNITIONTHREAD_H
#define FACERECOGNITIONTHREAD_H

#include <opencv2/opencv.hpp>
#include <QThread>
#include <QObject>
#include <QMessageBox>
#include <QSettings>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class FaceRecognitionThread : public QThread
{
	Q_OBJECT

public:
	FaceRecognitionThread(const QString& folderPath,
						  const QString& distanceCalculationMode,
						  QObject* parent = nullptr);
	~FaceRecognitionThread();
	void threadQuit();

signals:
	void setLoadingProgress(int progress);
	void resetLoadingProgress();
	void onThreadQuitRequested();
	void postRecognitionID(std::string idFound);
	void postRecognitionPath(std::string path);

protected:
	void run() override;

private slots:
	int initializeRecognition();
	int initializeSFaceDNN();
	cv::Mat imageInference(cv::Mat inputImage);
	int matchImages(cv::Mat unknownFeatures, cv::Mat referenceFeatures);
	void recognitionScan();
	QStringList getImagePathsFromDirectory();
	std::vector<std::vector<std::string>> createIndexVector();

private:
	const QString distanceCalculationMode;
	const QString folderPath;
	QString indexPath;
	QString modelPath;
	int returnCode;
	std::vector<std::string> duplicateRecognitions;
	cv::Ptr<cv::FaceRecognizerSF> sfaceDNN;
	double thresholdCosine;
	double thresholdEuclidean;
};

#endif //FACERECOGNITIONTHREAD_H
