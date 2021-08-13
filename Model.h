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
            namespace languageimporter
            {
                namespace model
                {
                    class Model : public Observable
                    {
                        ModelConfig mObjModelConfig;
                        QList<Language> mLstLanguages;
                    protected:
                        void setConfiguration(ModelConfig &refConfiguration);
                    public:
                        Model();
                        ~Model();

                        void addLanguage(const Language &refLanguage);
                        void addLanguages(const std::initializer_list<Language> &lstLanguages);
                        void addLanguages(const QList<Language> &lstLanguages);
                        void clearLanguages();
                        ModelConfig &getConfiguration();
                        QList<Language> &getLanguages() const;
                        void removeLanguage(const Language &refLanguage);
                        void removeLanguages(std::initializer_list<Language> &lstLanguages);
                        void setLanguages(const QList<Language> &lstLanguages);

                        Model &operator=(Model &refCopy);
                        bool operator==(Model &refOther);
                        bool operator!=(Model &refOther);
                    };
                }
            }
        }
    }
}
