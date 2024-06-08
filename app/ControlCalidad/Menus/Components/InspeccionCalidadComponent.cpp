#include "InspeccionCalidadComponent.h"

#include <iostream>

#include "../../Models/InspeccionCalidad.h"
#include "../../Services/InspeccionService.h"

void InspeccionCalidadComponent::showMenu()
{
    system("cls");
    
    InspeccionCalidad* inspeccion = new InspeccionCalidad;
    
    std::string medicion_acidez;
    std::string medicion_dulzura;
    std::string prueba_aroma;

    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "FORMULARIO DE INSPECCION DE CALIDAD" << std::endl;

    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "INGRESE LA MEDICION DE ACIDEZ (1-5)" << std::endl;
    std::cin >> medicion_acidez;
    inspeccion->set_medicion_acidez(medicion_acidez);

    std::cout << "INGRESE LA MEDICION DE DULZURA (1-5)" << std::endl;
    std::cin >> medicion_dulzura;
    inspeccion->set_medicion_dulzura(medicion_dulzura);

    std::cout << "INGRESE EL RESULTADO DE LA PRUEBA AROMA (verde / maduro)" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin ,prueba_aroma);
    inspeccion->set_prueba_aroma(prueba_aroma);

    InspeccionService::saveInspeccion(inspeccion);
}
