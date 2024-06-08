#pragma once
#include <list>
#include <string>

#include "Durazno.h"

class Lote
{
private:
    int id;
    int Finca_ID = 1; // Default value
    int Embarcacion_ID;
    int Planta_Control_Calidad_ID;
    int Distribucion_ID;
    std::string Ubicacion_Actual;
    std::string descripcion = "";
    std::list<Durazno> duraznos;
    string creacion = DateTime::getCurrentDateTime();
    
public:
    int get_id() const;
    void set_id(int id);
    int get_finca_id() const;
    void set_finca_id(int finca_id);

    int get_embarcacion_id() const;
    void set_embarcacion_id(int embarcacion_id);

    int get_planta_control_calidad_id() const;
    void set_planta_control_calidad_id(int planta_control_calidad_id);

    std::string get_ubicacion_actual() const;
    void set_ubicacion_actual(const std::string& ubicacion_actual);


    int get_distribucion_id() const;
    void set_distribucion_id(int distribucion_id);

    string get_creacion() const;
    void set_creacion(const string& creacion);

    std::list<Durazno> get_duraznos() const;
    void set_duraznos(const std::list<Durazno>& duraznos);
};
