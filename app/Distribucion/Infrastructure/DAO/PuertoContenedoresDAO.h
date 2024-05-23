#pragma once
#include <vector>

#include "../../Business/Models/PuertoContenedores.h"

class PuertoContenedoresDAO
{
public:
    static void save(PuertoContenedores finca);
    
    static PuertoContenedores findById(int id);
    
    static  std::vector<PuertoContenedores> findAll();
};
