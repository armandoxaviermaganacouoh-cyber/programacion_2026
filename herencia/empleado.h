#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

class Empleado {
protected:
    std::string nombre;
    std::string id;
    float salarioBase;

public:
    // Constructores
    Empleado();
    Empleado(std::string nombre, std::string id, float salarioBase);

    // Métodos setters
    void actualizarNombre(std::string nombre);
    void actualizarId(std::string id);
    void actualizarSalarioBase(float salarioBase);

    // Métodos getters
    std::string obtenerNombre() const;
    std::string obtenerId() const;
    float obtenerSalarioBase() const;

    // Mostrar información
    virtual void mostrarInformacion() const;
};

#endif