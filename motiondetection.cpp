#include "motiondetection.h"

MotionDetection::MotionDetection(QObject *parent)
    : QObject(parent)
{
    // Do nothing.
}

MotionDetection::~MotionDetection()
{

}

void MotionDetection::initializeLoadingDialog()
{
    loadDialog = new MotionDetectionLoad();
    loadDialog->show();
    loadDialog->activateWindow();
}

void MotionDetection::start(MotionDetectionDialog *initDialog, QString videoPath, QString namesFilePath,
    QString weightsFilePath, QString configFilePath, QString outputVideoPath, 
    bool imgsaveFlag, bool timestampFlag, bool fbfFlag, double sensitivity, int frameskipNum)
{
    MotionDetectionThread* thread = new MotionDetectionThread(videoPath, namesFilePath,
        weightsFilePath, configFilePath,
        outputVideoPath, imgsaveFlag,
        timestampFlag, fbfFlag, sensitivity, frameskipNum);
    MotionDetection::initializeLoadingDialog();
    connect(thread, &MotionDetectionThread::started, initDialog, &MotionDetectionDialog::disableButtons);
    connect(loadDialog, &MotionDetectionLoad::cancelClicked, thread, &MotionDetectionThread::threadQuit);
    connect(thread, &MotionDetectionThread::loadingProgress, loadDialog, &MotionDetectionLoad::updateProgress);
    connect(thread, &MotionDetectionThread::currentStatus, loadDialog, &MotionDetectionLoad::updateStatus);
    connect(thread, &MotionDetectionThread::resetProgress, loadDialog, &MotionDetectionLoad::resetProgress);
    connect(thread, &MotionDetectionThread::threadQuitRequested, loadDialog, &MotionDetectionLoad::onCompletion);
    connect(thread, &MotionDetectionThread::threadQuitRequested, initDialog, &MotionDetectionDialog::enableButtons);
    connect(thread, &MotionDetectionThread::finished, thread, &MotionDetectionThread::deleteLater);
    thread->start();
}

