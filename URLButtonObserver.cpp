#include "ModelConfigSourceURL.h"
#include <QUrl>
#include "URLButtonObserver.h"

using net::draconia::util::languageimporter::model::ModelConfigSourceURL;
using namespace net::draconia::util::languageimporter::observers;

QPushButton *URLButtonObserver::getOkButton()
{
    return(mBtnOk);
}

URLButtonObserver::URLButtonObserver(QPushButton *btnOk)
    :   Observer()
    ,   mBtnOk(btnOk)
{ }

void URLButtonObserver::update(Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    ModelConfigSourceURL &refModel = static_cast<ModelConfigSourceURL &>(refObservable);

    getOkButton()->setEnabled((!refModel.getURL().isEmpty()) && QUrl(refModel.getURL()).isValid());
}
