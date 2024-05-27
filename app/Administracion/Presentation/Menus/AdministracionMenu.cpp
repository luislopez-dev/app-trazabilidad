#include "AdministracionMenu.h"
#include  <iostream>;

using namespace std;

void AdministracionMenu::showMenu()
{
    cout << "===========================================\n";

    cout << " BIENVENIDO GERENTE GENERAL" << endl;

    cout << "===========================================\n";

    cout << "MENU:" << endl << endl;
    
    cout << "1. VISUALIZAR OPERACIONES EN COSECHA Y PRODUCCION" << endl;

    cout << "2. VISUALIZAR OPERACIONES EN TRANSPORTE Y LOGISTICA" << endl;

    cout << "3. VISUALIZAR OPERACIONES EN CONTROL DE CALIDA" << endl;

    cout << "4. VISUALIZAR OPERACIONES EN DISTRIBUCION" << endl;

    cout << "5. VISUALIZAR OPERACIONES EN " << endl;

    cout << "6. CREAR GERENTE DE FINCA" << endl;

    cout << "7. CREAR GERENTE DE PLANTA" << endl;
    
    cout << "8. CREAR CONDUCTOR" << endl;

    cout << "9. CREAR INSPECTOR DE CALIDAD" << endl;

    cout << "10. CREAR GERENTE DE LOGISTICA" << endl;

    cout << "11. CREAR GERENTE DE DISTRIBUCION" << endl;
}
