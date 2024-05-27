#pragma once
#include <list>

#include "../../Business/Models/Embarcacion.h"

class EmbarcacionDAO
{
public:
    void save(Embarcacion embarcacion);
    Embarcacion findById(int id);
    std::list<Embarcacion> findAll();
};
