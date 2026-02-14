#include "Celular.h"
#include <iostream>

// Constructor
Celular::Celular(std::string _marca, std::string _modelo, int _almacenamiento, int _ram, float _precio) {
    marca = _marca;
    modelo = _modelo;
    almacenamiento = _almacenamiento;
    ram = _ram;
    precio = _precio;
}

// Método para mostrar la información del celular
void Celular::mostrarInfo() {
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Almacenamiento: " << almacenamiento << " GB" << std::endl;
    std::cout << "RAM: " << ram << " GB" << std::endl;
    std::cout << "Precio: $" << precio << std::endl;
}

// Método para actualizar el precio
void Celular::actualizarPrecio(float nuevoPrecio) {
    precio = nuevoPrecio;
    std::cout << "El nuevo precio del celular es: $" << precio << std::endl;
}

// Método para comparar si dos celulares son del mismo modelo
bool Celular::comparar(Celular otro) {
    return modelo == otro.modelo;
}



