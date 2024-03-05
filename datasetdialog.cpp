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

    clearSelectionButton = ui->clearSelectionButton;
    connect(clearSelectionButton, &QToolButton::clicked, this, &DatasetDialog::clearSelection);

    searchTextEdit = ui->searchTextEdit;
    connect(searchTextEdit, &QTextEdit::textChanged, this, &DatasetDialog::onSearchTextChanged);

    catalogDisplayTableWidget = ui->catalogDisplayTableWidget;
    catalogDisplayTableWidget->setColumnCount(3);
    catalogDisplayTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList labels = { "ID", "Όνομα", "Επώνυμο" };
    catalogDisplayTableWidget->setHorizontalHeaderLabels(labels);
    catalogDisplayTableWidget->verticalHeader()->setVisible(false);
    catalogDisplayTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    catalogDisplayTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    catalogDisplayTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    catalogDisplayTableWidget->setSortingEnabled(false);
    connect(catalogDisplayTableWidget, &QTableWidget::cellClicked, this, &DatasetDialog::onTableItemClicked);

    if (DatasetDialog::isFolderEmpty() == true)
    {
        // Table stays empty.
    }

    else if (DatasetDialog::isFolderEmpty() == false)
    {
        CatalogService service = new CatalogService();
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

bool DatasetDialog::isFolderEmpty()
{
    QDir folder(catalogFolderPath);
    QStringList entries = folder.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);
    return entries.isEmpty();
}

void DatasetDialog::onTableItemClicked(int row)
{
    selectedID = catalogDisplayTableWidget->item(row, 0)->text();
    labelID->setText(selectedID);
    addImgWidget->setEnabled(true);
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

void DatasetDialog::clearSelection()
{
    catalogDisplayTableWidget->clearSelection();
    addImgWidget->setEnabled(false);
    labelID->setText("");
}

DatasetDialog::~DatasetDialog()
{
    delete ui;
}