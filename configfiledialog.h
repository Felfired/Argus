#ifndef CONFIGFILEDIALOG_H
#define CONFIGFILEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QFile>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QTextBrowser>
#include <QMessageBox>

namespace Ui { class ConfigFileDialog; }

class ConfigFileDialog : public QDialog
{
	Q_OBJECT

public:
	ConfigFileDialog(const QString configFilePath, QWidget* parent = nullptr);
	~ConfigFileDialog();

signals:
	void onApplyButtonClicked(const QString& filePath);

private slots:
	void buttonOpenFileClicked();
	void buttonCancelClicked();
	void buttonCancelActivation();
	void buttonApplyClicked();
	bool readAndDisplay(QString filePath);

private:
	Ui::ConfigFileDialog* ui;
	QPushButton* openButton;
	QPushButton* cancelButton;
	QPushButton* applyButton;
	QProgressBar* progressBar;
	QTextBrowser* textBrowser;
	QLineEdit* filepathLineEdit;
	QLabel* fileLabel;
	QLabel* sizeLabel;
	QString configFilePath;
	bool isfileLoading;
	bool isfileLoaded;
};

#endif // CONFIGFILEDIALOG_H
