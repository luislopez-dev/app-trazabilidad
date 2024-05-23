#pragma once
#include <vector>

#include "../../Business/Models/Vehiculo.h"

class VehiculoDAO
{
public:
    static void save(Vehiculo vehiculo);
    
    static Vehiculo findById(int id);
    
    static  std::vector<Vehiculo> findAll();
};
