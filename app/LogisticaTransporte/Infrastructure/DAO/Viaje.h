#pragma once
#include <vector>

class Viaje
{
public:
    static void save(Viaje finca);
    
    static Viaje findById(int id);
    
    static  std::vector<Viaje> findAll();
};
