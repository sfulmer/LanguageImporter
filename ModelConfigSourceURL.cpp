#include "ModelConfigSourceURL.h"

using namespace net::draconia::util::languageimporter::model;

ModelConfigSourceURL::ModelConfigSourceURL()
    :   ModelConfigSource()
{ }

ModelConfigSourceURL::ModelConfigSourceURL(ModelConfigSourceURL &refCopy)
    :   ModelConfigSource()
    ,   msEnding(refCopy.getEnding())
    ,   msOpening(refCopy.getOpening())
    ,   msURL(refCopy.getURL())
{ }

ModelConfigSourceURL::~ModelConfigSourceURL()
{ }

QString &ModelConfigSourceURL::getEnding()
{
    return(msEnding);
}

QString &ModelConfigSourceURL::getOpening()
{
    return(msOpening);
}

QString &ModelConfigSourceURL::getURL()
{
    return(msURL);
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

ModelConfigSourceURL &ModelConfigSourceURL::operator=(ModelConfigSourceURL &refCopy)
{
    setEnding(refCopy.getEnding());
    setOpening(refCopy.getOpening());
    setURL(refCopy.getURL());

    return(*this);
}

bool ModelConfigSourceURL::operator==(ModelConfigSourceURL &refOther)
{
    return  (   (getEnding() == refOther.getEnding())
            &&  (getOpening() == refOther.getOpening())
            &&  (getURL() == refOther.getURL()));
}

bool ModelConfigSourceURL::operator!=(ModelConfigSourceURL &refOther)
{
    return(!operator==(refOther));
}
