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
                class ModelConfigSourceURL : public ModelConfigSource
                {
                    QString msEnding, msOpening, msURL;
                public:
                    ModelConfigSourceURL();
                    ModelConfigSourceURL(const ModelConfigSourceURL &refCopy);
                    virtual ~ModelConfigSourceURL();

                    QString &getEnding() const;
                    QString &getOpening() const;
                    QString &getURL() const;
                    void setEnding(const QString &sEnding);
                    void setOpening(const QString &sOpening);
                    void setURL(const QString &sURL);

                    ModelConfigSourceURL &operator=(const ModelConfigSourceURL &refCopy);
                    bool operator==(const ModelConfigSourceURL &refOther) const;
                    bool operator!=(const ModelConfigSourceURL &refOther) const;
                };
            }
        }
    }
}
