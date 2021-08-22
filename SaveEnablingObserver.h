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
                    class SaveEnablingObserver : public Observer
                    {
                        QPushButton *mBtnSave;
                    protected:
                        QPushButton *getSaveButton() const;
                    public:
                        SaveEnablingObserver(QPushButton *btnSave);
                        ~SaveEnablingObserver() = default;

                        virtual void update(Observable &refObservable, const QString &sProperty);
                    };
                }
            }
        }
    }
}
