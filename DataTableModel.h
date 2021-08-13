#pragma once

#include "Language.h"
#include <QAbstractTableModel>
#include <QList>

using net::draconia::util::languageimporter::model::Language;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace languageimporter
            {
                namespace ui
                {
                    namespace model
                    {
                        class DataTableModel : public QAbstractTableModel
                        {
                            QList<Language> &mLstModel;
                        protected:
                            QList<Language> &getModel() const;
                        public:
                            DataTableModel(QList<Language> &refLanguages);
                            virtual int columnCount(const QModelIndex &parent) const;
                            virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
                            virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
                            virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
                        };
                    }
                }
            }
        }
    }
}
