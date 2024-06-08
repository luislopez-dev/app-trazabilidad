#include "MostrarInformacionFincaComponent.h"

#include <iostream>

#include "../GerenteFincaMenu.h"
#include "../../Services/FincaService.h"

void MostrarInformacionFincaComponent::showMenu()
{
    Finca finca = FincaService::getFinca();
    
    std::cout << "INFORMACION DE FINCA: " << std::endl;

    std::cout << "NOMBRE: " <<  finca.get_nombre() << std::endl;

    std::cout << "DIRECCION: " << finca.get_direccion() << std::endl;

    CosechaProduccionMenu::showMenu();
}