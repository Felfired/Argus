#ifndef MOTIONDETECTIONTHREAD_H
#define MOTIONDETECTIONTHREAD_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QDebug>
#include <QThread>
#include <QObject>


class MotionDetectionThread : public QThread
{
	Q_OBJECT

public:
    MotionDetectionThread(const QString& videoPath, const QString& namesFilePath,
        const QString& weightsFilePath, const QString& configFilePath,
        const QString& outputVideoPath, bool imgsaveFlag, bool timestampFlag, bool fbfFlag,
        double sensitivity, int frameskipNum,
        QObject* parent = nullptr);
    void threadQuit();

signals:
    void loadingProgress(int progress);
    void currentStatus(QString status);
    void resetProgress();
    void threadQuitRequested();

protected:
    void run() override;

private slots:
    void initializeDNN(const std::string& weightsFilePath, const std::string& configFilePath);
    void initializeClasses(const std::string& namesFilePath);
    int getClassFileSize(const std::string& namesFilePath);
    void detectMotion(std::string videoPath, bool imgsaveFlag, QString outputVideoPath, bool timestampFlag, double sensitivity, int frameskipNum, bool fbfFlag);
    void detectObjects(cv::Mat& frame, std::vector<int>& classIds, std::vector<float>& scores, std::vector<cv::Rect>& boxes, const std::vector<std::string>& classes, double sensitivity);
    void writeToVideo(std::vector<cv::Mat> framesWithObjects, cv::VideoCapture videoCap, QString outputVideoPath);
    void writeToTxt(std::vector<std::string> detectedClasses, std::vector<double> timestampVector, QString outputVideoPath);
    void writeToImage(std::vector<cv::Mat> framesWithObjects, std::vector<double> timestampVector, QString outputVideoPath);
    int detectMotionDNN(QString videoPath, 
        QString namesFilePath, 
        QString weightsFilePath, 
        QString configFilePath, 
        QString outputVideoPath, 
        bool imgsaveFlag,
        bool timestampFlag,
        bool fbfFlag,
        double sensitivity,
        int frameskipNum);

private:
    QString m_videoPath;
    QString m_namesFilePath;
    QString m_weightsFilePath;
    QString m_configFilePath;
    QString m_outputVideoPath;
    bool m_imgsaveFlag;
    bool m_timestampFlag;
    bool m_fbfFlag;
    double m_sensitivity;
    int m_frameskipNum;
    cv::dnn::Net DNN;
    cv::dnn::DetectionModel detectionModel;
    std::vector<std::string> classes;
    std::vector<std::string> detectedClasses;
    std::vector<cv::Mat> framesWithObjects;
    std::vector<double> timestampVector;

    int returnCode;
};

#endif // MOTIONDETECTIONTHREAD_H
