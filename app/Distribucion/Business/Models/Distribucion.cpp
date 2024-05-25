#include "Distribucion.h"

int Distribucion::get_id() const
{
    return id;
}

void Distribucion::set_id(int id)
{
    this->id = id;
}

std::string Distribucion::get_destino() const
{
    return destino;
}

void Distribucion::set_destino(const std::string& destino)
{
    this->destino = destino;
}

std::string Distribucion::get_fecha_reparticion() const
{
    return fecha_reparticion;
}

void Distribucion::set_fecha_reparticion(const std::string& fecha_reparticion)
{
    this->fecha_reparticion = fecha_reparticion;
}
