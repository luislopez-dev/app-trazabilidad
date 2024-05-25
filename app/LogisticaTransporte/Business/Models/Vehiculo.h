#pragma once
#include <string>

class Vehiculo
{
public:
    int placa;
    std::string marca;
    std::string modelo;

    int get_placa() const;
    void set_placa(int placa);
    std::string get_marca() const;
    void set_marca(const std::string& marca);
    std::string get_modelo() const;
    void set_modelo(const std::string& modelo);
};
