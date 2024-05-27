#include "GerentePlantaMenu.h"
#include <iostream>;

using namespace std;

void GerentePlantaMenu::showMenu()
{
    system("cls");
    
    cout << "===========================================\n";

    cout << " BIENVENIDO GERENTE DE PLANTA \n";

    cout << "===========================================\n";

    cout << "1. REGISTRAR LOTES" << endl;

    cout << "2. MOSTRAR LOTES REGISTRADOS" << endl;

    cout << "3. REGISTRAR LOTES LISTOS PARA EXPORTACION" << endl;

    cout << "4. MOSTRAR LOTES LISTOS PARA EXPORTACION" << endl;

    cout << "5. MOSTRAR INFORMACION DE LA PLANTA" << endl;

    cout << "6. MOSTRAR BODEGAS DE ALIMENTOS" << endl;
    
    cout << "===========================================\n";
}
