#include "DBPathObserver.h"
#include "ModelConfig.h"

using net::draconia::util::languageimporter::model::ModelConfig;
using namespace net::draconia::util::languageimporter::observers;

QLineEdit *DBPathObserver::getDBPathText() const
{
    return(mTxtDBPath);
}

void DBPathObserver::setDBPathText(QLineEdit *txtDBPath)
{
    mTxtDBPath = txtDBPath;
}

DBPathObserver::DBPathObserver(QLineEdit *txtDBPath)
    :   Observer()
    ,   mTxtDBPath(txtDBPath)
{ }

DBPathObserver::~DBPathObserver()
{ }

void DBPathObserver::update(Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    ModelConfig &refModel = static_cast<ModelConfig &>(refObservable);
    const QString &sText = getDBPathText()->text();

    if(refModel.getDatabasePath() != sText)
        getDBPathText()->setText(refModel.getDatabasePath());
}
