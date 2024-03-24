#ifndef FACEDETECTIONDIALOG_H
#define FACEDETECTIONDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QCheckBox>
#include <QSpinBox>
#include <QSettings>

namespace Ui { class FaceDetectionDialog; }

class FaceDetectionDialog : public QDialog
{
	Q_OBJECT

public:
	FaceDetectionDialog(const QString& videoPath, QWidget* parent = nullptr);
	~FaceDetectionDialog();
	void setParams();
	void disableButtons();
	void enableButtons();

private slots:
	void closeButtonClicked();
	void startButtonClicked();
	void selectFolderButtonClicked();
	void updateStartButtonState();

private:
	Ui::FaceDetectionDialog* ui;
	QPushButton* closeButton;
	QPushButton* startButton;
	QPushButton* selectFolderButton;
	QCheckBox* saveToVideoCheckBox;
	QCheckBox* saveToImageCheckBox;
	QCheckBox* saveToTxtCheckBox;
	QLineEdit* saveFolderDisplay;
	QDoubleSpinBox* scaleFactorSpinBox;
	QDoubleSpinBox* confidenceThresholdSpinBox;
	QString saveFolderPath;
	QString loadedVideoPath;
	bool saveToVideoFlag;
	bool saveToImageFlag;
	bool saveToTxtFlag;
	bool enableButtonFlag;
	double scaleFactor;
	double confidenceThreshold;
};

#endif // SAVECONFIGDIALOG_H
