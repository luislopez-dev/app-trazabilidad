#pragma once
#include "../Models/Embarcacion.h"

class EmbarcacionDAO
{
public:
    static void saveEmbarcacion(Embarcacion* embarcacion);
    static int findLastId();
};
