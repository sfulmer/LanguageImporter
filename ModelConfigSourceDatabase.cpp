#include "ModelConfigSourceDatabase.h"

using namespace net::draconia::util::model;

ModelConfigSourceDatabase::ModelConfigSourceDatabase()
    :   ModelConfigSource()
{ }

ModelConfigSourceDatabase::ModelConfigSourceDatabase(const ModelConfigSourceDatabase &refCopy)
    :   ModelConfigSource()
    ,   msDatabase(refCopy.getDatabase())
    ,   msDriver(refCopy.getDriver())
    ,   msLanguageField(refCopy.getLanguageField())
    ,   msLocaleField(refCopy.getLocaleField())
    ,   msTable(refCopy.getTable())
{ }

ModelConfigSourceDatabase::~ModelConfigSourceDatabase()
{ }

QString &ModelConfigSourceDatabase::getDatabase() const
{
    return(const_cast<ModelConfigSourceDatabase &>(*this).msDatabase);
}

QString &ModelConfigSourceDatabase::getDriver() const
{
    return(const_cast<ModelConfigSourceDatabase &>(*this).msDriver);
}

QString &ModelConfigSourceDatabase::getLanguageField() const
{
    return(const_cast<ModelConfigSourceDatabase &>(*this).msLanguageField);
}

QString &ModelConfigSourceDatabase::getLocaleField() const
{
    return(const_cast<ModelConfigSourceDatabase &>(*this).msLocaleField);
}

QString &ModelConfigSourceDatabase::getTable() const
{
    return(const_cast<ModelConfigSourceDatabase &>(*this).msTable);
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

ModelConfigSourceDatabase &ModelConfigSourceDatabase::operator=(const ModelConfigSourceDatabase &refCopy)
{
    ModelConfigSource::operator=(refCopy);

    setDatabase(refCopy.getDatabase());
    setDriver(refCopy.getDriver());
    setLanguageField(refCopy.getLanguageField());
    setLocaleField(refCopy.getLocaleField());
    setTable(refCopy.getTable());

    return(*this);
}

bool ModelConfigSourceDatabase::operator==(const ModelConfigSourceDatabase &refOther) const
{
    return  (   (getDatabase() == refOther.getDatabase())
            &&  (getDriver() == refOther.getDriver())
            &&  (getLanguageField() == refOther.getLanguageField())
            &&  (getLocaleField() == refOther.getLocaleField())
            &&  (getTable() == refOther.getTable()));
}

bool ModelConfigSourceDatabase::operator!=(const ModelConfigSourceDatabase &refOther) const
{
    return(!operator==(refOther));
}
