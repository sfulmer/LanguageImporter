#pragma once

#include "Observable.h"
#include <QPushButton>

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
                    class URLButtonObserver : public Observer
                    {
                        QPushButton *mBtnOk;
                    protected:
                        QPushButton *getOkButton();
                    public:
                        URLButtonObserver(QPushButton *btnOk);
                        ~URLButtonObserver() = default;

                        virtual void update(Observable &refObservable, const QString &sProperty);
                    };
                }
            }
        }
    }
}
