#ifndef FACEDETECTION_H
#define FACEDETECTION_H

#include <QObject>
#include "motiondetectionload.h"
#include "facedetectiondialog.h"
#include "facedetectionthread.h"

class FaceDetection : public QObject
{
	Q_OBJECT

public:
	FaceDetection(QObject* parent = nullptr);
	~FaceDetection();
	void start(FaceDetectionDialog* initDialog,
		QString videoPath,
		bool saveToVideoFlag,
		bool saveToImageFlag,
		bool saveToTxtFlag,
		double scaleFactor,
		double confidenceThreshold);
	void initializeLoadingDialog();

private:
	MotionDetectionLoad* loadDialog;
};

#endif //FACEDETECTION_H
