#pragma once
#include <string>

class GerentePlanta
{
public:
    int id;
    std::string name;
    int planta_id;
    
    int get_id() const;
    void set_id(int id);
    std::string get_name() const;
    void set_name(const std::string& name);
    int get_planta_id() const;
    void set_planta_id(int planta_id);
};
