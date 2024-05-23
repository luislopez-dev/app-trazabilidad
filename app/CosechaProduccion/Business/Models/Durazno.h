#pragma once
#include <string>
using namespace std;

class Durazno
{
    public:
        string color;
        string tamano;

        string get_color() const;
        void set_color(const string& color);
        string get_tamano() const;
        void set_tamano(const string& tamano);
};


