#include "facerecognition.h"
#include "facerecognitionthread.h"

FaceRecognition::FaceRecognition(QObject* parent)
    : QObject(parent)
{
    // Do nothing.
}

FaceRecognition::~FaceRecognition()
{

}

void FaceRecognition::start(FaceRecognitionDialog* initDialog, QString folderPath, QString distanceCalculationMode)
{
    FaceRecognitionThread* thread = new FaceRecognitionThread(folderPath, distanceCalculationMode);
    //connect(thread, &FaceRecognitionThread::started, initDialog, &FaceRecognitionDialog::disableButtons);
    //connect(loadDialog, &MotionDetectionLoad::cancelClicked, thread, &FaceDetectionThread::threadQuit);
    //connect(thread, &FaceDetectionThread::loadingProgress, loadDialog, &MotionDetectionLoad::updateProgress);
    //connect(thread, &FaceDetectionThread::currentStatus, loadDialog, &MotionDetectionLoad::updateStatus);
    //connect(thread, &FaceDetectionThread::resetProgress, loadDialog, &MotionDetectionLoad::resetProgress);
    //connect(thread, &FaceDetectionThread::threadQuitRequested, loadDialog, &MotionDetectionLoad::onCompletion);
    //connect(thread, &FaceDetectionThread::threadQuitRequested, initDialog, &FaceDetectionDialog::enableButtons);
    connect(thread, &FaceRecognitionThread::finished, thread, &FaceRecognitionThread::deleteLater);
    thread->start();
}