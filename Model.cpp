#include "Model.h"

using namespace net::draconia::util::languageimporter::model;

void Model::setConfiguration(ModelConfig &refConfiguration)
{
    mObjModelConfig = refConfiguration;
}

Model::Model()
    :   Observable()
    ,   mLstLanguages()
{ }

Model::~Model()
{ }

void Model::addLanguage(const Language &refLanguage)
{
    getLanguages().append(refLanguage);

    setChanged();
    notifyObservers("Languages");
}

void Model::addLanguages(const std::initializer_list<Language> &lstLanguages)
{
    getLanguages().append(lstLanguages);

    setChanged();
    notifyObservers("Languages");
}

void Model::addLanguages(const QList<Language> &lstLanguages)
{
    getLanguages().append(lstLanguages);

    setChanged();
    notifyObservers("Languages");
}

void Model::clearLanguages()
{
    getLanguages().clear();

    setChanged();
    notifyObservers("Languages");
}

ModelConfig &Model::getConfiguration()
{
    return(mObjModelConfig);
}

QList<Language> &Model::getLanguages()
{
    return(mLstLanguages);
}

void Model::removeLanguage(const Language &refLanguage)
{
    getLanguages().removeOne(refLanguage);

    setChanged();
    notifyObservers("Languages");
}

void Model::removeLanguages(std::initializer_list<Language> &lstLanguages)
{
    for(const Language &lang : lstLanguages)
        getLanguages().removeOne(lang);

    setChanged();
    notifyObservers("Languages");
}

void Model::setLanguages(const QList<Language> &lstLanguages)
{
    mLstLanguages = lstLanguages;

    setChanged();
    notifyObservers("Languages");
}

Model &Model::operator=(Model &refCopy)
{
    setConfiguration(refCopy.getConfiguration());
    setLanguages(refCopy.getLanguages());

    return(*this);
}

bool Model::operator==(Model &refOther)
{
    return  (   (getConfiguration() == refOther.getConfiguration())
            &&  (getLanguages() == refOther.getLanguages()));
}

bool Model::operator!=(Model &refOther)
{
    return(!operator==(refOther));
}
