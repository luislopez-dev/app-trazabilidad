#pragma once
#include <vector>
#include "../Models/Distribucion.h"

class DistribucionDAO
{
public:
    static void save(Distribucion* distribucion);
};
