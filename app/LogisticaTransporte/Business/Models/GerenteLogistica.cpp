#include "GerenteLogistica.h"

int GerenteLogistica::get_id() const
{
    return id;
}

void GerenteLogistica::set_id(int id)
{
    this->id = id;
}

std::string GerenteLogistica::get_nombre() const
{
    return nombre;
}

void GerenteLogistica::set_nombre(const std::string& nombre)
{
    this->nombre = nombre;
}
