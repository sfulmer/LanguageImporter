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
                    class TextNullConverter : public Converter
                    {
                    public:
                        TextNullConverter();
                        virtual ~TextNullConverter() = default;

                        virtual QList<Language> convert(const QVariant &refValue);
                    };
                }
            }
    }
}

Q_DECLARE_METATYPE(net::draconia::util::languageimporter::TextNullConverter);
