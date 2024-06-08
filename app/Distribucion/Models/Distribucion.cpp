#include "Distribucion.h"

int Distribucion::get_id() const
{
    return id;
}

void Distribucion::set_id(int id)
{
    this->id = id;
}

std::string Distribucion::get_tienda_destino_nombre() const
{
    return tienda_destino_nombre;
}

void Distribucion::set_tienda_destino_nombre(const std::string& tienda_destino_nombre)
{
    this->tienda_destino_nombre = tienda_destino_nombre;
}

std::string Distribucion::get_tienda_destino_direccion() const
{
    return tienda_destino_direccion;
}

void Distribucion::set_tienda_destino_direccion(const std::string& tienda_destino_direccion)
{
    this->tienda_destino_direccion = tienda_destino_direccion;
}

std::string Distribucion::get_fecha_reparticion() const
{
    return fecha_reparticion;
}

void Distribucion::set_fecha_reparticion(const std::string& fecha_reparticion)
{
    this->fecha_reparticion = fecha_reparticion;
}
