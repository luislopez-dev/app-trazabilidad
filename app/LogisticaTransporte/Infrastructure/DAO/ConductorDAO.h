#pragma once
#include <vector>

#include "../../Business/Models/Conductor.h"

class ConductorDAO
{
public:
    static void save(Conductor conductor);
    
    static Conductor findById(int id);
    
    static  std::vector<Conductor> findAll();
};
