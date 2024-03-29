#pragma once

#include <QList>
#include <QString>

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Observable;

            class Observer
            {
            public:
                virtual ~Observer() { }
                virtual void update(Observable &refObservable, const QString &sProperty) = 0;
            };

            class Observable
            {
                bool mbChanged;
                QList<Observer *> mLstObservers;
            protected:
                QList<Observer *> &getObserversInternal();
            public:
                Observable();
                ~Observable();

                void addObserver(const Observer *ptrObserver);
                const QList<Observer *> &getObservers();
                bool isChanged() const;
                void notifyObservers(const QString &sProperty);
                void setChanged(const bool bChanged = true);

                bool operator==(const Observable &objOther) const;
                bool operator!=(const Observable &objOther) const;
            };
        }
    }
}

