#pragma once
#include "../Models/Distribucion.h"

class DistribucionDAO
{
public:
    static void save(Distribucion* distribucion);
    static Distribucion getLast();
};
