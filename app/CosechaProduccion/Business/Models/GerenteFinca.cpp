#include "GerenteFinca.h"

int GerenteFinca::get_id() const
{
    return id;
}

void GerenteFinca::set_id(int id)
{
    this->id = id;
}

std::string GerenteFinca::get_nombre() const
{
    return nombre;
}

void GerenteFinca::set_nombre(const std::string& nombre)
{
    this->nombre = nombre;
}

int GerenteFinca::get_finca_id() const
{
    return finca_id;
}

void GerenteFinca::set_finca_id(int finca_id)
{
    this->finca_id = finca_id;
}
