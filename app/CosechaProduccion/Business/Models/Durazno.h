#pragma once
#include <string>
using namespace std;

class Durazno
{
    public:
        string color;
        string tamaño;

        string get_color() const;
        void set_color(const string& color);
        string get_tamaño() const;
        void set_tamaño(const string& tamaño);
};


