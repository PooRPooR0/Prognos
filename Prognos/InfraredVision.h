#pragma once
#include "IVision.h"
#include <string>
class InfraredVision :
    public IVision
{
public:
    std::string collectData() override;
};

