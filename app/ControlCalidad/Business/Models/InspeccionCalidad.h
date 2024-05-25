#pragma once
#include <string>

class InspeccionCalidad
{
public:
    int id;
    int planta_id;
    int inspector_calidad_id;
    std::string medicion_acidez;
    std::string prueba_sabor_aroma;

    int get_id() const;
    void set_id(int id);
    int get_planta_id() const;
    void set_planta_id(int planta_id);
    int get_inspector_calidad_id() const;
    void set_inspector_calidad_id(int inspector_calidad_id);
    std::string get_medicion_acidez() const;
    void set_medicion_acidez(const std::string& medicion_acidez);
    std::string get_prueba_sabor_aroma() const;
    void set_prueba_sabor_aroma(const std::string& prueba_sabor_aroma);
};
