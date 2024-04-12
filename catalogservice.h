#ifndef CATALOGSERVICE_H
#define CATALOGSERVICE_H

#include <QObject>
#include <QDir>
#include <QTextStream>
#include <QSettings>
#include <QStringList>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class CatalogService : public QObject
{
	Q_OBJECT
		
public:
	CatalogService(QObject* parent = nullptr);
	~CatalogService();
	int addPerson(QString name, QString surname, QString id, QDate dob, QString latinName, QString latinSurname, QString profilePicturePath) const;
	bool personExists(QString id);
	std::vector<QStringList> getAllEntries() const;
	QStringList getEntryData(QString id) const;
	int deletePerson(QString id) const;
	std::vector<QStringList> getDataset(QString id) const;
	bool isCatalogFolderEmpty();
	bool isDatasetFolderEmpty(QString id) const;
	void addPicturesToDataset(QStringList fileList, QString id);
	int deletePicturesFromDataset(QString fileName);
	int createDatasetIndex();

signals:
	void folderSetupFailed(const QString& errorMessage);

private slots:
	void setupFolder();
	void sortCatalog(bool deletionFlag, QString id) const;
	void createIndexRecursive(const QDir& currentDirectory, QTextStream& outputStream, const QString& parentFolderPath);
	
private:
	QString catalogFolderPath;
	QString indexPath;
};

#endif // CATALOGSERVICE_H
