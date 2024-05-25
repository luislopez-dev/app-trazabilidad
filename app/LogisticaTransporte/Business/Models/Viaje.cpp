#include "Viaje.h"

int Viaje::get_id() const
{
    return id;
}

void Viaje::set_id(int id)
{
    this->id = id;
}

int Viaje::get_gerente_logistica_id() const
{
    return gerente_logistica_id;
}

void Viaje::set_gerente_logistica_id(int gerente_logistica_id)
{
    this->gerente_logistica_id = gerente_logistica_id;
}

int Viaje::get_conductor_id() const
{
    return conductor_id;
}

void Viaje::set_conductor_id(int conductor_id)
{
    this->conductor_id = conductor_id;
}

std::string Viaje::get_salida() const
{
    return salida;
}

void Viaje::set_salida(const std::string& salida)
{
    this->salida = salida;
}

std::string Viaje::get_llegada() const
{
    return llegada;
}

void Viaje::set_llegada(const std::string& llegada)
{
    this->llegada = llegada;
}

std::string Viaje::get_lugar_origen() const
{
    return lugar_origen;
}

void Viaje::set_lugar_origen(const std::string& lugar_origen)
{
    this->lugar_origen = lugar_origen;
}

std::string Viaje::get_lugar_destino() const
{
    return lugar_destino;
}

void Viaje::set_lugar_destino(const std::string& lugar_destino)
{
    this->lugar_destino = lugar_destino;
}
