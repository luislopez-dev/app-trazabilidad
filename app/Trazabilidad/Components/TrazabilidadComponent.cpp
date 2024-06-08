#include "TrazabilidadComponent.h"
#include <iostream>

#include "../../ControlCalidad/DAO/InspeccionCalidadDAO.h"
#include "../../ControlCalidad/DAO/PlantaControlCalidadDAO.h"
#include "../../ControlCalidad/Models/InspeccionCalidad.h"
#include "../../ControlCalidad/Models/PlantaControlCalidad.h"
#include "../../CosechaProduccion/DAO/LoteDAO.h"
#include "../../CosechaProduccion/Models/Finca.h"
#include "../../CosechaProduccion/Models/Lote.h"
#include "../../CosechaProduccion/Services/FincaService.h"
#include "../../Distribucion/DAO/DistribucionDAO.h"
#include "../../Distribucion/Models/Distribucion.h"
#include "../../LogisticaTransporte/DAO/EmbarcacionDAO.h"
#include "../../LogisticaTransporte/Models/Embarcacion.h"

void TrazabilidadComponent::show()
{
    // lote exportado
    Lote lote = LoteDAO::getLast();

    // finca
    Finca finca = FincaService::getFinca();

    // planta de control de calidad
    PlantaControlCalidad planta = PlantaControlCalidadDAO::get();

    // inspeccion de control de calidad
    InspeccionCalidad inspeccion = InspeccionCalidadDAO::getLast();

    // Embarcacion / Exportacion
    Embarcacion embarcacion = EmbarcacionDAO::getLast();

    // Distribucion
    Distribucion distribucion = DistribucionDAO::getLast();

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "TRAZABILIDAD DE LOTE EXPORTADO" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::cout << "|PROCESO | FECHA | RESPONSABLE | ESTADO | LUGAR | MARCO DE GANANCIA|" << std::endl;

    std::cout << "|COSECHA PRODUCCION | " << lote.get_creacion() << " | Gerente de Cosecha y Produccion | COMPLETADO | " << finca.get_nombre() << ", " << finca.get_direccion() << " | MARCO DE GANANCIA|" << std::endl;

    std::cout << "|CONTROL DE CALIDAD | " << inspeccion.get_fecha() << " | Gerente de Control de Calidad | COMPLETADO | " <<  planta.get_nombre() << ", " << planta.get_direccion() <<" | MARCO DE GANANCIA|" << std::endl;

    std::cout << "|EMBARCACION / EXPORTACION | "<< embarcacion.get_fecha_salida() << " | Gerente de Logistica | COMPLETADO | " << embarcacion.get_puerto_base() << " | MARCO DE GANANCIA|" << std::endl;

    std::cout << "|DISTRIBUCION | " << distribucion.get_fecha_reparticion() <<" | Gerente de Distribucion | COMPLETADO | "<< distribucion.get_tienda_destino_nombre() << ", " << distribucion.get_tienda_destino_direccion() <<" | MARCO DE GANANCIA|" << std::endl;
}
