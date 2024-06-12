#ifndef FACERECOGNITIONDIALOG_H
#define FACERECOGNITIONDIALOG_H

#include <QDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QFileDialog>
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
	void stopButtonClicked(); 
	void onCompletion();
	void setLoadingProgress(int progress);
	void addRecognitionToTable(std::string idFound);
	
private slots:
	void onRejected();
	void selectFolderButtonClicked();
	void onAccepted();
	int onRecognitionCompleted();
	void setParams();
	void clearResultsTable();

private:
	Ui::FaceRecognitionDialog* ui;
	QComboBox* distanceCalculationComboBox;
	QPushButton* selectFolderButton;
	QToolButton* stopButton;
	QDialogButtonBox* buttonBox;
	QLineEdit* folderDisplayLineEdit;
	QTableWidget* resultsTableWidget;
	QCheckBox* saveToTextCheckBox;
	QProgressBar* progressBar;
	QString distanceCalculationMode;
	QString folderPath;
};

#endif //FACERECOGNITIONDIALOG_H
