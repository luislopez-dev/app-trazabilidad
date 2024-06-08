#include "MainMenu.h"

#include <iostream>

#include "ControlCalidad/Menus/GerentePlantaMenu.h"
#include "CosechaProduccion/Menus/GerenteFincaMenu.h"
#include "Distribucion/Menus/GerenteDistribucionMenu.h"
#include "LogisticaTransporte/Menus/GerenteLogisticaMenu.h"
#include "Trazabilidad/Components/TrazabilidadComponent.h"

using namespace std;

void MainMenu::show()
{
    int user;
    
    cout << "===============================================================\n";

    cout << " BIENVENIDO AL SISTEMA DE TRAZABILIDAD DE DURAZNOS EXPORTADOS \n";

    cout << "===============================================================\n" << endl;

    cout << "PROCESOS: " << endl;
    
    cout << "* Finca y Cosecha" << endl;
    cout << "* Planta de Control de Calidad" << endl;
    cout << "* Embarcacion / Exportacion" << endl;
    cout << "* Distribucion" << endl;
    cout << "* Visualizar Registros de Trazabilidad" << endl;
    
    cout << "INGRESE 1 INICIAR PROCESOS: ";
    
    cin >> user;

    switch (user)
    {
    case 1:
        CosechaProduccionMenu::showMenu();
        break;
    default:
        cout << "OPCION INCORRECTA";
    }
}
