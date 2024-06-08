#include <iostream>
#include "MainMenu.h"
#include "Shared/Database/Database.h"

using namespace std;

int main() {

    // Inicializar base de datos
    Database::init();

    // Mostrar Menu Principal
    MainMenu::show();
    
    return 0;
}