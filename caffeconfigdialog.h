#ifndef CAFFECONFIGDIALOG_H
#define CAFFECONFIGDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QLabel>
#include <QSettings>

namespace Ui { class CaffeConfigDialog; }

class CaffeConfigDialog : public QDialog
{
	Q_OBJECT

public:
	CaffeConfigDialog(QWidget* parent = nullptr);
	~CaffeConfigDialog();

private slots:
	void cancelButtonClicked();
	void openModelFileClicked();
	void openConfigFileClicked();
	void saveButtonClicked();

private:
	Ui::CaffeConfigDialog* ui;
	QPushButton* openModelFileButton;
	QPushButton* openConfigFileButton;
	QPushButton* closeButton;
	QPushButton* saveButton;
	QLineEdit* modelFPLineEdit;
	QLineEdit* configFPLineEdit;
	QString modelFilePath;
	QString configFilePath;
	QString originalModelFilePath;
	QString originalConfigFilePath;
};

#endif // CAFFECONFIGDIALOG_H
