#pragma once
#include <string>

#include "../../Shared/Util/DateTime.h"

class Embarcacion
{
    private:
        int ID;
        std::string Puerto_Base;
        std::string Fecha_Salida = DateTime::getCurrentDateTime();

    public:
        int get_id() const;
        void set_id(int id);
        std::string get_puerto_base() const;
        void set_puerto_base(const std::string& puerto_base);
        std::string get_fecha_salida() const;
        void set_fecha_salida(const std::string& fecha_salida);
};
