#include "Planta.h"

int Planta::get_id() const
{
    return id;
}

void Planta::set_id(int id)
{
    this->id = id;
}

std::string Planta::get_nombre() const
{
    return nombre;
}

void Planta::set_nombre(const std::string& nombre)
{
    this->nombre = nombre;
}

std::string Planta::get_direccion() const
{
    return direccion;
}

void Planta::set_direccion(const std::string& direccion)
{
    this->direccion = direccion;
}
