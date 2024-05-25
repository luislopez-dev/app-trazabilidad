#pragma once
#include <string>

class Finca
{
public:
    int id;
    std::string nombre;
    std::string direccion;

    int get_id() const;
    void set_id(int id);
    std::string get_nombre() const;
    void set_nombre(const std::string& nombre);
    std::string get_direccion() const;
    void set_direccion(const std::string& direccion);
};
