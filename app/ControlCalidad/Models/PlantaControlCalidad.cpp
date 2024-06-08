#include "PlantaControlCalidad.h"

int PlantaControlCalidad::get_id() const
{
    return ID;
}

void PlantaControlCalidad::set_id(int id)
{
    ID = id;
}

std::string PlantaControlCalidad::get_direccion() const
{
    return Direccion;
}

void PlantaControlCalidad::set_direccion(const std::string& direccion)
{
    Direccion = direccion;
}

std::string PlantaControlCalidad::get_nombre() const
{
    return Nombre;
}

void PlantaControlCalidad::set_nombre(const std::string& nombre)
{
    Nombre = nombre;
}
