#include "ModelConfigSourceNull.h"

using namespace net::draconia::util::model;

ModelConfigSourceNull::ModelConfigSourceNull()
    :   ModelConfigSource()
{ }

ModelConfigSourceNull::ModelConfigSourceNull(const ModelConfigSourceNull &refCopy)
    :   ModelConfigSource()
{
    Q_UNUSED(refCopy);
}

ModelConfigSourceNull::~ModelConfigSourceNull()
{ }

ModelConfigSourceNull &ModelConfigSourceNull::operator=(const ModelConfigSourceNull &refCopy)
{
    ModelConfigSource::operator=(refCopy);

    return(*this);
}

bool ModelConfigSourceNull::operator==(const ModelConfigSourceNull &refOther) const
{
    return(ModelConfigSource::operator==(refOther));
}

bool ModelConfigSourceNull::operator!=(const ModelConfigSourceNull &refOther) const
{
    return(ModelConfigSource::operator!=(refOther));
}
