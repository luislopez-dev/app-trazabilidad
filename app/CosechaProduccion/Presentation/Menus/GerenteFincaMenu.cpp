#include "GerenteFincaMenu.h"
#include <iostream>
using namespace std;

void CosechaProduccionMenu::showMenu()
{
    system("cls");

    cout << "===========================================\n";

    cout << " BIENVENIDO GERENTE DE FINCA" << endl;

    cout << "===========================================\n";

    cout << "MENU:" << endl << endl;
    
    cout << "1. REGISTRAR DURAZNO" << endl;

    cout << "2. REGISTRAR LOTES" << endl;

    cout << "3. VISUALIZAR DURAZNOS" << endl;

    cout << "4. VISUALIZAR LOTES" << endl;

    cout << "5. MARCAR LOTES COMO LISTOS PARA INSPECCION DE CALIDAD" << endl;

    cout << "6. VISUALIZAR REGISTRO DE LOTES LISTOS PARA INSPECCION DE CALIDAD" << endl;
}
