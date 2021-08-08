#pragma once

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
                class ModelConfigSource : public Observable
                {
                public:
                    virtual ~ModelConfigSource() = 0;

                    ModelConfigSource &operator=(const ModelConfigSource &refCopy);
                    bool operator==(const ModelConfigSource &refOther) const;
                    bool operator!=(const ModelConfigSource &refOther) const;
                };
            }
        }
    }
}
