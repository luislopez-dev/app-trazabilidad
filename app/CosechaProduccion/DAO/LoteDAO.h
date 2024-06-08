#pragma once
#include <list>

#include "../Models/Lote.h"

class LoteDAO
{
public:
    static void save(Lote* lote);
    
    static Lote findById(int id);
    
    static  std::list<Lote> findAll();

    static void updateUbicacion(Lote* lote);

    static int findLoteEnFincaID();
    
    static int findLoteEnPlantaInspeccionID();

    static int findLoteListoParaEmbarcacionID();

    static int findLoteExportadoID();

    static Lote getLast();
};
