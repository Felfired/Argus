#ifndef RECOGNITIONCONFIGDIALOG_H
#define RECOGNITIONCONFIGDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSettings>
#include <QPushButton>
#include <QFileDialog>

namespace Ui { class RecognitionConfigDialog; }

class RecognitionConfigDialog : public QDialog
{
	Q_OBJECT

public:
	RecognitionConfigDialog(QWidget* parent = nullptr);
	~RecognitionConfigDialog();

private slots:
	void cancelButtonClicked();
	void applyButtonClicked(); 
	void openSFaceFileButtonClicked();

private:
	Ui::RecognitionConfigDialog* ui;
	QPushButton* cancelButton;
	QPushButton* applyButton;
	QPushButton* openSfaceFileButton;
	QString sfaceFilePath;
	QLineEdit* sfaceFPLineEdit;
	QString originalSfaceFilePath;
};

#endif
