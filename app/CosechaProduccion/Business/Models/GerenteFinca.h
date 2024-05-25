#pragma once
#include <string>

class GerenteFinca
{
public:
    int id;
    std::string nombre;
    int finca_id;

    int get_id() const;
    void set_id(int id);
    std::string get_nombre() const;
    void set_nombre(const std::string& nombre);
    int get_finca_id() const;
    void set_finca_id(int finca_id);
};
