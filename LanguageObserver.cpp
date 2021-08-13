#include "LanguageObserver.h"

using namespace net::draconia::util::languageimporter::observers;

QTableWidget *LanguageObserver::getLanguagesTable()
{
    return(mTblLanguages);
}

LanguageObserver::LanguageObserver(QTableWidget *tblWidget)
    :   Observer()
    ,   mTblLanguages(tblWidget)
{ }

void LanguageObserver::update(Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(refObservable);

    if(sProperty == "Languages")
        getLanguagesTable()->update();
}
