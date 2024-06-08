#include "TrazabilidadComponent.h"

#include <iomanip>
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

// Marco de ganancia: precio-venta - costo unidad (durazno)
double get_marco_ganancia() {

    Durazno* durazno = new Durazno;

    return  9.75 - durazno->get_precio();
}

void TrazabilidadComponent::show()
{
    system("cls");
    
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
    
    std::cout << "PROCESO: COSECHA Y PRODUCCION" << endl;
    std::cout << "FECHA: " << lote.get_creacion() << endl;
    std::cout << "RESPONSABLE: GERNETE DE COSECHA Y PRODUCCION"<< endl;
    std::cout << "ESTADO: COMPLETADO"<< endl;
    std::cout << "LUGAR: "  << finca.get_nombre() << ", " << finca.get_direccion() << endl;

    std::cout << "--------------------------------------------" << endl;
    
    std::cout << "PROCESO: CONTROL DE CALIDAD" << endl;
    std::cout << "FECHA: " << inspeccion.get_fecha() << endl;
    std::cout << "RESPONSABLE: GERENTE DE CONTROL DE CALIDAD"<< endl;
    std::cout << "ESTADO: COMPLETADO"<< endl;
    std::cout << "LUGAR: "<< planta.get_nombre() << ", " << planta.get_direccion() << endl;

    std::cout << "--------------------------------------------" << endl;

    std::cout << "PROCESO: EMBARCACION / EXPORTACION" << endl;
    std::cout << "FECHA: " << embarcacion.get_fecha_salida() << endl;
    std::cout << "RESPONSABLE: GERENTE DE LOGISTICA"<< endl;
    std::cout << "ESTADO: COMPLETADO"<< endl;
    std::cout << "LUGAR: " << embarcacion.get_puerto_base() << endl;

    std::cout << "--------------------------------------------" << endl;

    std::cout << "PROCESO: DISTRIBUCION" << endl;
    std::cout << "FECHA: " << distribucion.get_fecha_reparticion() << endl;
    std::cout << "RESPONSABLE: GERENTE DE DISTRIBUCION"<< endl;
    std::cout << "ESTADO: COMPLETADO"<< endl;
    std::cout << "LUGAR: " << distribucion.get_tienda_destino_nombre() << ", " << distribucion.get_tienda_destino_direccion() << endl;
    std::cout << "MARCO DE GANANCIA: Q" << get_marco_ganancia() << " por unidad" << endl;
}
