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
                    class ModelSourceConfigURLObserver : public Observer
                    {
                        QLineEdit *mTxtURL;
                    protected:
                        QLineEdit *getURLText();
                        void setURLText(QLineEdit *txtURL);
                    public:
                        ModelSourceConfigURLObserver(QLineEdit *txtURL);
                        ~ModelSourceConfigURLObserver() = default;

                        virtual void update(Observable &reObservable, const QString &sProperty);
                    };
                }
            }
        }
    }
}
