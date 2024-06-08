#include "DuraznoService.h"

#include <iostream>

#include "../DAO/DuraznoDAO.h"

void DuraznoService::saveDurazno(Durazno* durazno)
{
    DuraznoDAO::save(durazno);
    std::cout << "DURAZNO REGISTRADO EXITOSAMENTE." << endl;
}