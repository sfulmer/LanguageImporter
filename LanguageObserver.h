#pragma once

#include "Observable.h"
#include <QTableWidget>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace languageimporter
            {
                namespace observers
                {
                    class LanguageObserver : public Observer
                    {
                        QTableWidget *mTblLanguages;
                    protected:
                        QTableWidget *getLanguagesTable();
                    public:
                        LanguageObserver(QTableWidget *tblWidget);
                        ~LanguageObserver() = default;

                        virtual void update(Observable &refObservable, const QString &sProperty);
                    };
                }
            }
        }
    }
}
