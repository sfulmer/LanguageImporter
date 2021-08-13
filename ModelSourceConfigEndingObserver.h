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
                    class ModelSourceConfigEndingObserver : public Observer
                    {
                        QTextEdit *mTxtEnding;
                    protected:
                        QTextEdit *getEndingText();
                        void setEndingText(QTextEdit *txtEnding);
                    public:
                        ModelSourceConfigEndingObserver(QTextEdit *txtEnding);
                        ~ModelSourceConfigEndingObserver() = default;

                        virtual void update(Observable &refObservable, const QString &sProperty);
                    };
                }
            }
        }
    }
}
