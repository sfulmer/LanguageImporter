#pragma once

#include "Language.h"
#include "ModelConfig.h"
#include "Observable.h"

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace model
            {
                class Model : public Observable
                {
                    ModelConfig mObjModelConfig;
                    QList<Language> mLstLanguages;
                protected:
                    void setConfiguration(const ModelConfig &refConfiguration);
                public:
                    Model();
                    ~Model();

                    void addLanguage(const Language &refLanguage);
                    void addLanguages(const std::initializer_list<Language> &lstLanguages);
                    void addLanguages(const QList<Language> &lstLanguages);
                    ModelConfig &getConfiguration() const;
                    QList<Language> &getLanguages() const;
                    void removeLanguage(const Language &refLanguage);
                    void removeLanguages(std::initializer_list<Language> &lstLanguages);
                    void setLanguages(const QList<Language> &lstLanguages);

                    Model &operator=(const Model &refCopy);
                    bool operator==(const Model &refOther) const;
                    bool operator!=(const Model &refOther) const;
                };
            }
        }
    }
}
