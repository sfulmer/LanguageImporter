#pragma once

#include "ModelConfigSource.h"
#include "Observable.h"
#include <QString>

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
                    class ModelConfig : public Observable
                    {
                        ModelConfigSource *mPtrSourceConfig;
                        QString msDBPath, msSource;
                    protected:
                        void setSourceConfig(ModelConfigSource *ptrSourceConfig);
                    public:
                        ModelConfig();
                        ModelConfig(const ModelConfig &refCopy);
                        ~ModelConfig();

                        QString &getDatabasePath();
                        QString &getSource();
                        ModelConfigSource &getSourceConfig();
                        void setDatabasePath(QString sDBPath);
                        void setSource(const QString &sSource);

                        ModelConfig &operator=(ModelConfig &refCopy);
                        bool operator==(ModelConfig &refOther);
                        bool operator!=(ModelConfig &refOther);
                    };
                }
            }
        }
    }
}
