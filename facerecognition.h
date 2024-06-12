#ifndef FACERECOGNITION_H
#define FACERECOGNITION_H

#include <QObject>
#include "facerecognitiondialog.h"

class FaceRecognition : public QObject
{
	Q_OBJECT

public:
	FaceRecognition(QObject* parent = nullptr);
	~FaceRecognition();
	void start(FaceRecognitionDialog* initDialog,
		QString folderPath,
		QString distanceCalculationMode,
		bool saveToTxtFlag);

private:
};

#endif //FACEDETECTION_H
