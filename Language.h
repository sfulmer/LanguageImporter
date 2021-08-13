#pragma once

#include "Observable.h"
#include <QString>
#include <QVariant>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace languageimporter
            {
                namespace model
                {
                    class Language : public Observable
                    {
                        bool mbUsed;
                        QString msLanguage, msLocale;
                    public:
                        Language();
                        Language(const QString &sLanguage, const QString &sLocale);
                        Language(const Language &refCopy);
                        Language(Language &refMove);
                        ~Language();

                        QString &getLanguage() const;
                        QString &getLocale() const;
                        bool isUsed() const;
                        void setLanguage(const QString &sLanguage);
                        void setLocale(const QString &sLocale);
                        void setUsed(const bool bUsed);

                        Language &operator=(const Language &refCopy);
                        Language &operator=(Language &refCopy);
                        bool operator==(const Language &refOther) const;
                        bool operator!=(const Language &refOther) const;

                        QString toString();
                        operator QString();
                    };
                }
            }
        }
    }
}

Q_DECLARE_METATYPE(net::draconia::util::languageimporter::model::Language);
