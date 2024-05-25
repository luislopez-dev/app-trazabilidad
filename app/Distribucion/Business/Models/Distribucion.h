#pragma once
#include <string>

class Distribucion
{
public:
    int id;
    std::string destino;
    std::string fecha_reparticion;

    int get_id() const;
    void set_id(int id);
    std::string get_destino() const;
    void set_destino(const std::string& destino);
    std::string get_fecha_reparticion() const;
    void set_fecha_reparticion(const std::string& fecha_reparticion);
};
