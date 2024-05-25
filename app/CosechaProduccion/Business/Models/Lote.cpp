#include "Lote.h"

int Lote::get_unidades() const
{
    return unidades;
}

void Lote::set_unidades(int unidades)
{
    this->unidades = unidades;
}

std::string Lote::get_descripcion() const
{
    return descripcion;
}

void Lote::set_descripcion(const std::string& descripcion)
{
    this->descripcion = descripcion;
}
