#pragma once

#include "ModelConfigSource.h"

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
                    class ModelConfigSourceNull : public ModelConfigSource
                    {
                    public:
                        ModelConfigSourceNull();
                        ModelConfigSourceNull(const ModelConfigSourceNull &refCopy);
                        virtual ~ModelConfigSourceNull();

                        ModelConfigSourceNull &operator=(const ModelConfigSourceNull &refCopy);
                        bool operator==(const ModelConfigSourceNull &refOther) const;
                        bool operator!=(const ModelConfigSourceNull &refOther) const;
                    };
                }
            }
        }
    }
}
