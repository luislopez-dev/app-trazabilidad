#include "GerenteFincaMenu.h"
#include <iostream>

#include "Components/EnviarDuraznosInspeccionCalidad.h"
#include "Components/MostrarInformacionFincaComponent.h"
#include "Components/RegistroDuraznoComponent.h"
using namespace std;

void CosechaProduccionMenu::showMenu()
{
    int option;
    
    // system("cls");

    cout << "===========================================\n";

    cout << "BIENVENIDO AL PROCESO DE COSECHA Y PRODUCCION" << endl;

    cout << "===========================================\n" << endl;

    cout << "MENU:" << endl << endl;
    
    cout << "1. REGISTRAR DURAZNO" << endl;
    
    cout << "2. VER INFORMACION DE FINCA" << endl;

    cout << "3. ENVIAR DURAZNOS EN FINCA A INSPECCION DE CALIDAD" << endl << endl;
    
    cout << "INGRESE UNA OPCION: ";

    cin >> option;
    
    switch (option)
    {
        case 1:
            RegistroDuraznoComponent::showMenu();
        break;

        case 2:
            MostrarInformacionFincaComponent::showMenu();
        break;
        
        case 3:
            EnviarDuraznosInspeccionCalidad::showMenu();
        break;
        
        default:
            cout << "OPCION INCORRECTA";
    }
}
