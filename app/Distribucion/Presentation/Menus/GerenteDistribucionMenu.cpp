#include "GerenteDistribucionMenu.h"

#include <iostream>;

using namespace std;

void GerenteDistribucionMenu::showMenu()
{
    system("cls");

    cout << "===========================================\n";

    cout << " BIENVENIDO GERENTE DE DISTRIBUCION" << endl;

    cout << "===========================================\n";

    cout << "MENU:" << endl << endl;
    
    cout << "1. VISUALIZAR REGISTRO DE EMBARGACIONES" << endl;

    cout << "2. REGISTRAR LOTES EN EMBARCACIONES" << endl;

    cout << "3. REGISTRAR SALIDA DE EMBARCACION" << endl;

    cout << "4. VISUALIZAR REGISTRO DE SALIDAD DE EMBARCACIONES" << endl;

    cout << "5. REGISTRAR LLEGADA DE EMBARCACION A PAIS DE DETINO" << endl;

    cout << "6. VISUALIZAR REGISTROS DE LLEGASAS DE EMBARCACIONES AL EXTRANJERO" << endl;
    
    cout << "7. REGISTRAR LLEGADA DE LOTES A TIENDAS DE DESTINO" << endl;

    cout << "8. VISUALIZAR REGISTRO DE LLEGADAS DE LOTES A TIENDAS DE DESTINO" << endl;

    cout << "9. VISUALIZAR TRAZABILIDAD DE LOTES" << endl;
}
