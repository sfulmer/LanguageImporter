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
                    class ModelConfigSourceText : public ModelConfigSource
                    {
                        QString msText;
                    public:
                        ModelConfigSourceText();
                        ModelConfigSourceText(ModelConfigSourceText &refCopy);
                        virtual ~ModelConfigSourceText();

                        QString &getText();
                        void setText(const QString &sText);

                        ModelConfigSourceText &operator=(ModelConfigSourceText &refCopy);
                        bool operator==(ModelConfigSourceText &refOther);
                        bool operator!=(ModelConfigSourceText &refOther);
                    };
                }
            }
        }
    }
}
