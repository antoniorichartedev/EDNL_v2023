//
// Created by antonio on 19/04/23.
//

#ifndef AGEN_P3_NUMNODOSAGEN_HPP
#define AGEN_P3_NUMNODOSAGEN_HPP
#include "Agen.h"

template <typename T>
int NumNodosAgen_rec(typename Agen<T>::nodo n, const Agen<T>& A);

template <typename T>
int NumNodosAgen(const Agen<T>& A){
    return NumNodosAgen_rec(A.raiz(),A);
}

template <typename T>
int NumNodosAgen_rec(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        int nodos = 0;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            nodos += NumNodosAgen_rec(hijo, A);
            hijo = A.hermDrcho(hijo);
        }
        return 1 + nodos;
    }

}
#endif //AGEN_P3_NUMNODOSAGEN_HPP
