#include <iostream>

#include "ControlCalidad/Presentation/ControlCalidadMenu.h"
#include "CosechaProduccion/Presentation/CosechaProduccionMenu.h"
#include "Distribucion/Presentation/DistribucionMenu.h"
#include "LogisticaTransporte/LogisticaTransporteMenu.h"

using namespace std;

int option;

int main() {

    cout << "===============================================================\n";

    cout << " BIENVENIDO AL SISTEMA DE TRAZABILIDAD DE FRUTAS EXPORTADAS \n";

    cout << "===============================================================\n";

    cout << "MODULOS: " << endl;

    cout << "1. COSECHA Y PRODUCCION " << endl;

    cout << "2. CONTROL DE CALIDAD " << endl;

    cout << "3. LOGISTICA Y TRANSPORTE" << endl;

    cout << "4. DISTRIBUCION " << endl;

    cout << "SELECCIONE UNA OPCION: ";

    cin >> option;

    switch (option)
    {
    case 1:
        CosechaProduccionMenu::showMenu();
        break;
    case 2:
        ControlCalidadMenu::showMenu();
        break;
    case 3:
        DistribucionMenu::showMenu();
        break;
    case 4:
        LogisticaTransporteMenu::showMenu();
        break;
    default:
        cout << "OPCION INVALIDA";
    }
    return 0;
}