#pragma once
#include <vector>

class Vehiculo
{
public:
    static void save(Vehiculo finca);
    
    static Vehiculo findById(int id);
    
    static  std::vector<Vehiculo> findAll();
};
