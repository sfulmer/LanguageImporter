#include "DataTableModel.h"

using namespace net::draconia::util::languageimporter::ui::model;

QList<Language> &DataTableModel::getModel() const
{
    return(mLstModel);
}

DataTableModel::DataTableModel(QList<Language> &refLanguage)
    :   QAbstractTableModel()
    ,   mLstModel(refLanguage)
{ }

int DataTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return(3);
}

QVariant DataTableModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);

    Language &refValue = getModel()[index.row()];

    switch(index.column())
        {
        case 0:
            return(refValue.getLanguage());
        case 1:
            return(refValue.getLocale());
        case 2:
            return(refValue.isUsed());
        default:
            return(QVariant());
        }
}

QVariant DataTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
        if(orientation == Qt::Horizontal)
            switch(section)
                {
                case 0:
                    return("Language");
                case 1:
                    return("Locale");
                case 2:
                    return("is Used?");
                }

    return(QAbstractTableModel::headerData(section, orientation, role));
}

int DataTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return(getModel().count());
}
