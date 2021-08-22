#include "ModelConfigSourceText.h"
#include "ModelSourceConfigTextObserver.h"

using net::draconia::util::languageimporter::model::ModelConfigSourceText;
using namespace net::draconia::util::languageimporter::observers;

QTextEdit *ModelSourceConfigTextObserver::getTextEdit() const
{
    return(mTxtText);
}

ModelSourceConfigTextObserver::ModelSourceConfigTextObserver(QTextEdit *txtEdit)
    :   Observer()
    ,   mTxtText(txtEdit)
{ }

void ModelSourceConfigTextObserver::update(Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    ModelConfigSourceText &refModel = static_cast<ModelConfigSourceText &>(refObservable);

    if(refModel.getText() != getTextEdit()->toPlainText())
        getTextEdit()->setText(refModel.getText());
}
