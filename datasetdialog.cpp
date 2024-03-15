#include "datasetdialog.h"
#include "./ui_datasetdialog.h"

DatasetDialog::DatasetDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::DatasetDialog)
{
    ui->setupUi(this);
    setFixedSize(430, 410);
    setWindowModality(Qt::ApplicationModal);
    QSettings settings("config.ini", QSettings::IniFormat);
    catalogFolderPath = settings.value("Save_Preferences/Catalog_Path").toString();
    QDir folderInfo(catalogFolderPath);
    QString folderName = folderInfo.dirName();
    CatalogService service = new CatalogService();

    addImgWidget = ui->tabWidget->widget(1);
    addImgWidget->setEnabled(false);

    labelID = ui->labelID;

    cancelButton = ui->cancelButton;
    connect(cancelButton, &QPushButton::clicked, this, &DatasetDialog::onCancelButtonClicked);

    openButton = ui->openButton;
    connect(openButton, &QPushButton::clicked, this, &DatasetDialog::onOpenButtonClicked);

    clearSelectionButton = ui->clearSelectionButton;
    connect(clearSelectionButton, &QToolButton::clicked, this, &DatasetDialog::clearCatalogSelection);

    searchTextEdit = ui->searchTextEdit;
    connect(searchTextEdit, &QTextEdit::textChanged, this, &DatasetDialog::onSearchTextChanged);

    refreshButton = ui->refreshButton;
    refreshButton->setEnabled(false);
    connect(refreshButton, &QToolButton::clicked, this, &DatasetDialog::onRefreshButtonClicked);
    
    deleteButton = ui->deleteButton;
    deleteButton->setEnabled(false);
    connect(deleteButton, &QToolButton::clicked, this, &DatasetDialog::onDeleteButtonClicked);

    previewButton = ui->previewButton;
    previewButton->setEnabled(false);

    catalogDisplayTableWidget = ui->catalogDisplayTableWidget;
    DatasetDialog::setupCatalogTable();
    DatasetDialog::fillCatalogTable();

    datasetDisplayTableWidget = ui->datasetDisplayTableWidget;
    DatasetDialog::setupDatasetTable();
}

DatasetDialog::~DatasetDialog()
{
    delete ui;
}

void DatasetDialog::onCatalogTableItemClicked(int row)
{
    selectedID = catalogDisplayTableWidget->item(row, 0)->text();
    labelID->setText(selectedID);
    addImgWidget->setEnabled(true);
    DatasetDialog::fillDatasetTable(selectedID);
}

void DatasetDialog::onDatasetTableItemClicked(int row)
{
    deleteButton->setEnabled(true);
    refreshButton->setEnabled(true);
    previewButton->setEnabled(true);
}

void DatasetDialog::onSearchTextChanged()
{
    QString searchText = searchTextEdit->toPlainText();
    filterTable(searchText);
}

void DatasetDialog::filterTable(const QString& searchText)
{
    for (int row = 0; row < catalogDisplayTableWidget->rowCount(); ++row)
    {
        bool rowVisible = false;
        for (int col = 0; col < catalogDisplayTableWidget->columnCount(); ++col)
        {
            QTableWidgetItem* item = catalogDisplayTableWidget->item(row, col);
            if (item && item->text().contains(searchText, Qt::CaseInsensitive))
            {
                rowVisible = true;
                break;
            }
        }
        catalogDisplayTableWidget->setRowHidden(row, !rowVisible);
    }
}

void DatasetDialog::clearCatalogSelection()
{
    catalogDisplayTableWidget->clearSelection();
    addImgWidget->setEnabled(false);
    labelID->setText("");
    datasetDisplayTableWidget->clearContents();
}

void DatasetDialog::onRefreshButtonClicked()
{
    datasetDisplayTableWidget->clearContents();
    datasetDisplayTableWidget->setRowCount(0);
    DatasetDialog::fillDatasetTable(selectedID);
}

void DatasetDialog::onCancelButtonClicked()
{
    close();
}

void DatasetDialog::onDeleteButtonClicked()
{

}

void DatasetDialog::onOpenButtonClicked()
{
    QStringList fileList = QFileDialog::getOpenFileNames(
        nullptr,
        "Επιλέξτε μια ή περισσότερες φωτογραφίες...",
        QDir::currentPath(),
        "Εικόνες (*.png *.jpg)"
    );

    QStringList validFiles = DatasetDialog::checkPictureSizeConstraints(fileList);
    QStringList invalidFiles;

    // Compare fileList with validFiles
    for (const QString& file : fileList) 
    {
        if (!validFiles.contains(file)) 
        {
            invalidFiles << file;
        }
    }

    if (!invalidFiles.isEmpty())
    {
        DatasetDialog::createDatasetWarningDialog(invalidFiles);
    }
    CatalogService service = new CatalogService();
    service.addPicturesToDataset(validFiles, selectedID);
    DatasetDialog::onRefreshButtonClicked();
}

