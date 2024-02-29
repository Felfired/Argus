#ifndef CATALOGDIALOG_H
#define CATALOGDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QFileInfo>
#include <QListView>
#include <QMessageBox>
#include <QFrame>
#include <QPixmap>
#include <QTableWidget>
#include <QDir>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <addpersondialog.h>
#include <catalogservice.h>

namespace Ui { class CatalogDialog; }

class CatalogDialog : public QDialog
{
	Q_OBJECT

public:
	CatalogDialog(QWidget* parent = nullptr);
	~CatalogDialog();

private slots:
	void buttonAddClicked();
	bool isFolderEmpty();
	void showFolderSetupError(const QString& errorMessage);
	void onTableItemClicked(int row, int col);
	void buttonRefreshClicked();
	void buttonDeleteClicked();
	QMessageBox* createWarningDialog();
	void createSuccessDialog() const;

private:
	Ui::CatalogDialog* ui;
	QPushButton* addButton;
	QToolButton* refreshTableButton;
	QPushButton* deleteButton;
	AddPersonDialog* addDialog;
	QString catalogFolderPath;
	QLabel* pathLabel;
	QLabel* idLabel;
	QLabel* birthLabel;
	QLabel* trainedStatusLabel;
	QLabel* datasetLabel;
	QLabel* pictureLabel;
	QFrame* frame;
	QTableWidget* catalogTableWidget;
};

#endif //CATALOGDIALOG_H