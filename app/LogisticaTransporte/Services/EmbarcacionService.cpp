#include "EmbarcacionService.h"

#include <iostream>

#include "../../CosechaProduccion/DAO/LoteDAO.h"
#include "../../Distribucion/Menus/GerenteDistribucionMenu.h"
#include "../../Distribucion/Models/GerenteDistribucion.h"
#include "../DAO/EmbarcacionDAO.h"

void EmbarcacionService::saveEmbarcacion(Embarcacion* embarcacion)
{
    int lote_id = LoteDAO::findLoteListoParaEmbarcacionID();

    if (lote_id)
    {
        EmbarcacionDAO::saveEmbarcacion(embarcacion);
        
        Lote* lote = new Lote;

        lote->set_id(lote_id);

        lote->set_ubicacion_actual("EXPORTADO");

        LoteDAO::updateUbicacion(lote);

        std::cout << "EMBARCACION DE LOTES EXPORTADA." << endl;

        GerenteDistribucionMenu::showMenu();
    }
    else
    {
        std::cout << "FORMULARIO INVALIDO. AUN NO HAY LOTES RECIBIDOS DESDE LA PLANTA DE CONTROL DE CALIDAD.";
    }
}