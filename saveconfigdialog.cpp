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
    catalogFolderDisplay = ui->catalogFolderDisplay;
    catalogFolderDisplay->setReadOnly(true);

    resultsFolderSelect = ui->resultsFolderSelect;
    connect(resultsFolderSelect, &QPushButton::clicked, this, &SaveConfigDialog::selectResultsFolderClicked);
    resultsFolderDisplay = ui->resultsFolderDisplay;
    resultsFolderDisplay->setReadOnly(true);
    
    applyButton = ui->applyButton;
    applyButton->setEnabled(false);
    connect(applyButton, &QPushButton::clicked, this, &SaveConfigDialog::applyButtonClicked);

    cancelButton = ui->cancelButton;
    connect(cancelButton, &QPushButton::clicked, this, &SaveConfigDialog::cancelButtonClicked);

    QSettings settings("config.ini", QSettings::IniFormat);
    if (settings.contains("Save_Preferences/Catalog_Path"))
    {
        originalCatalogFolderPath = settings.value("Save_Preferences/Catalog_Path").toString();
        catalogFolderPath = originalCatalogFolderPath;
        catalogFolderDisplay->setText(catalogFolderPath);
    }
    if (settings.contains("Save_Preferences/Results_Path"))
    {
        originalResultsFolderPath = settings.value("Save_Preferences/Results_Path").toString();
        resultsFolderPath = originalResultsFolderPath;
        resultsFolderDisplay->setText(resultsFolderPath);
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

    if (catalogFolderPath != originalCatalogFolderPath)
    {
        applyButton->setEnabled(true);
    }
}

void SaveConfigDialog::selectResultsFolderClicked()
{
    resultsFolderPath = QFileDialog::getExistingDirectory(this, tr("Επιλογή Φακέλου..."), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    resultsFolderDisplay->setText(resultsFolderPath);

    if (resultsFolderPath != originalResultsFolderPath)
    {
        applyButton->setEnabled(true);
    }
}

void SaveConfigDialog::applyButtonClicked()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("Save_Preferences/Catalog_Path", catalogFolderPath);
    settings.setValue("Save_Preferences/Results_Path", resultsFolderPath);
    settings.sync();
    close();
}