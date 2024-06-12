#include "aboutargusdialog.h"
#include "./ui_aboutargus.h"

AboutArgusDialog::AboutArgusDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AboutArgusDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
}

AboutArgusDialog::~AboutArgusDialog()
{
    delete ui;
}