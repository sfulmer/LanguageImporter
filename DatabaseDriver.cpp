#include "DatabaseDriver.h"

using namespace net::draconia::util::languageimporter::model;

QList<DatabaseDriver> DatabaseDriver::msLstDrivers({{   DatabaseDriver("QDB2", "IBM DB2 (version 7.1 and above)")
                                                    ,   DatabaseDriver("QIBASE", "Borland InterBase")
                                                    ,   DatabaseDriver("QMYSQL", "MySQL or MariaDB (version 5.0 and above)")
                                                    ,   DatabaseDriver("QOCI", "Oracle Call Interface Driver")
                                                    ,   DatabaseDriver("QODBC", "Open Database Connectivity (ODBC) - Microsoft SQL Server and other ODBC-compliant databases")
                                                    ,   DatabaseDriver("QPSQL", "PostgreSQL (versions 7.3 and above)")
                                                    ,   DatabaseDriver("QSQLITE", "SQLite version 3")
                                                    }});

DatabaseDriver::DatabaseDriver()
    :   Observable()
{ }

DatabaseDriver::DatabaseDriver(const QString &sDriver, const QString &sName)
    :   Observable()
    ,   msDriver(sDriver)
    ,   msName(sName)
{ }

DatabaseDriver::DatabaseDriver(const DatabaseDriver &refCopy)
    :   DatabaseDriver(refCopy.getDriver(), refCopy.getName())
{ }

QString &DatabaseDriver::getDriver() const
{
    return(const_cast<DatabaseDriver &>(*this).msDriver);
}

QString &DatabaseDriver::getName() const
{
    return(const_cast<DatabaseDriver &>(*this).msName);
}

void DatabaseDriver::setDriver(const QString &sDriver)
{
    msDriver = sDriver;

    setChanged();
    notifyObservers("Driver");
}

void DatabaseDriver::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

DatabaseDriver &DatabaseDriver::operator=(const DatabaseDriver &refCopy)
{
    setDriver(refCopy.getDriver());
    setName(refCopy.getName());

    return(*this);
}

bool DatabaseDriver::operator==(const DatabaseDriver &refOther) const
{
    return  (   (getDriver() == refOther.getDriver())
            &&  (getName() == refOther.getName()));
}

bool DatabaseDriver::operator!=(const DatabaseDriver &refOther) const
{
    return(!operator==(refOther));
}

QString DatabaseDriver::toString() const
{
    return(getName());
}

DatabaseDriver::operator QString() const
{
    return(toString());
}

QList<DatabaseDriver> DatabaseDriver::getDrivers()
{
    return(msLstDrivers);
}
