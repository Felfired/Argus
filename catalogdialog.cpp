#include "catalogdialog.h"
#include "./ui_catalogdialog.h"

CatalogDialog::CatalogDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::CatalogDialog)
{
    ui->setupUi(this);

    addButton = ui->addButton;
    connect(addButton, &QPushButton::clicked, this, &CatalogDialog::buttonAddClicked);

    refreshTableButton = ui->refreshTableButton;
    connect(refreshTableButton, &QToolButton::clicked, this, &CatalogDialog::buttonRefreshClicked);

    deleteButton = ui->deleteButton;
    connect(deleteButton, &QPushButton::clicked, this, &CatalogDialog::buttonDeleteClicked);

    sortComboBox = ui->sortComboBox;
    sortComboBox->addItem("ID " + QString(QChar(0x2191)) + " (Αύξουσα)");
    sortComboBox->addItem("ID " + QString(QChar(0x2193)) + " (Φθίνουσα)");
    sortComboBox->addItem("Επίθετο (Α-Ω)");
    sortComboBox->addItem("Επίθετο (Ω-Α)");
    connect(sortComboBox, QOverload<int>::of(&QComboBox::activated), this, &CatalogDialog::sortTable);

    searchLineEdit = ui->searchLineEdit;
    connect(searchLineEdit, &QLineEdit::textChanged, this, &CatalogDialog::filterTable);

    QSettings settings("config.ini", QSettings::IniFormat);
    catalogFolderPath = settings.value("Save_Preferences/Catalog_Path").toString();
    QDir folderInfo(catalogFolderPath);
    QString folderName = folderInfo.dirName();

    pathLabel = ui->pathLabel;
    pathLabel->setToolTip("Αποθήκευση στον φάκελο: " + folderName);
    pathLabel->setStyleSheet("QLabel { color : #0000EE; }");

    idLabel = ui->idLabel;
    birthLabel = ui->birthLabel;
    datasetLabel = ui->datasetLabel;
    trainedStatusLabel = ui->trainedStatusLabel;
    pictureLabel = ui->pictureLabel;
    frame = ui->frame;

    catalogTableWidget = ui->catalogTableWidget;
    catalogTableWidget->setColumnCount(3);
    catalogTableWidget->setColumnWidth(0, 45);
    catalogTableWidget->setColumnWidth(1, 175);
    catalogTableWidget->setColumnWidth(2, 175);

    QStringList labels = { "ID", "Όνομα", "Επώνυμο" };
    catalogTableWidget->setHorizontalHeaderLabels(labels);
    catalogTableWidget->verticalHeader()->setVisible(false);
    catalogTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    catalogTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    catalogTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    catalogTableWidget->setSortingEnabled(false);
    connect(catalogTableWidget, &QTableWidget::cellClicked, this, &CatalogDialog::onTableItemClicked);

    if (CatalogDialog::isFolderEmpty() == true)
    {
        // Table stays empty.
    }

    else if (CatalogDialog::isFolderEmpty() == false)
    {
        CatalogService service = new CatalogService();
        std::vector<QStringList> catalogEntries = service.getAllEntries();
        // Populating the table widget.
        for (const auto& entry : catalogEntries) 
        {
            int row = catalogTableWidget->rowCount();
            catalogTableWidget->insertRow(row);
            for (int i = 0; i < entry.size(); ++i) 
            {
                QTableWidgetItem* item = new QTableWidgetItem(entry[i]);
                if (item) 
                {
                    item->setTextAlignment(Qt::AlignCenter);
                }
                catalogTableWidget->setItem(row, i, item);
            }
        }
        catalogTableWidget->setSortingEnabled(true);
    }
}

CatalogDialog::~CatalogDialog()
{
    delete ui;
}

void CatalogDialog::buttonAddClicked()
{
    addDialog = new AddPersonDialog();
    addDialog->show();
    addDialog->activateWindow();

    CatalogService service = new CatalogService();
    connect(&service, &CatalogService::folderSetupFailed, this, &CatalogDialog::showFolderSetupError);
}

void CatalogDialog::showFolderSetupError(const QString& errorMessage)
{
    QMessageBox::critical(this, tr("Σφάλμα!"), errorMessage);
}

bool CatalogDialog::isFolderEmpty()
{
    QDir folder(catalogFolderPath);
    QStringList entries = folder.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);
    return entries.isEmpty();
}

void CatalogDialog::onTableItemClicked(int row)
{
    QString idEntry = catalogTableWidget->item(row, 0)->text();
    CatalogService service = new CatalogService();
    QStringList entryData = service.getEntryData(idEntry);

    idLabel->setText(entryData.at(2));
    birthLabel->setText(entryData.at(3));
    if (entryData.at(6) == "No")
    {
        trainedStatusLabel->setText("");
    }
    else if (entryData.at(6) == "Yes")
    {
        trainedStatusLabel->setText("");
    }
    datasetLabel->setText(entryData.at(7));
    QPixmap image(entryData.at(8));
    pictureLabel->setPixmap(image);
    pictureLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    pictureLabel->setScaledContents(true);
}

