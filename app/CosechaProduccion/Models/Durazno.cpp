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

double Durazno::get_precio() const
{
    return this->precio;
}

void Durazno::set_precio(double precio)
{
}

int Durazno::get_lote_id() const
{
    return lote_id;
}

void Durazno::set_lote_id(int lote_id)
{
    this->lote_id = lote_id;
}

string Durazno::get_fecha_cosecha() const
{
    return fecha_cosecha;
}

void Durazno::set_fecha_cosecha(const string& fecha_cosecha)
{
    this->fecha_cosecha = fecha_cosecha;
}
