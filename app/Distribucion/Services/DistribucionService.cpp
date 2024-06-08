#include "DistribucionService.h"

#include <iostream>

#include "../../CosechaProduccion/DAO/LoteDAO.h"
#include "../../Trazabilidad/Components/TrazabilidadComponent.h"
#include "../DAO/DistribucionDAO.h"

void DistribucionService::save(Distribucion* distribucion)
{
    int lote_id = LoteDAO::findLoteExportadoID();

    if (lote_id)
    {
        DistribucionDAO::save(distribucion);
        
        Lote* lote = new Lote;

        lote->set_id(lote_id);

        lote->set_ubicacion_actual("DISTRIBUIDO");

        LoteDAO::updateUbicacion(lote);

        cout << "DISTRIBUCION REGISTRADA." << endl;

        TrazabilidadComponent::show();
    }
    else
    {
        std::cout << "FORMULARIO INVALIDO. AUN NO HAY LOTES RECIBIDOS DESDE LAS EMBARCACIONES";
    }
    
}
