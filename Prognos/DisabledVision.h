#pragma once
#include "IVision.h"
#include <string>
class DisabledVision :
    public IVision
{
public:
    std::string collectData() override;
};

