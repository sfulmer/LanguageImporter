#include "ModelConfigSourceDatabase.h"

using namespace net::draconia::util::languageimporter::model;

ModelConfigSourceDatabase::ModelConfigSourceDatabase()
    :   ModelConfigSource()
{ }

ModelConfigSourceDatabase::ModelConfigSourceDatabase(ModelConfigSourceDatabase &refCopy)
    :   ModelConfigSource()
    ,   msDatabase(refCopy.getDatabase())
    ,   msDriver(refCopy.getDriver())
    ,   msHost(refCopy.getHost())
    ,   msLanguageField(refCopy.getLanguageField())
    ,   msLocaleField(refCopy.getLocaleField())
    ,   msTable(refCopy.getTable())
{ }

ModelConfigSourceDatabase::~ModelConfigSourceDatabase()
{ }

QString &ModelConfigSourceDatabase::getDatabase()
{
    return(msDatabase);
}

QString &ModelConfigSourceDatabase::getDriver()
{
    return(msDriver);
}

QString &ModelConfigSourceDatabase::getHost()
{
    return(msHost);
}

QString &ModelConfigSourceDatabase::getLanguageField()
{
    return(msLanguageField);
}

QString &ModelConfigSourceDatabase::getLocaleField()
{
    return(msLocaleField);
}

QString &ModelConfigSourceDatabase::getTable()
{
    return(msTable);
}

void ModelConfigSourceDatabase::setDatabase(const QString &sDatabase)
{
    msDatabase = sDatabase;

    setChanged();
    notifyObservers("Database");
}

void ModelConfigSourceDatabase::setDriver(const QString &sDriver)
{
    msDriver = sDriver;

    setChanged();
    notifyObservers("Driver");
}

void ModelConfigSourceDatabase::setHost(const QString &sHost)
{
    msHost = sHost;

    setChanged();
    notifyObservers("Host");
}

void ModelConfigSourceDatabase::setLanguageField(const QString &sLanguage)
{
    msLanguageField = sLanguage;

    setChanged();
    notifyObservers("LanguageField");
}

void ModelConfigSourceDatabase::setLocaleField(const QString &sLocale)
{
    msLocaleField = sLocale;

    setChanged();
    notifyObservers("LocaleField");
}

void ModelConfigSourceDatabase::setTable(const QString &sTable)
{
    msTable = sTable;

    setChanged();
    notifyObservers("Table");
}

ModelConfigSourceDatabase &ModelConfigSourceDatabase::operator=(ModelConfigSourceDatabase &refCopy)
{
    ModelConfigSource::operator=(refCopy);

    setDatabase(refCopy.getDatabase());
    setDriver(refCopy.getDriver());
    setLanguageField(refCopy.getLanguageField());
    setLocaleField(refCopy.getLocaleField());
    setTable(refCopy.getTable());

    return(*this);
}

bool ModelConfigSourceDatabase::operator==(ModelConfigSourceDatabase &refOther)
{
    return  (   (getDatabase() == refOther.getDatabase())
            &&  (getDriver() == refOther.getDriver())
            &&  (getLanguageField() == refOther.getLanguageField())
            &&  (getLocaleField() == refOther.getLocaleField())
            &&  (getTable() == refOther.getTable()));
}

bool ModelConfigSourceDatabase::operator!=(ModelConfigSourceDatabase &refOther)
{
    return(!operator==(refOther));
}
