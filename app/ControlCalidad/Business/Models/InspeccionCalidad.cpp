#include "InspeccionCalidad.h"

int InspeccionCalidad::get_id() const
{
    return id;
}

void InspeccionCalidad::set_id(int id)
{
    this->id = id;
}

int InspeccionCalidad::get_planta_id() const
{
    return planta_id;
}

void InspeccionCalidad::set_planta_id(int planta_id)
{
    this->planta_id = planta_id;
}

int InspeccionCalidad::get_inspector_calidad_id() const
{
    return inspector_calidad_id;
}

void InspeccionCalidad::set_inspector_calidad_id(int inspector_calidad_id)
{
    this->inspector_calidad_id = inspector_calidad_id;
}

std::string InspeccionCalidad::get_medicion_acidez() const
{
    return medicion_acidez;
}

void InspeccionCalidad::set_medicion_acidez(const std::string& medicion_acidez)
{
    this->medicion_acidez = medicion_acidez;
}

std::string InspeccionCalidad::get_prueba_sabor_aroma() const
{
    return prueba_sabor_aroma;
}

void InspeccionCalidad::set_prueba_sabor_aroma(const std::string& prueba_sabor_aroma)
{
    this->prueba_sabor_aroma = prueba_sabor_aroma;
}
