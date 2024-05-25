#include "Embarcacion.h"

int Embarcacion::get_id() const
{
    return id;
}

void Embarcacion::set_id(int id)
{
    this->id = id;
}

std::string Embarcacion::get_salida() const
{
    return salida;
}

void Embarcacion::set_salida(const std::string& salida)
{
    this->salida = salida;
}

std::string Embarcacion::get_llegada() const
{
    return llegada;
}

void Embarcacion::set_llegada(const std::string& llegada)
{
    this->llegada = llegada;
}
