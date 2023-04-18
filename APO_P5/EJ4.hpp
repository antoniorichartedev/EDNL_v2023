//
// Created by antonio on 17/04/23.
//

#ifndef APO_P5_EJ4_HPP
#define APO_P5_EJ4_HPP
#include "../Agen_P3/Agen.h"

template <typename T>
int NumhijosAgen(typename Agen<T>::nodo n, const Agen<T>& A);

template <typename T>
bool AgenesTernario_rec(typename Agen<T>::nodo n, const Agen<T>& A);

template <typename T>
int NumhijosAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    int hijos = 0;
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
        return 0;
    }else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            hijos++;
            hijo = A.hermDrcho(hijo);
        }
    }
    return hijos;
}

template <typename T>
bool AgenesTernario(const Agen<T>& A){
    if(A.arbolVacio()) {
       return true;    // Podríamos considerar que un agen vacío es estrictamente ternario.
    }else if(A.hijoIzqdo(A.raiz()) == Agen<T>::NODO_NULO){
        return true;
    }else{
        return AgenesTernario_rec(A.raiz(), A);
    }
}

template <typename T>
bool AgenesTernario_rec(typename Agen<T>::nodo n, const Agen<T>& A){

    int numHIJOS = NumhijosAgen(n, A);
    if(numHIJOS == 0){
        return true;
    }else if (numHIJOS == 3){
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        bool si = true;
        while (si and hijo != Agen<T>::NODO_NULO) {
            si = AgenesTernario_rec(hijo, A);
            hijo = A.hermDrcho(hijo);
        }
        return si;
    }else{
        return false;
    }
}
#endif //APO_P5_EJ4_HPP
