#include "ModelConfigSourceText.h"

using namespace net::draconia::util::languageimporter::model;

ModelConfigSourceText::ModelConfigSourceText()
    :   ModelConfigSource()
{ }

ModelConfigSourceText::ModelConfigSourceText(ModelConfigSourceText &refCopy)
    :   ModelConfigSource()
    ,   msText(refCopy.getText())
{ }

ModelConfigSourceText::~ModelConfigSourceText()
{ }

QString &ModelConfigSourceText::getText()
{
    return(msText);
}

void ModelConfigSourceText::setText(const QString &sText)
{
    msText = sText;

    setChanged();
    notifyObservers("Text");
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
