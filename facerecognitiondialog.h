#ifndef FACERECOGNITIONDIALOG_H
#define FACERECOGNITIONDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QCheckBox>
#include <QProgressBar>

namespace Ui { class FaceRecognitionDialog; }

class FaceRecognitionDialog : public QDialog
{
	Q_OBJECT

public:
	FaceRecognitionDialog(QWidget* parent = nullptr);
	~FaceRecognitionDialog();

private:
	Ui::FaceRecognitionDialog* ui;
	QComboBox* distanceCalculationComboBox;
	QPushButton* selectFolderButton;
	QLineEdit* folderDisplayLineEdit;
	QTableWidget* resultsTableWidget;
	QCheckBox* saveToTextCheckBox;
	QProgressBar* progressBar;
};

#endif //FACERECOGNITIONDIALOG_H
