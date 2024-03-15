#include "catalogservice.h"

CatalogService::CatalogService(QObject* parent)
    : QObject(parent)
{
    QSettings settings("config.ini", QSettings::IniFormat);
    catalogFolderPath = settings.value("Save_Preferences/Catalog_Path").toString();

    if (isCatalogFolderEmpty())
    {
        CatalogService::setupFolder();
    }
}

CatalogService::~CatalogService()
{

}

void CatalogService::setupFolder()
{

    QString filePath = catalogFolderPath + "/catalog.txt";
    QFile file(filePath);

    if (file.exists()) 
    {
        qDebug() << "File already exists.";
        return;
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.close();
        qDebug() << "File created successfully.";
    }

    else
    {
        qDebug() << "Failed to create file.";
        emit folderSetupFailed("Failed to create file: " + file.errorString());
    }
}

bool CatalogService::isCatalogFolderEmpty()
{
    QDir directory(catalogFolderPath);
    QStringList entries = directory.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);
    return entries.isEmpty();
}

bool CatalogService::isDatasetFolderEmpty(QString id) const
{
    QString path = catalogFolderPath + "/" + id + "/dataset";
    QDir folder(path);
    QStringList entries = folder.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);
    return entries.isEmpty();
}

bool CatalogService::personExists(QString id)
{
    QFile file(catalogFolderPath + "/catalog.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        qDebug() << "Σφάλμα ανάγνωσης του αρχείου:" << file.errorString();
        return false;
    }

    QTextStream in(&file);

    while (!in.atEnd()) 
    {
        QString line = in.readLine();
        QStringList parts = line.split(" ");

        if (parts.size() >= 1 && parts[0] == id) 
        {
            file.close();
            // ID found.
            return true; 
        }
    }

    file.close();
    // ID not found.
    return false; 
}

int CatalogService::addPerson(QString name, QString surname, QString id, QDate dob, QString latinName, QString latinSurname, QString profilePicturePath) const
{
    // Append ID, name, and surname to id.txt.
    QFile catalogFile(catalogFolderPath + "/catalog.txt");
    if (!catalogFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) 
    {
        return 1;
    }
    QTextStream stream(&catalogFile);
    stream << id << " " << name << " " << surname << "\n";
    catalogFile.close();

    // Create folder named with ID and add a file with ID.txt.
    QString folderName = catalogFolderPath + "/" + id;
    QDir dir(folderName);
    if (!dir.exists()) 
    {
        if (!dir.mkpath(folderName)) 
        {
            qDebug() << "Αποτυχία δημιουργίας φακέλου:" << folderName;
            return 1;
        }
    }

    // Write the information to the ID.txt file.
    QString fileName = folderName + "/" + id + ".txt";
    QFile personFile(fileName);
    if (!personFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return 1;
    }
    QTextStream personStream(&personFile);
    personStream << name << "\n";
    personStream << surname << "\n";
    personStream << id << "\n";
    personStream << dob.toString("yyyy-MM-dd") << "\n";
    personStream << latinName << "\n";
    personStream << latinSurname << "\n";
    personStream << "No\n";
    personStream << "0\n";
    personStream << profilePicturePath;
    personFile.close();

    // Create empty folder named "dataset" in the person folder.
    QString datasetFolder = folderName + "/dataset";
    QDir datasetDir(datasetFolder);
    if (!datasetDir.exists()) 
    {
        datasetDir.mkpath(".");
    }

    // Copy the profile picture to the appropriate folder.
    QString destinationPath = folderName + "/" + QFileInfo(profilePicturePath).fileName();
    if (QFile::copy(profilePicturePath, destinationPath)) 
    {
        qDebug() << "Profile picture copied successfully to:" << destinationPath;
    }
    else 
    {
        qDebug() << "Failed to copy profile picture to:" << destinationPath;
    }

    CatalogService::sortCatalog(false, "0");
    return 0;
}

std::vector<QStringList> CatalogService::getAllEntries() const
{
    std::vector<QStringList> entries;

    // Open the catalog.txt file.
    std::ifstream file(catalogFolderPath.toStdString() + "/catalog.txt");
    if (!file.is_open()) 
    {
        // Return an empty vector.
        return entries; 
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        QStringList tokens = QString::fromStdString(line).split(' ');
        entries.push_back(tokens);
    }
    file.close();

    return entries;
}

