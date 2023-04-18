//
// Created by antonio on 22/03/23.
//

#ifndef ABB_P4_ABB_E_S_HPP
#define ABB_P4_ABB_E_S_HPP
#include "Abb.hpp"
#include <iostream>

template<typename t>
void rellenarAbb(Abb<t>& A, const t& fin){
    t x = t();
    std::cout << "Introduce la raíz: ";
    std::cin >> x;
    while(x != fin){
        std::cout << "Introduce el elemento: ";
        A.insertar(x);
        std::cin >> x;
    }
}

template<typename t>
void imprimirAbb(const Abb<t>& A){
    if(A.vacio())
        std::cout << "Arbol vacio" << std::endl;
    else{
        std::cout << A.elemento() << std::endl;
        if(!A.izqdo().vacio()){
            std::cout << "Hijo izquierdo de " << A.elemento() << ": ";
            imprimirAbb(A.izqdo());
        }
        if(!A.drcho().vacio()){
            std::cout << "Hijo derecho de " << A.elemento() << ": ";
            imprimirAbb(A.drcho());
        }
    }
}
#endif //ABB_P4_ABB_E_S_HPP
