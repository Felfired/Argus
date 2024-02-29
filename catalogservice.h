#ifndef CATALOGSERVICE_H
#define CATALOGSERVICE_H

#include <QObject>
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

signals:
	void folderSetupFailed(const QString& errorMessage);

private slots:
	void setupFolder();
	bool isFolderEmpty();
	void sortCatalog(bool deletionFlag, QString id) const;
	
private:
	QString catalogFolderPath;
};

#endif // CATALOGSERVICE_H
