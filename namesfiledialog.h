#ifndef NAMESFILEDIALOG_H
#define NAMESFILEDIALOG_H

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

namespace Ui { class NamesFileDialog; }

class NamesFileDialog : public QDialog
{
	Q_OBJECT

public:
	NamesFileDialog(const QString namesFilePath, QWidget *parent = nullptr);
	~NamesFileDialog();

signals:
	void onApplyButtonClicked(const QString& filePath);

private slots:
	void buttonOpenFileClicked();
	void buttonCancelClicked();
	void buttonCancelActivation();
	void buttonApplyClicked();
	bool readAndDisplay(QString filePath);

private:
	Ui::NamesFileDialog *ui;
	QPushButton *openButton;
	QPushButton *cancelButton;
	QPushButton *applyButton;
	QProgressBar *progressBar;
	QTextBrowser *textBrowser;
	QLineEdit *filepathLineEdit;
	QLabel *fileLabel;
	QLabel *sizeLabel;
	QString namesFilePath;
	bool isfileLoading;
	bool isfileLoaded;
};

#endif // NAMESFILEDIALOG_H
