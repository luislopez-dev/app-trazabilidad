#include "GerenteDistribucion.h"

int GerenteDistribucion::get_id() const
{
    return id;
}

void GerenteDistribucion::set_id(int id)
{
    this->id = id;
}

std::string GerenteDistribucion::get_nombre() const
{
    return nombre;
}

void GerenteDistribucion::set_nombre(const std::string& nombre)
{
    this->nombre = nombre;
}
