#pragma once
#include <vector>

#include "../../Business/Models/GerenteFinca.h"

class GerenteFincaDAO
{
public:
    static void save(GerenteFinca gerente_finca);
    
    static GerenteFinca findById(int id);
    
    static  std::vector<GerenteFinca> findAll();
};
