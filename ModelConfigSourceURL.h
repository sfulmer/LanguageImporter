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
                    class ModelConfigSourceURL : public ModelConfigSource
                    {
                        QString msEnding, msOpening, msURL;
                    public:
                        ModelConfigSourceURL();
                        ModelConfigSourceURL(ModelConfigSourceURL &refCopy);
                        virtual ~ModelConfigSourceURL();

                        QString &getEnding();
                        QString &getOpening();
                        QString &getURL();
                        void setEnding(const QString &sEnding);
                        void setOpening(const QString &sOpening);
                        void setURL(const QString &sURL);

                        ModelConfigSourceURL &operator=(ModelConfigSourceURL &refCopy);
                        bool operator==(ModelConfigSourceURL &refOther);
                        bool operator!=(ModelConfigSourceURL &refOther);
                    };
                }
            }
        }
    }
}
