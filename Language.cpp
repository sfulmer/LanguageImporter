#include "Language.h"

using namespace net::draconia::util::model;

Language::Language()
    :  Observable()
{ }

Language::Language(const QString &sLanguage, const QString &sLocale)
    :   Observable()
    ,   msLanguage(sLanguage)
    ,   msLocale(sLocale)
{ }

Language::Language(const Language &refCopy)
    :   Language(refCopy.getLanguage(), refCopy.getLocale())
{ }

Language::~Language()
{ }

QString &Language::getLanguage() const
{
    return(const_cast<Language &>(*this).msLanguage);
}

QString &Language::getLocale() const
{
    return(const_cast<Language &>(*this).msLocale);
}

void Language::setLanguage(const QString &sLanguage)
{
    msLanguage = sLanguage;

    setChanged();
    notifyObservers("Language");
}

void Language::setLocale(const QString &sLocale)
{
    msLocale = sLocale;

    setChanged();
    notifyObservers("Locale");
}

Language &Language::operator=(const Language &refCopy)
{
    setLanguage(refCopy.getLanguage());
    setLocale(refCopy.getLocale());

    return(*this);
}

bool Language::operator==(const Language &refOther) const
{
    return  (   (getLanguage() == refOther.getLanguage())
            &&  (getLocale() == refOther.getLocale()));
}

bool Language::operator!=(const Language &refOther) const
{
    return(!operator==(refOther));
}

QString Language::toString() const
{
    return(getLanguage() + "(" + getLocale() + ")");
}

Language::operator QString() const
{
    return(toString());
}
