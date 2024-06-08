#pragma once
#include <list>

#include "../Models/Lote.h"

class LoteService
{
public:
    static void enviarAControlCalidad();
    static int findLoteEnPlantaInspeccionID();
    static void addLote(Lote* lote);
    static Lote findById(int id);
    static std::list<Lote> findAll(); 
};
