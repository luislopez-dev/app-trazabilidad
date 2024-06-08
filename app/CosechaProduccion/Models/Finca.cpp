#include "Finca.h"

int Finca::get_id() const
{
    return id;
}

void Finca::set_id(int id)
{
    this->id = id;
}

std::string Finca::get_nombre() const
{
    return nombre;
}

void Finca::set_nombre(const std::string& nombre)
{
    this->nombre = nombre;
}

std::string Finca::get_direccion() const
{
    return direccion;
}

void Finca::set_direccion(const std::string& direccion)
{
    this->direccion = direccion;
}
