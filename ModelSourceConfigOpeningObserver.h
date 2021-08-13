#pragma once

#include "Observable.h"
#include <QTextEdit>

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
                    class ModelSourceConfigOpeningObserver : public Observer
                    {
                        QTextEdit *mTxtOpening;
                    protected:
                        QTextEdit *getOpeningText();
                        void setOpeningText(QTextEdit *txtOpening);
                    public:
                        ModelSourceConfigOpeningObserver(QTextEdit *txtOpening);
                        ~ModelSourceConfigOpeningObserver() = default;

                        virtual void update(Observable &reObservable, const QString &sProperty);
                    };
                }
            }
        }
    }
}
