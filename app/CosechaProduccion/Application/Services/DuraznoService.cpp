#include "DuraznoService.h"

#include "../../Infrastructure/DAO/DuraznoDAO.h"

void DuraznoService::saveDurazno(Durazno durazno)
{
    DuraznoDAO::save(durazno);
}
