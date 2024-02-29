#ifndef MOTIONDETECTION_H
#define MOTIONDETECTION_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <QString>
#include <QObject>
#include <QStringList>
#include <QMessageBox>
#include <QProgressBar>
#include <QDebug>
#include "motiondetectionload.h"
#include "motiondetectionthread.h"
#include "motiondetectiondialog.h"

class MotionDetection : public QObject
{
    Q_OBJECT

public:
    MotionDetection(QObject* parent = nullptr);
    ~MotionDetection();
    void start(MotionDetectionDialog *initDialog,
        QString videoPath, 
        QString namesFilePath, 
        QString weightsFilePath, 
        QString configFilePath, 
        QString outputVideoPath, 
        bool imgsaveFlag,
        bool timestampFlag,
        bool fbfFlag,
        double sensitivity,
        int frameskipNum);
    void initializeLoadingDialog();

private:
    QString namesFilePath;
    QString weightsFilePath;
    QString configFilePath;
    MotionDetectionLoad* loadDialog;
};

#endif // MOTIONDETECTION_H
