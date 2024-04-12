#ifndef DATASETDIALOG_H
#define DATASETDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QModelIndexList>
#include <QTabWidget>
#include <QFileDialog>
#include <QLineEdit>
#include <QCheckBox>
#include <QTextEdit>
#include <vector>
#include "catalogservice.h"
#include "imagedisplaydialog.h"

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
	void onPreviewButtonClicked();
	void onSaveToTextButtonClicked();
	void disableDatasetButtons();
	void setupCatalogTable();
	void setupDatasetTable();
	void createDatasetWarningDialog(QStringList invalidFiles) const;
	void createSuccessDialog(QString message) const;
	void createImageDialog(QString imagePath) const; 
	QStringList checkPictureSizeConstraints(QStringList fileList);

private:
	Ui::DatasetDialog* ui;
	QTableWidget* catalogDisplayTableWidget;
	QTableWidget* datasetDisplayTableWidget;
	QPushButton* cancelButton;
	QPushButton* openButton;
	QPushButton* saveToTextButton;
	QToolButton* clearSelectionButton;
	QToolButton* previewButton;
	QToolButton* deleteButton;
	QToolButton* refreshButton;
	QTabWidget* tabWidget;
	QLineEdit* displayPathLineEdit;
	QString catalogFolderPath;
	QString selectedID;
	QWidget* addImgWidget;
	QLabel* labelID;
	QTextEdit* searchTextEdit;
};

#endif // DATASETDIALOG_H
