#include <iostream>

#include "Administracion/Presentation/Menus/AdministracionMenu.h"
#include "ControlCalidad/Presentation/Menus/GerentePlantaMenu.h"
#include "ControlCalidad/Presentation/Menus/InspectorCalidadMenu.h"
#include "ControlCalidad/Presentation/Menus/TecnicoLaboratorioMenu.h"
#include "CosechaProduccion/Presentation/Menus/GerenteFincaMenu.h"
#include "LogisticaTransporte/Presentation/Menus/ConductorMenu.h"
#include "LogisticaTransporte/Presentation/Menus/GerenteLogisticaMenu.h"

using namespace std;

int option;
int user;

int main() {

    cout << "===============================================================\n";

    cout << " BIENVENIDO AL SISTEMA DE TRAZABILIDAD DE FRUTAS EXPORTADAS \n";

    cout << "===============================================================\n";

    cout << "INICIAR SESION COMO: " << endl;

    cout << "1. Gerente General" << endl;
    cout << "2. Gerente de Finca" << endl;
    cout << "3. Gerente de Planta" << endl;
    cout << "4. Inspector de Calidad" << endl;
    cout << "5. Tecnico de Laboratorio" << endl;
    cout << "6. Gerente de Logistica" << endl;
    cout << "7. Conductor" << endl;
    cout << "8. Gerente de Distribucion" << endl;

    cout << "INGRESE UNA OPCION: ";
    cin >> user;

    switch (user)
    {
        case 1:
            AdministracionMenu::showMenu();
            break;
        case 2:
            CosechaProduccionMenu::showMenu();
            break;
        case 3:
            GerentePlantaMenu::showMenu();
            break;
        case 4:
            InspectorCalidadMenu::showMenu();
            break;
        case 5:
            TecnicoLaboratorioMenu::showMenu();
            break;
        case 6:
            GerenteLogisticaMenu::showMenu();
            break;
        case 7:
            ConductorMenu::showMenu();
            break;
        case 8:
            GerentePlantaMenu::showMenu();
        default:
            cout << "OPCION INCORRECTA";
    }
    
    /*// cout << "MODULOS: " << endl;
    //
    // cout << "1. COSECHA Y PRODUCCION " << endl;
    //
    // cout << "2. CONTROL DE CALIDAD " << endl;
    //
    // cout << "3. LOGISTICA Y TRANSPORTE" << endl;
    //
    // cout << "4. DISTRIBUCION " << endl;
    //
    // cout << "SELECCIONE UNA OPCION: ";
    //
    // cin >> option;
    //
    // switch (option)
    // {
    // case 1:
    //     CosechaProduccionMenu::showMenu();
    //     break;
    // case 2:
    //     ControlCalidadMenu::showMenu();
    //     break;
    // case 3:
    //     DistribucionMenu::showMenu();
    //     break;
    // case 4:
    //     LogisticaTransporteMenu::showMenu();
    //     break;
    // default:
    //     cout << "OPCION INVALIDA";
    // }*/
    return 0;
}