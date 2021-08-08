#include "DBPathObserver.h"
#include "ModelConfig.h"

using net::draconia::util::model::ModelConfig;
using namespace net::draconia::util::observers;

QLineEdit *DBPathObserver::getDBPathText() const
{
    return(mTxtDBPath);
}

void DBPathObserver::setDBPathText(const QLineEdit *txtDBPath)
{
    mTxtDBPath = const_cast<QLineEdit *>(txtDBPath);
}

DBPathObserver::DBPathObserver(const QLineEdit *txtDBPath)
    :   Observer()
    ,   mTxtDBPath(const_cast<QLineEdit *>(txtDBPath))
{ }

DBPathObserver::~DBPathObserver()
{ }

void DBPathObserver::update(const Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    ModelConfig &refModel = static_cast<ModelConfig &>(const_cast<Observable &>(refObservable));
    const QString &sText = getDBPathText()->text();

    if(refModel.getDatabasePath() != sText)
        getDBPathText()->setText(refModel.getDatabasePath());
}
