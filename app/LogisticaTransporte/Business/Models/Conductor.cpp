#include "Conductor.h"

int Conductor::get_id() const
{
    return id;
}

void Conductor::set_id(int id)
{
    this->id = id;
}

std::string Conductor::get_nombre() const
{
    return nombre;
}

void Conductor::set_nombre(const std::string& nombre)
{
    this->nombre = nombre;
}
