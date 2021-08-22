#pragma once

#include "Language.h"
#include <QList>
#include <QString>
#include <QVariant>

using net::draconia::util::languageimporter::model::Language;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace languageimporter
            {
                class Converter
                {
                    QString msName;
                public:
                    Converter();
                    Converter(const QString &sName);
                    Converter(const Converter &refCopy);
                    virtual ~Converter() = default;

                    QString &getName() const;
                    void setName(const QString &sName);

                    virtual QList<Language> convert(const QVariant &refValue) = 0;

                    QString toString() const;
                    operator QString() const;

                    Converter &operator=(const Converter &refCopy);
                    bool operator==(const Converter &refOther) const;
                    bool operator!=(const Converter &refOther) const;
                };
            }
        }
    }
}

Q_DECLARE_METATYPE(net::draconia::util::languageimporter::Converter *);
