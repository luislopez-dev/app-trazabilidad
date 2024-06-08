#include "EnviarDuraznosInspeccionCalidad.h"

#include <iostream>

#include "../../../ControlCalidad/Menus/GerentePlantaMenu.h"
#include "../../Services/LoteService.h"

void EnviarDuraznosInspeccionCalidad::showMenu()
{
    LoteService::enviarAControlCalidad();
    
    GerentePlantaMenu::showMenu();
}
