#include "Embarcacion.h"

int Embarcacion::get_id() const
{
    return this->get_id();
}

void Embarcacion::set_id(int id)
{
    this->ID = id;
}

std::string Embarcacion::get_puerto_base() const
{
    return this->Puerto_Base;
}

void Embarcacion::set_puerto_base(const std::string& puerto_base)
{
    this->Puerto_Base = puerto_base;
}

std::string Embarcacion::get_fecha_salida() const
{
    return this->Fecha_Salida;
}

void Embarcacion::set_fecha_salida(const std::string& fecha_salida)
{
    this->Fecha_Salida = fecha_salida;
}