void CatalogDialog::buttonRefreshClicked()
{
    catalogTableWidget->setSortingEnabled(false);
    catalogTableWidget->clearContents();
    catalogTableWidget->setRowCount(0);
    CatalogService service = new CatalogService();
    std::vector<QStringList> catalogEntries = service.getAllEntries();
    for (const auto& entry : catalogEntries)
    {
        int row = catalogTableWidget->rowCount();
        catalogTableWidget->insertRow(row);
        for (int i = 0; i < entry.size(); ++i)
        {
            QTableWidgetItem* item = new QTableWidgetItem(entry[i]);
            if (item)
            {
                item->setTextAlignment(Qt::AlignCenter);
            }
            catalogTableWidget->setItem(row, i, item);
        }
    }
    catalogTableWidget->setSortingEnabled(true);
}

void CatalogDialog::buttonDeleteClicked()
{
    int selectedRow = catalogTableWidget->currentRow();
    if (selectedRow >= 0) 
    {
        QString id = catalogTableWidget->item(selectedRow, 0)->text();
        int returnVal = CatalogDialog::createWarningDialog();
        
        if (returnVal == 0)
        {
            CatalogService service = new CatalogService();
            returnVal = service.deletePerson(id);
            if (returnVal == 1)
            {
                QMessageBox::critical(this, tr("Σφάλμα!"), "Αποτυχία διαγραφής του φακέλου.");
            }
            else if (returnVal == 2)
            {
                QMessageBox::critical(this, tr("Σφάλμα!"), "Ο επιλεγμένος φάκελος δεν υπάρχει στον κατάλογο.");
            }
            else if (returnVal == 0)
            {
                CatalogDialog::createSuccessDialog(id);
            }
        }
        else if (returnVal == 1) 
        {
            return;
        }
    }
    else 
    {
        QMessageBox::critical(this, tr("Σφάλμα!"), "Δεν έχετε επιλέξει κάποιο άτομο για διαγραφή.");
    }
    
}

int CatalogDialog::createWarningDialog()
{
    QMessageBox warningBox;
    warningBox.setWindowTitle("Επιβεβαίωση Διαγραφής");
    warningBox.setText("Όλα τα δεδομένα για το συγκεκριμένο άτομο θα διαγραφούν. Συνέχεια;");
    QPushButton* okButton = warningBox.addButton(tr("ΟΚ"), QMessageBox::AcceptRole);
    QPushButton* cancelButton = warningBox.addButton(tr("Ακύρωση"), QMessageBox::RejectRole);
    warningBox.setDefaultButton(okButton);
    warningBox.setIcon(QMessageBox::Warning);
    QIcon winIcon = QIcon("C:/Users/matdi/Documents/Argus/res/icons/id.png");
    warningBox.setWindowIcon(winIcon);
    warningBox.exec();

    if (warningBox.clickedButton() == okButton) 
    {
        return 0;
    }
    else if (warningBox.clickedButton() == cancelButton) 
    {
        return 1;
    }

    return 1;
}

void CatalogDialog::createSuccessDialog(QString id) const
{
    QMessageBox successBox;
    successBox.setWindowTitle("Επιτυχία.");
    successBox.setText("Ο φάκελος με αναγνωριστικο " + id + " διαγράφηκε.");
    QPixmap successIcon(":argus/res/dialog_icons/OK_DIALOG.png");
    successBox.setIconPixmap(successIcon);
    successBox.addButton(QMessageBox::Ok);
    QIcon winIcon = QIcon(":argus/res/app_icons/catalog.png");
    successBox.setWindowIcon(winIcon);
    successBox.exec();
}

void CatalogDialog::sortTable(int index)
{
    if (index == 0)
    {
        catalogTableWidget->sortByColumn(0, Qt::AscendingOrder);
    }
    else if (index == 1)
    {
        catalogTableWidget->sortByColumn(0, Qt::DescendingOrder);
    }
    else if (index == 2)
    {
        catalogTableWidget->sortByColumn(2, Qt::AscendingOrder);
    }
    else if (index == 3)
    {
        catalogTableWidget->sortByColumn(2, Qt::DescendingOrder);
    }
}

void CatalogDialog::filterTable(const QString& searchText)
{
    for (int row = 0; row < catalogTableWidget->rowCount(); ++row) 
    {
        bool rowVisible = false;
        for (int col = 0; col < catalogTableWidget->columnCount(); ++col) 
        {
            QTableWidgetItem* item = catalogTableWidget->item(row, col);
            if (item && item->text().contains(searchText, Qt::CaseInsensitive)) 
            {
                rowVisible = true;
                break;
            }
        }
        catalogTableWidget->setRowHidden(row, !rowVisible);
    }
}