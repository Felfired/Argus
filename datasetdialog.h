#ifndef DATASETDIALOG_H
#define DATASETDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QTabWidget>
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
	bool isFolderEmpty();
	void onTableItemClicked(int row);
	void clearSelection();
	void filterTable(const QString& searchText);
	void onSearchTextChanged();

private:
	Ui::DatasetDialog* ui;
	QTableWidget* catalogDisplayTableWidget;
	QToolButton* clearSelectionButton;
	QTabWidget* tabWidget;
	QString catalogFolderPath;
	QString selectedID;
	QWidget* addImgWidget;
	QLabel* labelID;
	QTextEdit* searchTextEdit;
};

#endif // DATASETDIALOG_H
