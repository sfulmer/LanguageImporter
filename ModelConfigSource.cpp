#include "ModelConfigSource.h"

using namespace net::draconia::util::model;

ModelConfigSource::~ModelConfigSource()
{ }

ModelConfigSource &ModelConfigSource::operator=(const ModelConfigSource &refCopy)
{
    Q_UNUSED(refCopy);

    return(*this);
}

bool ModelConfigSource::operator==(const ModelConfigSource &refOther) const
{
    Q_UNUSED(refOther);

    return(true);
}

bool ModelConfigSource::operator!=(const ModelConfigSource &refOther) const
{
    return(!operator==(refOther));
}
