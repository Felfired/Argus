#include "facedetection.h"

FaceDetection::FaceDetection(QObject* parent)
    : QObject(parent)
{
    // Do nothing.
}

FaceDetection::~FaceDetection()
{

}

void FaceDetection::initializeLoadingDialog()
{
    loadDialog = new MotionDetectionLoad();
    loadDialog->setWindowIcon(QIcon(":argus/res/app_icons/detection.png"));
    loadDialog->setWindowTitle("Εντοπισμός Προσώπων");
    loadDialog->show();
    loadDialog->activateWindow();
}

void FaceDetection::start(FaceDetectionDialog* initDialog, QString videoPath,
	bool saveToVideoFlag, bool saveToImageFlag, double scaleFactor, 
    double confidenceThreshold, double yConfidenceThreshold, double nmsThreshold, int detectionCount,
    QString selectedModel)
{
    FaceDetectionThread* thread = new FaceDetectionThread(videoPath,
        saveToVideoFlag, saveToImageFlag,  scaleFactor, confidenceThreshold, yConfidenceThreshold,
        nmsThreshold, detectionCount, selectedModel);
    FaceDetection::initializeLoadingDialog();
    connect(thread, &FaceDetectionThread::started, initDialog, &FaceDetectionDialog::disableButtons);
    connect(loadDialog, &MotionDetectionLoad::cancelClicked, thread, &FaceDetectionThread::threadQuit);
    connect(thread, &FaceDetectionThread::loadingProgress, loadDialog, &MotionDetectionLoad::updateProgress);
    connect(thread, &FaceDetectionThread::currentStatus, loadDialog, &MotionDetectionLoad::updateStatus);
    connect(thread, &FaceDetectionThread::resetProgress, loadDialog, &MotionDetectionLoad::resetProgress);
    connect(thread, &FaceDetectionThread::threadQuitRequested, loadDialog, &MotionDetectionLoad::onCompletion);
    connect(thread, &FaceDetectionThread::threadQuitRequested, initDialog, &FaceDetectionDialog::enableButtons);
    connect(thread, &FaceDetectionThread::finished, thread, &FaceDetectionThread::deleteLater);
    thread->start();
}