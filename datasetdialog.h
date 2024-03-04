#ifndef DATASETDIALOG_H
#define DATASETDIALOG_H

#include <QDialog>

namespace Ui { class DatasetDialog; }

class DatasetDialog : public QDialog
{
	Q_OBJECT

public:
	DatasetDialog(QWidget* parent = nullptr);
	~DatasetDialog();

private:
	Ui::DatasetDialog* ui;
};

#endif // DATASETDIALOG_H
