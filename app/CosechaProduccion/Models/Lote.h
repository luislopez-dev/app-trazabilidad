#pragma once
#include <list>
#include <string>

#include "Durazno.h"

class Lote
{
private:
    int id;
    int Finca_ID = 1; // Default value
    std::string Ubicacion_Actual;
    std::string descripcion = "";
    std::list<Durazno> duraznos;
    string creacion = DateTime::getCurrentDateTime();
    
public:
    int get_id() const;
    void set_id(int id);
    int get_finca_id() const;
    void set_finca_id(int finca_id);

    std::string get_ubicacion_actual() const;
    void set_ubicacion_actual(const std::string& ubicacion_actual);

    std::string get_descripcion() const;
    void set_descripcion(const std::string& descripcion);
    std::list<Durazno> get_duraznos() const;
    void set_duraznos(const std::list<Durazno>& duraznos);
    string get_creacion() const;
    void set_creacion(const string& creacion);
};
