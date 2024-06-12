#include "contacthelpdialog.h"
#include "./ui_contacthelpdialog.h"

ContactHelpDialog::ContactHelpDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ContactHelpDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
}

ContactHelpDialog::~ContactHelpDialog()
{
    delete ui;
}