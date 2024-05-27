#include "InspectorCalidadMenu.h"

#include <iostream>;

using namespace std;

void InspectorCalidadMenu::showMenu()
{
    system("cls");

    cout << "===========================================\n";

    cout << " BIENVENIDO INSPECTOR DE CALIDAD \n";

    cout << "===========================================\n";

    cout << "MENU:" << endl << endl;
    
    cout << "1. REGISTRAR LOTES EN BODEGA" << endl;

    cout << "2. VISUALIZAR REGISTROS DE BODEGA" << endl;
    
    cout << "3. REGISTRAR RESULTADOS DE INSPECCION Y CONTROL DE CALIDAD" << endl;

    cout << "4. VISUALIZAR REGISTROS DE INSPECCION Y CONTROL DE CALIDAD" << endl;

    cout << "5. MARCAR LOTES COMO LISTOS PARA EXPORTACION" << endl;

    cout << "6. VISUALIZAR LOTES LISTOS PARA EXPORTACION" << endl;
}
