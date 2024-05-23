#pragma once
#include <vector>

#include "../../Business/Models/Distribucion.h"

class DistribucionDAO
{
public:
    static void save(Distribucion distribucion);
    
    static Distribucion findById(int id);
    
    static  std::vector<Distribucion> findAll();
};
