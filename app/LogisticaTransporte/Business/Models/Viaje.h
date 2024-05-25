#pragma once
#include <string>

class Viaje
{
public:
    int id;
    int gerente_logistica_id;
    int conductor_id;
    std::string salida;
    std::string llegada;
    std::string lugar_origen;
    std::string lugar_destino;

    int get_id() const;
    void set_id(int id);
    int get_gerente_logistica_id() const;
    void set_gerente_logistica_id(int gerente_logistica_id);
    int get_conductor_id() const;
    void set_conductor_id(int conductor_id);
    std::string get_salida() const;
    void set_salida(const std::string& salida);
    std::string get_llegada() const;
    void set_llegada(const std::string& llegada);
    std::string get_lugar_origen() const;
    void set_lugar_origen(const std::string& lugar_origen);
    std::string get_lugar_destino() const;
    void set_lugar_destino(const std::string& lugar_destino);
};
