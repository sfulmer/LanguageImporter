#pragma once

#include <any>
#include "Converter.h"
#include "ModelConfigSource.h"
#include <QList>
#include <QString>

using net::draconia::util::languageimporter::Converter;
using std::any;

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
                        Converter *mPtrConverter;

                        static QList<Converter *> msLstConverters;
                    public:
                        ModelConfigSourceText();
                        ModelConfigSourceText(ModelConfigSourceText &refCopy);
                        virtual ~ModelConfigSourceText();

                        Converter &getConverter();
                        QString &getText();
                        void setConverter(Converter &refConverter);
                        void setText(const QString &sText);

                        static const QList<Converter *> &getConverters();

                        ModelConfigSourceText &operator=(ModelConfigSourceText &refCopy);
                        bool operator==(ModelConfigSourceText &refOther);
                        bool operator!=(ModelConfigSourceText &refOther);
                    };
                }
            }
        }
    }
}
