#include "Language.h"

using namespace net::draconia::util::languageimporter::model;

Language::Language()
    :  Observable()
{ }

Language::Language(const QString &sLanguage, const QString &sLocale)
    :   Observable()
    ,   msLanguage(sLanguage)
    ,   msLocale(sLocale)
{ }

Language::Language(const Language &refCopy)
    :   Language(const_cast<Language &>(refCopy).getLanguage(), const_cast<Language &>(refCopy).getLocale())
{ }

Language::Language(Language &refMove)
    :   Language(refMove.getLanguage(), refMove.getLocale())
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

bool Language::isUsed() const
{
    return(mbUsed);
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

void Language::setUsed(const bool bUsed)
{
    mbUsed = bUsed;

    setChanged();
    notifyObservers("Used");
}

Language &Language::operator=(const Language &refCopy)
{
    setLanguage(const_cast<Language &>(refCopy).getLanguage());
    setLocale(const_cast<Language &>(refCopy).getLocale());

    return(*this);
}

Language &Language::operator=(Language &refMove)
{
    setLanguage(refMove.getLanguage());
    setLocale(refMove.getLocale());

    return(*this);
}

bool Language::operator==(const Language &refOther) const
{
    Language &refThis = const_cast<Language &>(*this);

    return  (   (refThis.getLanguage() == const_cast<Language &>(refOther).getLanguage())
            &&  (refThis.getLocale() == const_cast<Language &>(refOther).getLocale()));
}

bool Language::operator!=(const Language &refOther) const
{
    return(!operator==(refOther));
}

QString Language::toString()
{
    return(getLanguage() + "(" + getLocale() + ")");
}

Language::operator QString()
{
    return(toString());
}
