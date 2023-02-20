//
// Created by antonio on 20/02/23.
//

#ifndef P1_EJ3_HPP
#define P1_EJ3_HPP
#include "Abin_enlazada.hpp"

template <typename T>
int Profundidad(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + Profundidad(A.padre(n), A);
    }
}
#endif //P1_EJ3_HPP
