#pragma once
#include <vector>

#include "../../Business/Models/Lote.h"

class LoteDAO
{
public:
    static void save(Lote lote);
    
    static Lote findById(int id);
    
    static  std::vector<Lote> findAll();
    
};
