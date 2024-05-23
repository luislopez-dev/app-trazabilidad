#pragma once
#include <vector>

#include "../../Business/Models/Viaje.h"

class ViajeDAO
{
public:
    static void save(Viaje viaje);
    
    static Viaje findById(int id);
    
    static  std::vector<Viaje> findAll();
};
