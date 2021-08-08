#pragma once

#include "ModelConfigSource.h"
#include <QString>

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace model
            {
                class ModelConfigSourceDatabase : public ModelConfigSource
                {
                    QString msDatabase, msDriver, msLanguageField, msLocaleField, msTable;
                public:
                    ModelConfigSourceDatabase();
                    ModelConfigSourceDatabase(const ModelConfigSourceDatabase &refCopy);
                    virtual ~ModelConfigSourceDatabase();

                    QString &getDatabase() const;
                    QString &getDriver() const;
                    QString &getLanguageField() const;
                    QString &getLocaleField() const;
                    QString &getTable() const;
                    void setDatabase(const QString &sDatabase);
                    void setDriver(const QString &sDriver);
                    void setLanguageField(const QString &sLanguage);
                    void setLocaleField(const QString &sLocale);
                    void setTable(const QString &sTable);

                    ModelConfigSourceDatabase &operator=(const ModelConfigSourceDatabase &refCopy);
                    bool operator==(const ModelConfigSourceDatabase &refOther) const;
                    bool operator!=(const ModelConfigSourceDatabase &refOther) const;
                };
            }
        }
    }
}
