#pragma once

#include "Observable.h"
#include <QNetworkAccessManager>
#include <QObject>

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
                    class URLSourceObserver : public QObject, public Observer
                    {
                        Q_OBJECT

                        QNetworkAccessManager *mPtrNAM;
                    protected:
                        QNetworkAccessManager *getNetworkAccessManager();
                        void NAMFinished(QNetworkReply *reply);
                    public:
                        URLSourceObserver();
                        ~URLSourceObserver() = default;
                        virtual void update(Observable &refObservable, const QString &sProperty);
                    };
                }
            }
        }
    }
}
