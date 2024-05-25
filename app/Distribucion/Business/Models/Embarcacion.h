#pragma once
#include <string>

class Embarcacion
{
public:
    int id;
    std::string salida;
    std::string llegada;

    int get_id() const;
    void set_id(int id);
    std::string get_salida() const;
    void set_salida(const std::string& salida);
    std::string get_llegada() const;
    void set_llegada(const std::string& llegada);
};
