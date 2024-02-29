#include "saveconfigdialog.h"
#include "./ui_saveconfigdialog.h"

SaveConfigDialog::SaveConfigDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::SaveConfigDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);

    catalogFolderSelect = ui->catalogFolderSelect;
    connect(catalogFolderSelect, &QPushButton::clicked, this, &SaveConfigDialog::selectCatalogFolderClicked);
    
    applyButton = ui->applyButton;
    connect(applyButton, &QPushButton::clicked, this, &SaveConfigDialog::applyButtonClicked);

    cancelButton = ui->cancelButton;
    connect(cancelButton, &QPushButton::clicked, this, &SaveConfigDialog::cancelButtonClicked);

    catalogFolderDisplay = ui->catalogFolderDisplay;
    catalogFolderDisplay->setReadOnly(true);

    QSettings settings("config.ini", QSettings::IniFormat);
    if (settings.contains("Save_Preferences/Catalog_Path"))
    {
        catalogFolderPath = settings.value("Save_Preferences/Catalog_Path").toString();
        catalogFolderDisplay->setText(catalogFolderPath);
    }
}

SaveConfigDialog::~SaveConfigDialog()
{
    delete ui;
}

void SaveConfigDialog::cancelButtonClicked()
{
    close();
}

void SaveConfigDialog::selectCatalogFolderClicked()
{
    catalogFolderPath = QFileDialog::getExistingDirectory(this, tr("Επιλογή Φακέλου..."), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    catalogFolderDisplay->setText(catalogFolderPath);
}

void SaveConfigDialog::applyButtonClicked()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("Save_Preferences/Catalog_Path", catalogFolderPath);
    settings.sync();
    close();
}