#pragma once
#include <string>

#include "../../Shared/Util/DateTime.h"

using namespace std;

class Durazno
{
    private:
        int id;
        string color;
        string tamano;
        double precio = 4; // En quetzales
        int lote_id;
        string fecha_cosecha = DateTime::getCurrentDateTime();

    public:
        int get_id() const;
        void set_id(int id);
        string get_color() const;
        void set_color(const string& color);
        string get_tamano() const;
        void set_tamano(const string& tamano);
        double get_precio() const;
        void set_precio(double precio);
        int get_lote_id() const;
        void set_lote_id(int lote_id);
        string get_fecha_cosecha() const;
        void set_fecha_cosecha(const string& fecha_cosecha);
};


