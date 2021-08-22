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
                    class ModelSourceConfigTextObserver : public Observer
                    {
                        QTextEdit *mTxtText;
                    protected:
                        QTextEdit *getTextEdit() const;
                    public:
                        ModelSourceConfigTextObserver(QTextEdit *txtEdit);
                        ~ModelSourceConfigTextObserver() = default;

                        virtual void update(Observable &refObservable, const QString &sProperty);
                    };
                }
            }
        }
    }
}
