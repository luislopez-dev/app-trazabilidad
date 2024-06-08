#include "InspeccionService.h"

#include <iostream>

#include "../../CosechaProduccion/DAO/LoteDAO.h"
#include "../../CosechaProduccion/Services/LoteService.h"
#include "../../LogisticaTransporte/Menus/GerenteLogisticaMenu.h"
#include "../DAO/InspeccionCalidadDAO.h"
#include "../Models/InspeccionCalidad.h"

void InspeccionService::saveInspeccion(InspeccionCalidad* inspeccion)
{
    int lote_id = LoteDAO::findLoteEnPlantaInspeccionID();

    inspeccion->set_lote_id(lote_id);

    if (lote_id)
    {
        InspeccionCalidadDAO::save(inspeccion);

        Lote* lote = new Lote;

        lote->set_id(lote_id);

        lote->set_ubicacion_actual("Listo Para Embarcacion");

        LoteDAO::updateUbicacion(lote);

        std::cout << "PRUEBA DE INSPECCION EXITOSA Y LOTE ENVIADO A PUERTOS DE EMBARCACION!" << endl;

        GerenteLogisticaMenu::showMenu();
    }
    else
    {
        std::cout << "FORMULARION INVALIDO. AUN NO HAY LOTES RECIBIDOS DESDE LA FINCA DE COSECHA Y PRODUCCION.";
    }
}
