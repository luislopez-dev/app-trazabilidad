#pragma once
#include <vector>

class GerenteDistribucion
{
public:
    static void save(GerenteDistribucion gerente_distribucion);
    
    static GerenteDistribucion findById(int id);
    
    static  std::vector<GerenteDistribucion> findAll();
};
