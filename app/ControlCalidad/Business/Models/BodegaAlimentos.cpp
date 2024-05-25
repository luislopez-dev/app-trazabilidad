#include "BodegaAlimentos.h"

int BodegaAlimentos::get_id() const
{
    return id;
}

void BodegaAlimentos::set_id(int id)
{
    this->id = id;
}

int BodegaAlimentos::get_planta_id() const
{
    return plantaId;
}

void BodegaAlimentos::set_planta_id(int planta_id)
{
    plantaId = planta_id;
}
