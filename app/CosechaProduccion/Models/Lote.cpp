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

int Lote::get_embarcacion_id() const
{
    return Embarcacion_ID;
}

void Lote::set_embarcacion_id(int embarcacion_id)
{
    Embarcacion_ID = embarcacion_id;
}

int Lote::get_planta_control_calidad_id() const
{
    return Planta_Control_Calidad_ID;
}

void Lote::set_planta_control_calidad_id(int planta_control_calidad_id)
{
    Planta_Control_Calidad_ID = planta_control_calidad_id;
}

std::string Lote::get_ubicacion_actual() const
{
    return Ubicacion_Actual;
}

void Lote::set_ubicacion_actual(const std::string& ubicacion_actual)
{
    Ubicacion_Actual = ubicacion_actual;
}

int Lote::get_distribucion_id() const
{
    return Distribucion_ID;
}

void Lote::set_distribucion_id(int distribucion_id)
{
    Distribucion_ID = distribucion_id;
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
