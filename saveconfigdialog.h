#ifndef SAVECONFIGDIALOG_H
#define SAVECONFIGDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QLabel>
#include <QSettings>

namespace Ui { class SaveConfigDialog; }

class SaveConfigDialog : public QDialog
{
	Q_OBJECT

public:
	SaveConfigDialog(QWidget* parent = nullptr);
	~SaveConfigDialog();

private slots:
	void cancelButtonClicked();
	void selectCatalogFolderClicked();
	void selectResultsFolderClicked();
	void applyButtonClicked();

private:
	Ui::SaveConfigDialog* ui;
	QPushButton* cancelButton;
	QPushButton* applyButton;
	QPushButton* catalogFolderSelect;
	QString catalogFolderPath;
	QLineEdit* catalogFolderDisplay;
	QPushButton* resultsFolderSelect;
	QString resultsFolderPath;
	QLineEdit* resultsFolderDisplay;
	QString originalCatalogFolderPath;
	QString originalResultsFolderPath;
};

#endif // SAVECONFIGDIALOG_H
