#pragma once
#include <string>

class PlantaControlCalidad
{
    private:
        int ID;
        std::string Direccion;
        std::string Nombre;
    public:
        int get_id() const;
        void set_id(int id);
        std::string get_direccion() const;
        void set_direccion(const std::string& direccion);
        std::string get_nombre() const;
        void set_nombre(const std::string& nombre);
};
