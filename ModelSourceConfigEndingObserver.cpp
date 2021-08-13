#include "ModelSourceConfigEndingObserver.h"
#include "ModelConfigSourceURL.h"

using net::draconia::util::languageimporter::model::ModelConfigSourceURL;
using namespace net::draconia::util::languageimporter::observers;

QTextEdit *ModelSourceConfigEndingObserver::getEndingText()
{
    return(mTxtEnding);
}

void ModelSourceConfigEndingObserver::setEndingText(QTextEdit *txtEnding)
{
    mTxtEnding = txtEnding;
}

ModelSourceConfigEndingObserver::ModelSourceConfigEndingObserver(QTextEdit *txtEnding)
    :   Observer()
    ,   mTxtEnding(txtEnding)
{ }

void ModelSourceConfigEndingObserver::update(Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    ModelConfigSourceURL &refModel = static_cast<ModelConfigSourceURL &>(refObservable);
    QString sText = getEndingText()->toPlainText();

    if(refModel.getEnding() != sText)
        getEndingText()->setText(refModel.getEnding());
}
