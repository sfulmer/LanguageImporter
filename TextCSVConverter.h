#pragma once

#include "Converter.h"
#include <QString>

namespace net
{
    namespace draconia
    {
            namespace util
            {
                namespace languageimporter
                {
                    class TextCSVConverter : public Converter
                    {
                    public:
                        TextCSVConverter();
                        virtual ~TextCSVConverter() = default;

                        virtual QList<Language> convert(const QVariant &refValue);
                    };
                }
            }
    }
}

Q_DECLARE_METATYPE(net::draconia::util::languageimporter::TextCSVConverter);
