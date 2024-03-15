#ifndef DATASETDIALOG_H
#define DATASETDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QTabWidget>
#include <QFileDialog>
#include <QCheckBox>
#include <QTextEdit>
#include <vector>
#include "catalogservice.h"

namespace Ui { class DatasetDialog; }

class DatasetDialog : public QDialog
{
	Q_OBJECT

public:
	DatasetDialog(QWidget* parent = nullptr);
	~DatasetDialog();

private slots:
	void onCatalogTableItemClicked(int row);
	void onDatasetTableItemClicked(int row);
	void clearCatalogSelection();
	void filterTable(const QString& searchText);
	void fillCatalogTable();
	void fillDatasetTable(QString id);
	void onSearchTextChanged();
	void onCancelButtonClicked();
	void onOpenButtonClicked();
	void onRefreshButtonClicked();
	void onDeleteButtonClicked();
	void setupCatalogTable();
	void setupDatasetTable();
	void createDatasetWarningDialog(QStringList invalidFiles) const;
	QStringList checkPictureSizeConstraints(QStringList fileList);

private:
	Ui::DatasetDialog* ui;
	QTableWidget* catalogDisplayTableWidget;
	QTableWidget* datasetDisplayTableWidget;
	QPushButton* cancelButton;
	QPushButton* openButton;
	QToolButton* clearSelectionButton;
	QToolButton* previewButton;
	QToolButton* deleteButton;
	QToolButton* refreshButton;
	QTabWidget* tabWidget;
	QString catalogFolderPath;
	QString selectedID;
	QWidget* addImgWidget;
	QLabel* labelID;
	QTextEdit* searchTextEdit;
};

#endif // DATASETDIALOG_H
