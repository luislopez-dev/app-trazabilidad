#include "GerentePlanta.h"

int GerentePlanta::get_id() const
{
    return id;
}

void GerentePlanta::set_id(int id)
{
    this->id = id;
}

std::string GerentePlanta::get_name() const
{
    return name;
}

void GerentePlanta::set_name(const std::string& name)
{
    this->name = name;
}

int GerentePlanta::get_planta_id() const
{
    return planta_id;
}

void GerentePlanta::set_planta_id(int planta_id)
{
    this->planta_id = planta_id;
}
