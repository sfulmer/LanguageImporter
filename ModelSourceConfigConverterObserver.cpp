#include "ModelConfigSourceText.h"
#include "ModelSourceConfigConverterObserver.h"

using net::draconia::util::languageimporter::model::ModelConfigSourceText;
using namespace net::draconia::util::languageimporter::observers;

QComboBox *ModelSourceConfigConverterObserver::getConverterComboBox() const
{
    return(mCboConverter);
}

ModelSourceConfigConverterObserver::ModelSourceConfigConverterObserver(QComboBox *cboConverter)
    :   Observer()
    ,   mCboConverter(cboConverter)
{ }

void ModelSourceConfigConverterObserver::update(Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);
    Q_UNUSED(refObservable);

   //ModelConfigSourceText &refModel = static_cast<ModelConfigSourceText &>(const_cast<Observable &>(refObservable));

   /*if(refModel.getConverters().indexOf(refModel.getConverter()) != getConverterComboBox()->currentIndex())
       getConverterComboBox()->setCurrentIndex(refModel.getConverters().indexOf(refModel.getConverter()));*/
}
