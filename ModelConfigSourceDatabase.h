#pragma once

#include "ModelConfigSource.h"
#include <QString>

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
                    class ModelConfigSourceDatabase : public ModelConfigSource
                    {
                        QString msDatabase, msDriver, msHost, msLanguageField, msLocaleField, msTable;
                    public:
                        ModelConfigSourceDatabase();
                        ModelConfigSourceDatabase(ModelConfigSourceDatabase &refCopy);
                        virtual ~ModelConfigSourceDatabase();

                        QString &getDatabase();
                        QString &getDriver();
                        QString &getHost();
                        QString &getLanguageField();
                        QString &getLocaleField();
                        QString &getTable();
                        void setDatabase(const QString &sDatabase);
                        void setDriver(const QString &sDriver);
                        void setHost(const QString &sHost);
                        void setLanguageField(const QString &sLanguage);
                        void setLocaleField(const QString &sLocale);
                        void setTable(const QString &sTable);

                        ModelConfigSourceDatabase &operator=(ModelConfigSourceDatabase &refCopy);
                        bool operator==(ModelConfigSourceDatabase &refOther);
                        bool operator!=(ModelConfigSourceDatabase &refOther);
                    };
                }
            }
        }
    }
}