void DatasetDialog::fillCatalogTable()
{
    CatalogService service = new CatalogService();
    if (service.isCatalogFolderEmpty())
    {
        // Table stays empty.
    }

    else
    {
        std::vector<QStringList> catalogEntries = service.getAllEntries();
        // Populating the table widget.
        for (const auto& entry : catalogEntries)
        {
            int row = catalogDisplayTableWidget->rowCount();
            catalogDisplayTableWidget->insertRow(row);

            for (int i = 0; i < entry.size(); ++i)
            {
                QTableWidgetItem* item = new QTableWidgetItem(entry[i]);
                if (item)
                {
                    item->setTextAlignment(Qt::AlignCenter);
                }
                catalogDisplayTableWidget->setItem(row, i, item);
            }
        }
        catalogDisplayTableWidget->setSortingEnabled(true);
    }
}

void DatasetDialog::fillDatasetTable(QString id)
{
    CatalogService service = new CatalogService();
    if (service.isDatasetFolderEmpty(id))
    {
        // Table stays empty. Buttons will not be enabled.
    }

    else
    {
        std::vector<QStringList> datasetEntries = service.getDataset(id);
        // Populating the table widget.
        for (const auto& entry : datasetEntries)
        {
            int row = datasetDisplayTableWidget->rowCount();
            datasetDisplayTableWidget->insertRow(row);

            for (int i = 0; i < entry.size(); ++i)
            {
                QTableWidgetItem* item = new QTableWidgetItem(entry[i]);
                if (item)
                {
                    item->setTextAlignment(Qt::AlignCenter);
                }
                datasetDisplayTableWidget->setItem(row, i, item);
            }
        }
        catalogDisplayTableWidget->setSortingEnabled(true);
    }
}

void DatasetDialog::setupCatalogTable()
{
    catalogDisplayTableWidget->setColumnCount(3);
    catalogDisplayTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList labels = { "ID", "Όνομα", "Επώνυμο" };
    catalogDisplayTableWidget->setHorizontalHeaderLabels(labels);
    catalogDisplayTableWidget->verticalHeader()->setVisible(false);
    catalogDisplayTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    catalogDisplayTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    catalogDisplayTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    catalogDisplayTableWidget->setSortingEnabled(false);
    connect(catalogDisplayTableWidget, &QTableWidget::cellClicked, this, &DatasetDialog::onCatalogTableItemClicked);
}

void DatasetDialog::setupDatasetTable()
{
    datasetDisplayTableWidget->setColumnCount(3);
    datasetDisplayTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList labels = { "Όνομα Αρχείου", "Μέγεθος", "Διαστάσεις" };
    datasetDisplayTableWidget->setHorizontalHeaderLabels(labels);
    datasetDisplayTableWidget->verticalHeader()->setVisible(false);
    datasetDisplayTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    datasetDisplayTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    datasetDisplayTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    datasetDisplayTableWidget->setSortingEnabled(false);
    connect(datasetDisplayTableWidget, &QTableWidget::cellClicked, this, &DatasetDialog::onDatasetTableItemClicked);
}

QStringList DatasetDialog::checkPictureSizeConstraints(QStringList fileList)
{
    QStringList validFiles;

    for (const QString& filePath : fileList) 
    {
        QImage image(filePath);
        if (!image.isNull()) 
        {
            for (int size = 64; size <= 512; size += 64) 
            {
                if (image.width() == size && image.height() == size) 
                {
                    // Image size meets the constraints, add it to the valid files list.
                    validFiles.append(filePath);
                    // No need to check further sizes.
                    break; 
                }
            }
        }
    }
    return validFiles;
}

void DatasetDialog::createDatasetWarningDialog(QStringList invalidFiles) const
{
    QMessageBox warningBox;
    warningBox.setWindowTitle("Προειδοποίηση.");
    QIcon windowIcon(":argus/res/app_icons/dataset.png");
    warningBox.setWindowIcon(windowIcon);
    warningBox.setText("Οι παρακάτω εικόνες δεν πληρούν τις προϋποθέσεις μεγέθους: " );
    QString fileListText;
    for (const QString& filePath : invalidFiles) 
    {
        QFileInfo fileInfo(filePath);
        fileListText += fileInfo.fileName() + "\n";
    }
    warningBox.setDetailedText(fileListText);
    warningBox.setIcon(QMessageBox::Warning);
    warningBox.addButton(QMessageBox::Ok);
    warningBox.exec();
}