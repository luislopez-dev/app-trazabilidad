#include "FincaService.h"

#include "../../CosechaProduccion/Infrastructure/DAO/FincaDAO.h"

Finca FincaService::save(Finca* finca)
{
    return FincaDAO::save(finca);
}
