#include <iostream>
#include "figura.h"
#include "circulo.h"
#include "Rectangulo.h"

int main (){
    std::cout <<"==Sistema de Figuras Geomegtricas (polimorfismo)==="<<std::endl;
    std::cout <<std::endl;

    Figura* f1 = new Circulo("Circulo",2.0);
    Figura* f2 = new Rectangulo("Rectangulo", 9.0  ,10.0 );

    std::cout << "---figura 1 (circulo)---"<< std::endl;
    f1->describir();
    std::cout << " Area "<< f1-> calcularArea() << std::endl;
    std::cout << std::endl;

    std::cout<< "---Figura 2 (Rectangulo)---" << std::endl;
    f2-> describir();
    std::cout<< " Area  " << f2->calcularArea() << std::endl;
    std::cout<<std::endl;

    std::cout << "---tratamiento uniforme con Figura*---"<< std::endl;
    Figura* figuras[] = {f1,f2};
    for(int i = 0; i < 2; i++){
    figuras[i]->describir();
    std::cout<< "Area " << figuras[i]->calcularArea()<< std::endl;
    }

delete f1;
delete f2;

return 0;
}
