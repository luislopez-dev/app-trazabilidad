#include "LoteService.h"

#include <iostream>

#include "../DAO/LoteDAO.h"

int findLoteEnPlantaInspeccionID()
{
    return LoteDAO::findLoteEnPlantaInspeccionID();
}

void LoteService::enviarAControlCalidad()
{
    int lote_id = LoteDAO::findLoteEnFincaID();
    
    if (lote_id)
    {
        Lote* lote = new Lote;
        lote->set_ubicacion_actual("Control_Calidad");
        lote->set_id(lote_id);
        LoteDAO::updateUbicacion(lote);

        std::cout << "DURAZNOS ENVIADOS A INSPECCION DE CALIDAD." << endl;
    }
    else
    {
        std::cout << "NO HAY DURAZNOS REGISTRADOS PARA ENVIAR." << endl;
    }
}

void LoteService::addLote(Lote* lote)
{
    LoteDAO::save(lote);
}

int LoteService::findLoteEnPlantaInspeccionID()
{
}

void LoteService::getLast()
{
    
}
