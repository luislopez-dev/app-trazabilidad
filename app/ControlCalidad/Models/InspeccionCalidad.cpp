#include "InspeccionCalidad.h"

int InspeccionCalidad::get_id() const
{
    return id;
}

void InspeccionCalidad::set_id(int id)
{
    this->id = id;
}

int InspeccionCalidad::get_planta_control_calidad_id() const
{
    return planta_control_calidad_id;
}

void InspeccionCalidad::set_planta_control_calidad_id(int planta_control_calidad_id)
{
    this->planta_control_calidad_id = planta_control_calidad_id;
}

int InspeccionCalidad::get_lote_id() const
{
    return lote_id;
}

void InspeccionCalidad::set_lote_id(int lote_id)
{
    this->lote_id = lote_id;
}

std::string InspeccionCalidad::get_medicion_acidez() const
{
    return medicion_acidez;
}

void InspeccionCalidad::set_medicion_acidez(const std::string& medicion_acidez)
{
    this->medicion_acidez = medicion_acidez;
}

std::string InspeccionCalidad::get_medicion_dulzura() const
{
    return medicion_dulzura;
}

void InspeccionCalidad::set_medicion_dulzura(const std::string& medicion_dulzura)
{
    this->medicion_dulzura = medicion_dulzura;
}

std::string InspeccionCalidad::get_prueba_aroma() const
{
    return prueba_aroma;
}

void InspeccionCalidad::set_prueba_aroma(const std::string& prueba_aroma)
{
    this->prueba_aroma = prueba_aroma;
}

std::string InspeccionCalidad::get_fecha() const
{
    return fecha;
}

void InspeccionCalidad::set_fecha(const std::string& fecha)
{
    this->fecha = fecha;
}
