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
	void applyButtonClicked();

private:
	Ui::SaveConfigDialog* ui;
	QPushButton* cancelButton;
	QPushButton* applyButton;
	QPushButton* catalogFolderSelect;
	QLabel* catalogImageLabel;
	QString catalogFolderPath;
	QLineEdit* catalogFolderDisplay;
};

#endif // SAVECONFIGDIALOG_H
