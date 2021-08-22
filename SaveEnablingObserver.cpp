#include "Model.h"
#include "SaveEnablingObserver.h"

using net::draconia::util::languageimporter::model::Model;
using namespace net::draconia::util::languageimporter::observers;

QPushButton *SaveEnablingObserver::getSaveButton() const
{
    return(mBtnSave);
}

SaveEnablingObserver::SaveEnablingObserver(QPushButton *btnSave)
    :   mBtnSave(btnSave)
{ }

void SaveEnablingObserver::update(Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    Model &refModel = static_cast<Model &>(refObservable);

    getSaveButton()->setDisabled(refModel.getLanguages().isEmpty());
}
