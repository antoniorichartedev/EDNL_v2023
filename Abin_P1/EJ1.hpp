#ifndef P1_EJ1_HPP
#define P1_EJ1_HPP

#include "Abin_enlazada.hpp"


template <typename T>
int NumNodos(const Abin<T>& A){
    return NumNodos(A.raiz(), A);
}


template <typename T>
int NumNodos(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 0;   // no hay nodo, devolvemos 0;
    }
    else{
        return 1 + NumNodos(A.hijoIzqdo(n), A) + NumNodos(A.hijoDrcho(n), A);
    }
}
#endif //P1_EJ1_HPP