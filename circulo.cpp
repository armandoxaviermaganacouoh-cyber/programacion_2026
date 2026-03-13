#include <iostream>
#include "circulo.h"

Circulo::Circulo(std::string nombre,double radio) : Figura(nombre){
    this-> radio= radio;
}

double Circulo :: calcularArea() {
    return 3.1416 * radio * radio;

}

void Circulo::describir() {
    std::cout << " Figura: " << nombre << ", radio: " << radio << std::endl;
}

double Circulo::obtenerRadio(){
    return radio;
}