#include "ModelConfig.h"
#include "ModelConfigSourceNull.h"

using namespace net::draconia::util::model;

void ModelConfig::setSourceConfig(const ModelConfigSource *ptrSourceConfig)
{
    if(ptrSourceConfig == nullptr)
        mPtrSourceConfig = new ModelConfigSourceNull();
    else
        mPtrSourceConfig = const_cast<ModelConfigSource *>(ptrSourceConfig);
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

QString &ModelConfig::getDatabasePath() const
{
    return(const_cast<ModelConfig &>(*this).msDBPath);
}

QString &ModelConfig::getSource() const
{
    return(const_cast<ModelConfig &>(*this).msSource);
}

ModelConfigSource &ModelConfig::getSourceConfig()
{
    if(mPtrSourceConfig == nullptr)
        mPtrSourceConfig = new ModelConfigSourceNull();

    return(*mPtrSourceConfig);
}

void ModelConfig::setDatabasePath(const QString sDBPath)
{
    msDBPath = sDBPath;

    setChanged();
    notifyObservers("DBPath");
}

void ModelConfig::setSource(const QString &sSource)
{
    msSource = sSource;

    setChanged();
    notifyObservers("Source");
}

ModelConfig &ModelConfig::operator=(const ModelConfig &refCopy)
{
    setSourceConfig(refCopy.mPtrSourceConfig);
    setDatabasePath(refCopy.getDatabasePath());
    setSource(refCopy.getSource());

    return(*this);
}

bool ModelConfig::operator==(const ModelConfig &refOther) const
{
    return  (   (getSource() == refOther.getSource())
            &&  (getDatabasePath() == refOther.getDatabasePath())
            &&  (const_cast<ModelConfig &>(*this).getSourceConfig() == const_cast<ModelConfig &>(refOther).getSourceConfig()));
}

bool ModelConfig::operator!=(const ModelConfig &refOther) const
{
    return(!operator==(refOther));
}
