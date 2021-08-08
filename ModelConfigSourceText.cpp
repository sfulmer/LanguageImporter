#include "ModelConfigSourceText.h"

using namespace net::draconia::util::model;

ModelConfigSourceText::ModelConfigSourceText()
    :   ModelConfigSource()
{ }

ModelConfigSourceText::ModelConfigSourceText(const ModelConfigSourceText &refCopy)
    :   ModelConfigSource()
    ,   msText(refCopy.getText())
{ }

ModelConfigSourceText::~ModelConfigSourceText()
{ }

QString &ModelConfigSourceText::getText() const
{
    return(const_cast<ModelConfigSourceText &>(*this).msText);
}

void ModelConfigSourceText::setText(const QString &sText)
{
    msText = sText;

    setChanged();
    notifyObservers("Text");
}

ModelConfigSourceText &ModelConfigSourceText::operator=(const ModelConfigSourceText &refCopy)
{
    ModelConfigSource::operator=(refCopy);

    setText(refCopy.getText());

    return(*this);
}

bool ModelConfigSourceText::operator==(const ModelConfigSourceText &refOther) const
{
    return(ModelConfigSource::operator==(refOther) && (getText() == refOther.getText()));
}

bool ModelConfigSourceText::operator!=(const ModelConfigSourceText &refOther) const
{
    return(!operator==(refOther));
}
