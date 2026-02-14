#ifndef CELULAR_H
#define CELULAR_H

#include <string>

class Celular {
private:
    // Atributos
    std::string marca;
    std::string modelo;
    int almacenamiento;   // en GB
    int ram;              // en GB
    float precio;         // en moneda local

public:
    // Constructor
    Celular(std::string _marca, std::string _modelo, int _almacenamiento, int _ram, float _precio);

    // Métodos
    void mostrarInfo();        // Muestra la información del celular
    void actualizarPrecio(float nuevoPrecio); // Cambia el precio
    bool comparar(Celular otro); // Compara si dos celulares son del mismo modelo
};

#endif // CELULAR_H