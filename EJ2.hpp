//
// Created by antonio on 20/02/23.
//

#ifndef P1_EJ2_HPP
#define P1_EJ2_HPP
#include "Abin_enlazada.hpp"
#include <cmath>


template <typename T>
int Altura(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }
    else{
        return 1 + std::max(Altura(A, A.hijoIzqdo(n)), Altura(A, A.hijoDrcho(n)));
    }


}

/*template <typename T>
int Altura(const Abin<T>& A){
    return Altura(A.raiz(), A);
}*/
#endif //P1_EJ2_HPP
