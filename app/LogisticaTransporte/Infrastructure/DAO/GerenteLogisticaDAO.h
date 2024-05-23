#pragma once
#include <vector>

#include "../../Business/Models/GerenteLogistica.h"

class GerenteLogisticaDAO
{
public:
    static void save(GerenteLogistica finca);
    
    static GerenteLogistica findById(int id);
    
    static  std::vector<GerenteLogistica> findAll();
    
};
