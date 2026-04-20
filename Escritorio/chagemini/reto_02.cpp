#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>

std::string obtenerHoraActual() {
    auto ahora =std::chrono::system_clock::now();
    std::time_t tiempo = std::chrono::system_clock::to_time_t(ahora);
    std::tm* tm=std::localtime(&tiempo);

    std::ostringstream oss;
    oss << std::put_time(tm, "%H:%M:%S");
    return oss.str();

}

int main() {
    std::ofstream archivo("mensajes.txt", std::ios::app); // "app" agrega al final
    std::string entrada;

    if (!archivo) {
        std::cerr << "Error al abrir el archivo.\n";
        return 1;
    }

    std::cout << "Escribe mensajes (escribe 'salir' para terminar):\n";

    while (true) {
        std::getline(std::cin, entrada);
        if (entrada == "salir") break;
        archivo << entrada << std::endl;
    }

    archivo.close();
    std::cout << "Mensajes guardados en 'mensajes.txt'.\n";

    return 0;
}
