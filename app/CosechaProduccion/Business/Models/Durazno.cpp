#include "Durazno.h"

int Durazno::get_id() const
{
    return id;
}

void Durazno::set_id(int id)
{
    this->id = id;
}

string Durazno::get_color() const
{
    return color;
}

void Durazno::set_color(const string& color)
{
    this->color = color;
}

string Durazno::get_tamano() const
{
    return tamano;
}

void Durazno::set_tamano(const string& tamano)
{
    this->tamano = tamano;
}

float Durazno::get_precio() const
{
    return precio;
}

void Durazno::set_precio(float precio)
{
    this->precio = precio;
}

int Durazno::get_finca_id() const
{
    return finca_id;
}

void Durazno::set_finca_id(int finca_id)
{
    this->finca_id = finca_id;
}

string Durazno::get_fecha_cosecha() const
{
    return fecha_cosecha;
}

void Durazno::set_fecha_cosecha(const string& fecha_cosecha)
{
    this->fecha_cosecha = fecha_cosecha;
}
