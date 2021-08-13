#include "ModelConfigSourceURL.h"
#include "ModelSourceConfigURLObserver.h"

using net::draconia::util::languageimporter::model::ModelConfigSourceURL;
using namespace net::draconia::util::languageimporter::observers;

QLineEdit *ModelSourceConfigURLObserver::getURLText()
{
    return(mTxtURL);
}

void ModelSourceConfigURLObserver::setURLText(QLineEdit *txtURL)
{
    mTxtURL = txtURL;
}

ModelSourceConfigURLObserver::ModelSourceConfigURLObserver(QLineEdit *txtURL)
    :   Observer()
    ,   mTxtURL(txtURL)
{ }

void ModelSourceConfigURLObserver::update(Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    ModelConfigSourceURL &refModel = static_cast<ModelConfigSourceURL &>(refObservable);
    QString sText = getURLText()->text();

    if(refModel.getURL() != sText)
        getURLText()->setText(refModel.getURL());
}
