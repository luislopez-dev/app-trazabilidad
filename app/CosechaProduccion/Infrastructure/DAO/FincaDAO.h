#pragma once
#include <vector>

#include "../../Business/Models/Finca.h"

class FincaDAO
{
public:
    static void save(Finca finca);
    
    static Finca findById(int id);
    
    static  std::vector<Finca> findAll();
};
