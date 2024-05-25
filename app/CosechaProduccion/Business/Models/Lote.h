#pragma once
#include <string>

class Lote
{
public:
    int unidades;
    std::string descripcion;

    int get_unidades() const;
    void set_unidades(int unidades);
    std::string get_descripcion() const;
    void set_descripcion(const std::string& descripcion);
};
