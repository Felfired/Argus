#ifndef FACEDETECTIONDIALOG_H
#define FACEDETECTIONDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QCheckBox>
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
	QLineEdit* saveFolderDisplay;
	QString saveFolderPath;
	bool saveToVideoFlag;
	bool saveToImageFlag;
	bool enableButtonFlag;
};

#endif // SAVECONFIGDIALOG_H
