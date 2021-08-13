#pragma once

#include "Observable.h"
#include <QLineEdit>

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
                    class DBPathObserver : public Observer
                    {
                        QLineEdit *mTxtDBPath;
                    protected:
                        QLineEdit *getDBPathText() const;
                        void setDBPathText(QLineEdit *txtDBPath);
                    public:
                        DBPathObserver(QLineEdit *txtDBPath);
                        virtual ~DBPathObserver();

                        virtual void update(Observable &refObservable, const QString &refProperty);
                    };
                }
            }
        }
    }
}
