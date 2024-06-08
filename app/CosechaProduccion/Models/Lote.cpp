#include "Lote.h"

int Lote::get_id() const
{
    return id;
}

void Lote::set_id(int id)
{
    this->id = id;
}

int Lote::get_finca_id() const
{
    return this->Finca_ID;
}

void Lote::set_finca_id(int finca_id)
{
}

std::string Lote::get_ubicacion_actual() const
{
    return Ubicacion_Actual;
}

void Lote::set_ubicacion_actual(const std::string& ubicacion_actual)
{
    Ubicacion_Actual = ubicacion_actual;
}

std::string Lote::get_descripcion() const
{
    return descripcion;
}

void Lote::set_descripcion(const std::string& descripcion)
{
    this->descripcion = descripcion;
}

std::list<Durazno> Lote::get_duraznos() const
{
    return duraznos;
}

void Lote::set_duraznos(const std::list<Durazno>& duraznos)
{
    this->duraznos = duraznos;
}

string Lote::get_creacion() const
{
    return creacion;
}

void Lote::set_creacion(const string& creacion)
{
    this->creacion = creacion;
}
