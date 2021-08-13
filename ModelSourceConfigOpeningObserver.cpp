#include "ModelConfigSourceURL.h"
#include "ModelSourceConfigOpeningObserver.h"

using net::draconia::util::languageimporter::model::ModelConfigSourceURL;
using namespace net::draconia::util::languageimporter::observers;

QTextEdit *ModelSourceConfigOpeningObserver::getOpeningText()
{
    return(mTxtOpening);
}

void ModelSourceConfigOpeningObserver::setOpeningText(QTextEdit *txtOpening)
{
    mTxtOpening = txtOpening;
}

ModelSourceConfigOpeningObserver::ModelSourceConfigOpeningObserver(QTextEdit *txtOpening)
    :   Observer()
    ,   mTxtOpening(txtOpening)
{ }

void ModelSourceConfigOpeningObserver::update(Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    ModelConfigSourceURL &refModel = static_cast<ModelConfigSourceURL &>(refObservable);
    const QString &sText = getOpeningText()->toPlainText();

    if(refModel.getOpening() != sText)
        getOpeningText()->setText(sText);
}
