#ifndef CATALOGDIALOG_H
#define CATALOGDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QFileInfo>
#include <QListView>
#include <QMessageBox>
#include <QComboBox>
#include <QLineEdit>
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
	void onTableItemClicked(int row);
	void buttonRefreshClicked();
	void buttonDeleteClicked();
	int createWarningDialog();
	void createSuccessDialog(QString id) const;
	void sortTable(int index);
	void filterTable(const QString& searchText);

private:
	Ui::CatalogDialog* ui;
	QPushButton* addButton;
	QToolButton* refreshTableButton;
	QPushButton* deleteButton;
	QLineEdit* searchLineEdit;
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
	QComboBox* sortComboBox;
};

#endif //CATALOGDIALOG_H