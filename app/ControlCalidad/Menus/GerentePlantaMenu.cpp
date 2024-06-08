#include "GerentePlantaMenu.h"
#include <iostream>;

#include "Components/InspeccionCalidadComponent.h"

using namespace std;

void GerentePlantaMenu::showMenu()
{
    system("cls");

    int option;
    
    cout << "===========================================\n";

    cout << " BIENVENIDO AL PROCESO DE CONTROL DE CALIDAD \n";

    cout << "===========================================\n" << endl;

    cout << "1. INSPECCIONAR LOTE EN ESPERA" << endl << endl;

    cout << "INGRESE UNA OPCION: ";

    cin >> option;
    
    cout << "===========================================\n";
    
    switch (option)
    {
        case 1:
            InspeccionCalidadComponent::showMenu();
        break;

        default:
            cout << "OPCION INCORRECTA.";
            GerentePlantaMenu::showMenu();
    }
}
