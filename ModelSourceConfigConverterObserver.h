#pragma once

#include "Observable.h"
#include <QComboBox>

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
                    class ModelSourceConfigConverterObserver : public Observer
                    {
                        QComboBox *mCboConverter;
                    protected:
                        QComboBox *getConverterComboBox() const;
                    public:
                        ModelSourceConfigConverterObserver(QComboBox *cboConverter);
                        ~ModelSourceConfigConverterObserver() = default;

                        virtual void update(Observable &refObservable, const QString &sProperty);
                    };
                }
            }
        }
    }
}
