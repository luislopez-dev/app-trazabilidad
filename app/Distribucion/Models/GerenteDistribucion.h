#pragma once
#include <string>

class GerenteDistribucion
{
public:
    int id;
    std::string nombre;

    int get_id() const;
    void set_id(int id);
    std::string get_nombre() const;
    void set_nombre(const std::string& nombre);
};
