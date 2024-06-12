#include "aboutopencvdialog.h"
#include "./ui_aboutopencv.h"

AboutOpencvDialog::AboutOpencvDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AboutOpencvDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
}

AboutOpencvDialog::~AboutOpencvDialog()
{
    delete ui;
}