#include "EnviarEmbarcacionComponent.h"

#include <iostream>

#include "../../Models/Embarcacion.h"
#include "../../Services/EmbarcacionService.h"

void EnviarEmbarcacionComponent::showMenu()
{
    // system("cls");

    std::string puerto_base;
    
    Embarcacion* embarcacion = new Embarcacion;
    
    std::cout << "-------------------------------" << std::endl;

    std::cout << "EXPORTAR EMBARCACION DE LOTES" << std::endl;

    std::cout << "-------------------------------" << std::endl;

    std::cout << "INGRESE EL NOMBRE DEL PUERTO BASE: " << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, puerto_base);
    embarcacion->set_puerto_base(puerto_base);
    
    EmbarcacionService::saveEmbarcacion(embarcacion);
}
