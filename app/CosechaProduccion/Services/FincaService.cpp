#include "FincaService.h"

#include "../DAO/FincaDAO.h"

Finca FincaService::getFinca()
{
    return FincaDAO::get();
}
