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
                class ModelConfigSourceText : public ModelConfigSource
                {
                    QString msText;
                public:
                    ModelConfigSourceText();
                    ModelConfigSourceText(const ModelConfigSourceText &refCopy);
                    virtual ~ModelConfigSourceText();

                    QString &getText() const;
                    void setText(const QString &sText);

                    ModelConfigSourceText &operator=(const ModelConfigSourceText &refCopy);
                    bool operator==(const ModelConfigSourceText &refOther) const;
                    bool operator!=(const ModelConfigSourceText &refOther) const;
                };
            }
        }
    }
}
