#include "TextCSVConverter.h"

using namespace net::draconia::util::languageimporter;

Converter::Converter()
{ }

Converter::Converter(const QString &sName)
    :   msName(sName)
{ }

Converter::Converter(const Converter &refCopy)
    :   msName(refCopy.getName())
{ }

QString &Converter::getName() const
{
    return(const_cast<Converter &>(*this).msName);
}

void Converter::setName(const QString &sName)
{
    msName = sName;
}

QString Converter::toString() const
{
    return(getName());
}

Converter::operator QString() const
{
    return(toString());
}

Converter &Converter::operator=(const Converter &refCopy)
{
    setName(refCopy.getName());

    return(*this);
}

bool Converter::operator==(const Converter &refOther) const
{
    return((getName() == refOther.getName()));
}

bool Converter::operator!=(const Converter &refOther) const
{
    return(!operator==(refOther));
}
