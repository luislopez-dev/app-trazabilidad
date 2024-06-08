#include "RegistroDuraznoComponent.h"

#include <iostream>

#include "../GerenteFincaMenu.h"
#include "../../../Distribucion/Menus/GerenteDistribucionMenu.h"
#include "../../../Distribucion/Models/GerenteDistribucion.h"
#include "../../Models/Durazno.h"
#include "../../Services/DuraznoService.h"

using namespace std;

void RegistroDuraznoComponent::showMenu()
{
    system("cls");
    
    Durazno* durazno = new Durazno();

    string color;

    string tamano;
    
    cout << "REGISTRAR DURAZNO" << std::endl;

    cout << "INGRESE EL COLOR DEL DURAZNO: " << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, color);
    durazno->set_color(color);

    cout << "INGRESE EL TAMANO DEL DURAZNO: " << endl;
    getline(cin, tamano);
    durazno->set_tamano(tamano);
    
    DuraznoService::saveDurazno(durazno);

    CosechaProduccionMenu::showMenu();
}
