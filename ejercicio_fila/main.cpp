#include <iostream>
#include "custom_stack.h"

int main() {

    CustomStack mi_pila;

    mi_pila.push(1);
    mi_pila.push(2);
    mi_pila.push(3);

    std::cout << "Tope de la pila: "
              << mi_pila.top() << std::endl;

    std::cout << "Tamano: "
              << mi_pila.size() << std::endl;

    mi_pila.pop();

    std::cout << "Nuevo tope: "
              << mi_pila.top() << std::endl;

    return 0;
}
