#include "GerenteFincaMenu.h"
#include <iostream>

#include "../../Application/Services/DuraznoService.h"
#include "../../Business/Models/Durazno.h"

using namespace std;

void CosechaProduccionMenu::showMenu()
{
    int option;
    Durazno durazno;
    string color;
    string peso;
    
    cout << "===========================================\n";

    cout << " BIENVENIDO GERENTE DE FINCA \n";

    cout << "OPCIONES: " << endl;

    cout << "1. Registrar durazno " << endl;

    cin >> option;

    switch (option)
    {
        case 1:
            cout << "Ingrese el color del durazno: ";
            cin >> color;
            durazno.set_color(color);
            cout << "Ingrese el peso del durazno: ";
            cin >> peso;
            durazno.set_tamano(peso);
            DuraznoService::saveDurazno(durazno);
    }

    cout << "===========================================\n";
}
