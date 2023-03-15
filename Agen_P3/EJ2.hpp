//
// Created by Anton on 13/03/2023.
//

#ifndef AGEN_P3_EJ2_HPP
#define AGEN_P3_EJ2_HPP
#include "Agen.h"

template <typename T>
int Profundidad(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return -1;
    }
    else{
        return 1 + Profundidad(A.padre(n), A);
    }
}
#endif //AGEN_P3_EJ2_HPP
