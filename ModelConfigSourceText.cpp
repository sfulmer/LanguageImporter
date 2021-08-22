#include <any>
#include "ModelConfigSourceText.h"
#include "TextNullConverter.h"
#include "TextCSVConverter.h"

using namespace net::draconia::util::languageimporter::model;
using std::any;
using std::any_cast;

QList<Converter *> ModelConfigSourceText::msLstConverters({{new TextNullConverter(), new TextCSVConverter()}});

ModelConfigSourceText::ModelConfigSourceText()
    :   ModelConfigSource()
    ,   mPtrConverter(nullptr)
{ }

ModelConfigSourceText::ModelConfigSourceText(ModelConfigSourceText &refCopy)
    :   ModelConfigSource()
    ,   msText(refCopy.getText())
    ,   mPtrConverter(refCopy.mPtrConverter)
{ }

ModelConfigSourceText::~ModelConfigSourceText()
{
    if(mPtrConverter != nullptr)
        delete mPtrConverter;
}

Converter &ModelConfigSourceText::getConverter()
{
    if(mPtrConverter == nullptr)
        mPtrConverter = new TextNullConverter();
        //mPtrConverter = const_cast<Converter *>(&(getConverters()[0]));

    return(*mPtrConverter);
}

QString &ModelConfigSourceText::getText()
{
    return(msText);
}

void ModelConfigSourceText::setConverter(Converter &refConverter)
{
    mPtrConverter = &refConverter;
}

void ModelConfigSourceText::setText(const QString &sText)
{
    msText = sText;

    setChanged();
    notifyObservers("Text");
}

const QList<Converter *> &ModelConfigSourceText::getConverters()
{
    return(msLstConverters);
}

ModelConfigSourceText &ModelConfigSourceText::operator=(ModelConfigSourceText &refCopy)
{
    ModelConfigSource::operator=(refCopy);

    setText(refCopy.getText());

    return(*this);
}

bool ModelConfigSourceText::operator==(ModelConfigSourceText &refOther)
{
    return(ModelConfigSource::operator==(refOther) && (getText() == refOther.getText()));
}

bool ModelConfigSourceText::operator!=(ModelConfigSourceText &refOther)
{
    return(!operator==(refOther));
}
