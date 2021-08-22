#include "TextCSVConverter.h"

using namespace net::draconia::util::languageimporter;

TextCSVConverter::TextCSVConverter()
    :   Converter("CSV")
{ }

QList<Language> TextCSVConverter::convert(const QVariant &refValue)
{
    Q_UNUSED(refValue);

    return(QList<Language>());
}
