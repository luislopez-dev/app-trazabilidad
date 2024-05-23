#include <iostream>

using namespace std;

int option;

int main() {

    cout << "===============================================================\n";

    cout << " BIENVENIDO AL SISTEMA DE TRAZABILIDAD DE FRUTAS EXPORTADAS \n";

    cout << "===============================================================\n";

    cout << "MODULOS: " << endl;

    cout << "1. COSECHA Y PRODUCCION " << endl;

    cout << "2. CONTROL DE CALIDAD " << endl;

    cout << "3. LOGISTICA Y TRANSPORTE" << endl;

    cout << "4. DISTRIBUCION " << endl;

    cout << "SELECCIONE UNA OPCION: ";

    cin >> option;

    switch (option)
    {
        case 1:
            cout << "COSECHA Y PRODUCCION";
            break;
        case 2:
            cout << "CONTROL DE CALIDAD";
            break;
        case 3:
            cout << "LOGISTICA Y TRANSPORTE";
            break;
        case 4:
            cout <<  "DISTRIBUCION";   
            break;
        default:
            cout << "OPCION INVALIDA";
    }
    
    return 0;
}
