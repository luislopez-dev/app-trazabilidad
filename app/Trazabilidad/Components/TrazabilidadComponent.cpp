#include "TrazabilidadComponent.h"
#include <iostream>

#include "../../CosechaProduccion/Models/Finca.h"
#include "../../CosechaProduccion/Services/FincaService.h"

void TrazabilidadComponent::show()
{
    Finca finca = FincaService::getFinca();

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "MOSTRANDO TRAZABILIDAD DE LOTE EXPORTADO" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::cout << "|PROCESO | FECHA | RESPONSABLE | ESTADO | LUGAR | UNIDADES | MARCO DE GANANCIA|" << std::endl;
    std::cout << "|COSECHA PRODUCCION | FECHA | RESPONSABLE | COMPLETADO | " << finca.get_nombre() << ", " << finca.get_direccion() << "| UNIDADES | MARCO DE GANANCIA|" << std::endl;
    std::cout << "|CONTROL DE CALIDAD | FECHA | RESPONSABLE | COMPLETADO | LUGAR | UNIDADES | MARCO DE GANANCIA|" << std::endl;
    std::cout << "|EMBARCACION / EXPORTACION | RESPONSABLE | COMPLETADO | LUGAR | UNIDADES | MARCO DE GANANCIA|" << std::endl;
    std::cout << "|DISTRIBUCION | FECHA | RESPONSABLE | ESTADO | COMPLETADO | UNIDADES | MARCO DE GANANCIA|" << std::endl;
    
}
