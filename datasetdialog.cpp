#include "datasetdialog.h"
#include "./ui_datasetdialog.h"

DatasetDialog::DatasetDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::DatasetDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
}

DatasetDialog::~DatasetDialog()
{
    delete ui;
}