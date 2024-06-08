#include "GerenteDistribucionMenu.h"
#include <iostream>;
#include "Components/RealizarDistribucionComponent.h"

using namespace std;

void GerenteDistribucionMenu::showMenu()
{
    // system("cls");

    int option;

    cout << "===========================================\n";

    cout << "PROCESO DE DISTRIBUCION" << endl;

    cout << "===========================================\n";

    cout << "MENU:" << endl << endl;
    
    cout << "1. ENVIAR LOTE EXPORTADO A TIENDA DE DISTRIBUCION" << endl << endl;

    cout << "INGRESE UNA OPCION: ";

    std::cin >> option;
    
    switch (option)
    {
        case 1:
            RealizarDistribucionComponent::showMenu();
            break;

        default:
            std::cout << "OPCION INCORRECTA.";
    }
}