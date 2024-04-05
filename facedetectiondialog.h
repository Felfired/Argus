#ifndef FACEDETECTIONDIALOG_H
#define FACEDETECTIONDIALOG_H

#include <QDialog>
#include <QTabWidget>
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
	void frameskipHelpButtonClicked();
	void changeFrameskipCheckboxState();

private:
	Ui::FaceDetectionDialog* ui;
	QPushButton* frameskipHelpButton;
	QPushButton* closeButton;
	QPushButton* startButton;
	QPushButton* selectFolderButton;
	QCheckBox* saveToVideoCheckBox;
	QCheckBox* saveToImageCheckBox;
	QCheckBox* saveToTxtCheckBox;
	QCheckBox* applyToImageCheckBox;
	QCheckBox* applyToVideoCheckBox;
	QLineEdit* saveFolderDisplay;
	QTabWidget* modelSelectionTabWidget;
	QDoubleSpinBox* scaleFactorSpinBox;
	QDoubleSpinBox* confidenceThresholdSpinBox;
	QDoubleSpinBox* nmsThresholdSpinBox;
	QDoubleSpinBox* yConfidenceThresholdSpinBox;
	QSpinBox* detectionCountSpinBox;
	QSpinBox* frameskipSpinBox;
	QString saveFolderPath;
	QString loadedVideoPath;
	QString selectedModel;
	bool saveToVideoFlag;
	bool saveToImageFlag;
	bool saveToTxtFlag;
	bool enableButtonFlag;
	double scaleFactor;
	double confidenceThreshold;
	double yConfidenceThreshold;
	double nmsThreshold;
	int detectionCount;
	int frameskipSelection;
	int frameskipValue;
};

#endif // SAVECONFIGDIALOG_H
