#pragma once

#include "Observable.h"
#include <QLineEdit>

using net::draconia::util::Observable;
using net::draconia::util::Observer;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace observers
            {
                class DBPathObserver : public Observer
                {
                    QLineEdit *mTxtDBPath;
                protected:
                    QLineEdit *getDBPathText() const;
                    void setDBPathText(const QLineEdit *txtDBPath);
                public:
                    DBPathObserver(const QLineEdit *txtDBPath);
                    virtual ~DBPathObserver();

                    virtual void update(const Observable &refObservable, const QString &refProperty);
                };
            }
        }
    }
}
