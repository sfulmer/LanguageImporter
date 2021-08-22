#pragma once

#include "Observable.h"
#include <QList>
#include <QString>
#include <QVariant>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace languageimporter
            {
                namespace model
                {
                    class DatabaseDriver : public Observable
                    {
                        QString msDriver, msName;

                        static QList<DatabaseDriver> msLstDrivers;
                    public:
                        DatabaseDriver();
                        DatabaseDriver(const QString &sDriver, const QString &sName);
                        DatabaseDriver(const DatabaseDriver &refCopy);
                        ~DatabaseDriver() = default;

                        QString &getDriver() const;
                        QString &getName() const;
                        void setDriver(const QString &sDriver);
                        void setName(const QString &sName);

                        DatabaseDriver &operator=(const DatabaseDriver &refCopy);
                        bool operator==(const DatabaseDriver &refOther) const;
                        bool operator!=(const DatabaseDriver &refOther) const;

                        QString toString() const;
                        operator QString() const;

                        static QList<DatabaseDriver> getDrivers();
                    };
                }
            }
        }
    }
}

Q_DECLARE_METATYPE(net::draconia::util::languageimporter::model::DatabaseDriver);
