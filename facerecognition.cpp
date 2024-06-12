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

void FaceRecognition::start(FaceRecognitionDialog* initDialog, QString folderPath, QString distanceCalculationMode, bool saveToTxtFlag)
{
    FaceRecognitionThread* thread = new FaceRecognitionThread(folderPath, distanceCalculationMode, saveToTxtFlag);
    connect(initDialog, &FaceRecognitionDialog::stopButtonClicked, thread, &FaceRecognitionThread::threadQuit);
    connect(thread, &FaceRecognitionThread::setLoadingProgress, initDialog, &FaceRecognitionDialog::setLoadingProgress);
    connect(thread, &FaceRecognitionThread::onThreadQuitRequested, initDialog, &FaceRecognitionDialog::onCompletion);
    connect(thread, &FaceRecognitionThread::postRecognitionID, initDialog, &FaceRecognitionDialog::addRecognitionToTable);
    connect(thread, &FaceRecognitionThread::finished, thread, &FaceRecognitionThread::deleteLater);
    thread->start();
}