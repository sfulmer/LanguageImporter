#include "ModelConfigSourceURL.h"

using namespace net::draconia::util::model;

ModelConfigSourceURL::ModelConfigSourceURL()
    :   ModelConfigSource()
{ }

ModelConfigSourceURL::ModelConfigSourceURL(const ModelConfigSourceURL &refCopy)
    :   ModelConfigSource()
    ,   msEnding(refCopy.getEnding())
    ,   msOpening(refCopy.getOpening())
    ,   msURL(refCopy.getURL())
{ }

ModelConfigSourceURL::~ModelConfigSourceURL()
{ }

QString &ModelConfigSourceURL::getEnding() const
{
    return(const_cast<ModelConfigSourceURL &>(*this).msEnding);
}

QString &ModelConfigSourceURL::getOpening() const
{
    return(const_cast<ModelConfigSourceURL &>(*this).msOpening);
}

QString &ModelConfigSourceURL::getURL() const
{
    return(const_cast<ModelConfigSourceURL &>(*this).msURL);
}

void ModelConfigSourceURL::setEnding(const QString &sEnding)
{
    msEnding = sEnding;

    setChanged();
    notifyObservers("Ending");
}

void ModelConfigSourceURL::setOpening(const QString &sOpening)
{
    msOpening = sOpening;

    setChanged();
    notifyObservers("Opening");
}

void ModelConfigSourceURL::setURL(const QString &sURL)
{
    msURL = sURL;

    setChanged();
    notifyObservers("URL");
}

ModelConfigSourceURL &ModelConfigSourceURL::operator=(const ModelConfigSourceURL &refCopy)
{
    setEnding(refCopy.getEnding());
    setOpening(refCopy.getOpening());
    setURL(refCopy.getURL());

    return(*this);
}

bool ModelConfigSourceURL::operator==(const ModelConfigSourceURL &refOther) const
{
    return  (   (getEnding() == refOther.getEnding())
            &&  (getOpening() == refOther.getOpening())
            &&  (getURL() == refOther.getURL()));
}

bool ModelConfigSourceURL::operator!=(const ModelConfigSourceURL &refOther) const
{
    return(!operator==(refOther));
}
