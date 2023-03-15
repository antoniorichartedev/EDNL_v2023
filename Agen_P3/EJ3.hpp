//
// Created by Anton on 14/03/2023.
//

#ifndef AGEN_P3_EJ3_HPP
#define AGEN_P3_EJ3_HPP
#include "Agen.h"
#include <algorithm>
#include "AlturaAgen.hpp"

template <typename T>
int DesequilibrioAgen(typename Agen<T>::nodo n, const Agen<T>& A);

template <typename T>
int DesequilibrioAgen(const Agen<T>& A){
    return DesequilibrioAgen(A.raiz(), A);
}

template <typename T>
int DesequilibrioAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    if (n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int max = 0, min = 0;

        while(hijo != Agen<T>::NODO_NULO){
            max = std::max(Altura(A, A.hijoIzqdo(hijo)), Altura(A, A.hermDrcho(hijo)));
            min = std::min(Altura(A, A.hijoIzqdo(hijo)), Altura(A, A.hermDrcho(hijo)));
            hijo = A.hermDrcho(hijo);
        }

        int des = std::abs(max - min);
        return des;
    }
}

#endif //AGEN_P3_EJ3_HPP
