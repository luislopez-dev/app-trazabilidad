#include "Vehiculo.h"

int Vehiculo::get_placa() const
{
    return placa;
}

void Vehiculo::set_placa(int placa)
{
    this->placa = placa;
}

std::string Vehiculo::get_marca() const
{
    return marca;
}

void Vehiculo::set_marca(const std::string& marca)
{
    this->marca = marca;
}

std::string Vehiculo::get_modelo() const
{
    return modelo;
}

void Vehiculo::set_modelo(const std::string& modelo)
{
    this->modelo = modelo;
}
