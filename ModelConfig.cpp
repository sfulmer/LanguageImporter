#include "ModelConfig.h"
#include "ModelConfigSourceDatabase.h"
#include "ModelConfigSourceNull.h"
#include "ModelConfigSourceText.h"
#include "ModelConfigSourceURL.h"

using namespace net::draconia::util::languageimporter::model;

void ModelConfig::setSourceConfig(ModelConfigSource *ptrSourceConfig)
{
    if(ptrSourceConfig == nullptr)
        mPtrSourceConfig = new ModelConfigSourceNull();
    else
        mPtrSourceConfig = ptrSourceConfig;
}

ModelConfig::ModelConfig()
    :   mPtrSourceConfig(nullptr)
{ }

ModelConfig::ModelConfig(const ModelConfig &refCopy)
    :   mPtrSourceConfig(refCopy.mPtrSourceConfig)
{ }

ModelConfig::~ModelConfig()
{
    if(mPtrSourceConfig != nullptr)
        delete mPtrSourceConfig;
}

QString &ModelConfig::getDatabasePath()
{
    return(msDBPath);
}

QString &ModelConfig::getSource()
{
    return(msSource);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdangling-else"
ModelConfigSource &ModelConfig::getSourceConfig()
{
    if(mPtrSourceConfig == nullptr)
        if(getSource() == "URL")
            mPtrSourceConfig = new ModelConfigSourceURL();
        else if(getSource() == "Text")
            mPtrSourceConfig = new ModelConfigSourceText();
        else if(getSource() == "Database")
            mPtrSourceConfig = new ModelConfigSourceDatabase();
        else
            mPtrSourceConfig = new ModelConfigSourceNull();

    return(*mPtrSourceConfig);
}
#pragma GCC diagnostic pop

void ModelConfig::setDatabasePath(const QString sDBPath)
{
    msDBPath = sDBPath;

    setChanged();
    notifyObservers("DBPath");
}

void ModelConfig::setSource(const QString &sSource)
{
    msSource = sSource;

    delete mPtrSourceConfig;
    mPtrSourceConfig = nullptr;

    setChanged();
    notifyObservers("Source");
}

ModelConfig &ModelConfig::operator=(ModelConfig &refCopy)
{
    setSourceConfig(refCopy.mPtrSourceConfig);
    setDatabasePath(refCopy.getDatabasePath());
    setSource(refCopy.getSource());

    return(*this);
}

bool ModelConfig::operator==(ModelConfig &refOther)
{
    return  (   (getSource() == refOther.getSource())
            &&  (getDatabasePath() == refOther.getDatabasePath())
            &&  (const_cast<ModelConfig &>(*this).getSourceConfig() == const_cast<ModelConfig &>(refOther).getSourceConfig()));
}

bool ModelConfig::operator!=(ModelConfig &refOther)
{
    return(!operator==(refOther));
}
