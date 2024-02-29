#ifndef WEIGHTSFILEDIALOG_H
#define WEIGHTSFILEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QFile>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui { class WeightsFileDialog; }

class WeightsFileDialog : public QDialog
{
	Q_OBJECT

public:
	WeightsFileDialog(const QString weightsFilePath, QWidget* parent = nullptr);
	~WeightsFileDialog();

signals:
	void onApplyButtonClicked(const QString& filePath);

private slots:
	void buttonOpenFileClicked();
	void buttonCancelClicked();
	void buttonCancelActivation();
	void buttonApplyClicked();
	bool readFile(QString filePath);

private:
	Ui::WeightsFileDialog* ui;
	QPushButton *openButton;
	QPushButton *cancelButton;
	QPushButton *applyButton;
	QProgressBar *progressBar;
	QLineEdit* filepathLineEdit;
	QLabel* fileLabel;
	QLabel* sizeLabel;
	QString weightsFilePath;
	bool isfileLoading;
	bool isfileLoaded;
};

#endif // WEIGHTSFILEDIALOG_H