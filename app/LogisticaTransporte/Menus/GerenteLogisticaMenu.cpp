#include "GerenteLogisticaMenu.h"

#include <iostream>

#include "Components/EnviarEmbarcacionComponent.h"

using namespace std;

void GerenteLogisticaMenu::showMenu()
{
    // system("cls");

    int option;

    cout << "===========================================\n";

    cout << "BIENVENIDO AL PROCESO DE EMBARCACION / EXPORTACION \n";

    cout << "===========================================\n" << endl;

    cout << "1. EXPORTAR EMBARCACION DE LOTES" << endl << endl;

    cout << "INGRESE UNA OPCION: ";
    
    cin >> option;

    switch (option)
    {
        case 1:
            EnviarEmbarcacionComponent::showMenu();
            break;
        default:
            cout << "OPCION INCORRECTA";
    }
}
