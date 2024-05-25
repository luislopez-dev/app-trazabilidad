#pragma once
#include <string>
using namespace std;

class Durazno
{
    public:
        int id;
        string color;
        string tamano;
        float precio;
        int finca_id;
        string fecha_cosecha;

        int get_id() const;
        void set_id(int id);
        string get_color() const;
        void set_color(const string& color);
        string get_tamano() const;
        void set_tamano(const string& tamano);
        float get_precio() const;
        void set_precio(float precio);
        int get_finca_id() const;
        void set_finca_id(int finca_id);
        string get_fecha_cosecha() const;
        void set_fecha_cosecha(const string& fecha_cosecha);
};


