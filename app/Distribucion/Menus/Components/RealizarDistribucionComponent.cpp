#include "RealizarDistribucionComponent.h"

#include <iostream>;

#include "../../Services/DistribucionService.h"

using namespace std;

void RealizarDistribucionComponent::showMenu()
{
    // system("cls");

    Distribucion* distribucion = new Distribucion;

    string tienda_nombre;

    string tienda_direccion;
    
    // cout << "=================================================\n";
    //
    // cout << "ENVIAR LOTE EXPORTADO A TIENDA DE DISTRIBUCION" << endl;
    //
    // cout << "=================================================\n";
    
    cout << "INGRESE EL NOMBRE DE LA TIENDA:" << endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, tienda_nombre);
    distribucion->set_tienda_destino_nombre(tienda_nombre);
    
    cout << "INGRESE LA DIRECCION DE LA TIENDA:" << endl;
    getline(std::cin, tienda_direccion);
    distribucion->set_tienda_destino_direccion(tienda_direccion);

    DistribucionService::save(distribucion);
}