#pragma once
#include <string>

#include "../../Shared/Util/DateTime.h"

class Distribucion
{
public:
    int id;
    std::string tienda_destino_nombre;
    std::string tienda_destino_direccion;
    std::string fecha_reparticion = DateTime::getCurrentDateTime();

    int get_id() const;
    void set_id(int id);
    std::string get_tienda_destino_nombre() const;
    void set_tienda_destino_nombre(const std::string& tienda_destino_nombre);
    std::string get_tienda_destino_direccion() const;
    void set_tienda_destino_direccion(const std::string& tienda_destino_direccion);
    std::string get_fecha_reparticion() const;
    void set_fecha_reparticion(const std::string& fecha_reparticion);
};
