#pragma once
#include "IVision.h"
#include <string>
class DefaultVision :
    public IVision
{
public:
    std::string collectData() override;
};

