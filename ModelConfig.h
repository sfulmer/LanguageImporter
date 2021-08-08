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
            namespace model
            {
                class ModelConfig : public Observable
                {
                    ModelConfigSource *mPtrSourceConfig;
                    QString msDBPath, msSource;
                protected:
                    void setSourceConfig(const ModelConfigSource *ptrSourceConfig);
                public:
                    ModelConfig();
                    ModelConfig(const ModelConfig &refCopy);
                    ~ModelConfig();

                    QString &getDatabasePath() const;
                    QString &getSource() const;
                    ModelConfigSource &getSourceConfig();
                    void setDatabasePath(const QString sDBPath);
                    void setSource(const QString &sSource);

                    ModelConfig &operator=(const ModelConfig &refCopy);
                    bool operator==(const ModelConfig &refOther) const;
                    bool operator!=(const ModelConfig &refOther) const;
                };
            }
        }
    }
}
