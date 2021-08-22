#include "TextNullConverter.h"

using namespace net::draconia::util::languageimporter;

TextNullConverter::TextNullConverter()
    :   Converter("Select a Conversion...")
{ }

QList<Language> TextNullConverter::convert(const QVariant &refValue)
{
    Q_UNUSED(refValue);

    return(QList<Language>());
}