QStringList CatalogService::getEntryData(QString id) const
{
    QStringList entryData;
    QString filePath = catalogFolderPath + "/" + id + "/" + id + ".txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        // File opening failed
        return entryData; // Return empty QStringList
    }

    QTextStream in(&file);

    while (!in.atEnd()) 
    {
        QString line = in.readLine();
        entryData.append(line);
    }

    // Close the file
    file.close();

    return entryData;
}

int CatalogService::deletePerson(QString id) const
{
    QString deletionPath = catalogFolderPath + "/" + id;
    // Check if the directory exists.
    if (QDir(deletionPath).exists()) 
    {
        // Create a QDir object for the directory.
        QDir directory(deletionPath);
        // Remove the directory and all its contents recursively.
        if (directory.removeRecursively()) 
        {
            CatalogService::sortCatalog(true, id);
            return 0;
        }
        else 
        {
            return 1;
        }
    }
    else 
    {
        return 2;
    }
}

void CatalogService::sortCatalog(bool deletionFlag, QString id) const
{
    // Get all entries from the catalog file.
    std::vector<QStringList> allEntries = getAllEntries();
    int allEntriesSize = static_cast<int>(allEntries.size()); // Convert size_t to int.

    // If deletionFlag is true and id is not "0", remove the entry with the specified id.
    if (deletionFlag && id != "0")
    {
        auto iterator = std::find_if(allEntries.begin(), allEntries.end(), [id](const QStringList& entry)
            {
                return !entry.isEmpty() && entry[0] == id;
            });
        if (iterator != allEntries.end())
        {
            // Calculate the position of the item and erase it.
            int pos = std::distance(allEntries.begin(), iterator);
            allEntries.erase(allEntries.begin() + pos);
            // Refreshing the size variable so it doesn't go out of bounds after deletion.
            allEntriesSize = static_cast<int>(allEntries.size());
        }
        else
        {
            return; // Entry not found, nothing to delete.
        }
    }

    // Sort the entries based on the ID (assuming the ID is the first element in each QStringList).
    for (int i = 0; i < allEntriesSize; ++i)
    {
        for (int j = 0; j < allEntriesSize - 1; ++j)
        {
            if (allEntries[j][0] > allEntries[j + 1][0])
            {
                std::swap(allEntries[j], allEntries[j + 1]);
            }
        }
    }

    // Write the sorted entries back to the catalog file.
    QFile catalogFile(catalogFolderPath + "/catalog.txt");
    if (!catalogFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return; // Unable to open the file for writing.
    }

    QTextStream stream(&catalogFile);
    for (const QStringList& entry : allEntries)
    {
        for (const QString& str : entry)
        {
            stream << str << " ";
        }
        stream << "\n";
    }

    catalogFile.close();
}

std::vector<QStringList> CatalogService::getDataset(QString id) const
{
    QStringList fileInfo;
    std::vector<QStringList> fileInfoList;
    QString path = catalogFolderPath + "/" + id + "/dataset";
    QDir directory(path);

    if (directory.exists()) 
    {
        QStringList fileNames = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);
        for (const QString& fileName : fileNames) 
        {
            QFileInfo file(path + "/" + fileName);
            QImage image(path + "/" + fileName);
            QStringList fileInfo;
            fileInfo << fileName
                << QString::number(file.size()) + " byte(s)"
                << QString::number(image.width()) + "x" + QString::number(image.height());
            fileInfoList.push_back(fileInfo);
        }
    }

    return fileInfoList;
}

void CatalogService::addPicturesToDataset(QStringList fileList, QString id)
{
    QStringList fileInfo;
    QString path = catalogFolderPath + "/" + id + "/dataset";
    QDir directory(path);

    for (const QString& filePath : fileList) 
    {
        QFileInfo fileInfo(filePath);
        QString destinationFilePath = path + "/" + fileInfo.fileName();
        QFile::copy(filePath, destinationFilePath);
    }
}

void CatalogService::deletePicturesFromDataset(QString fileName, QString id)
{

}