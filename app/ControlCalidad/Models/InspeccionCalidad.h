#pragma once
#include <string>

#include "../../Shared/Util/DateTime.h"

class InspeccionCalidad
{
public:
    int id;
    int planta_control_calidad_id = 1; // Planta con ID 1 - planta por defecto
    int lote_id;
    std::string medicion_acidez;
    std::string medicion_dulzura;
    std::string prueba_aroma;
    std::string fecha = DateTime::getCurrentDateTime();

    int get_id() const;
    void set_id(int id);
    int get_planta_control_calidad_id() const;
    void set_planta_control_calidad_id(int planta_control_calidad_id);
    int get_lote_id() const;
    void set_lote_id(int lote_id);
    std::string get_medicion_acidez() const;
    void set_medicion_acidez(const std::string& medicion_acidez);
    std::string get_medicion_dulzura() const;
    void set_medicion_dulzura(const std::string& medicion_dulzura);
    std::string get_prueba_aroma() const;
    void set_prueba_aroma(const std::string& prueba_aroma);
    std::string get_fecha() const;
    void set_fecha(const std::string& fecha);
};
