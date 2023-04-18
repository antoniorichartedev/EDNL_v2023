//
// Created by antonio on 17/04/23.
//

#ifndef APO_P5_EJ4_HPP
#define APO_P5_EJ4_HPP
#include "../Agen_P3/Agen.h"

template <typename T>
int NumhijosAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
        return 0;
    }else{
        int hijos = 0;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            hijos++;
            hijo = A.hermDrcho(hijo);
        }
        return hijos;
    }
}

template <typename T>
bool AgenesTernario(const Agen<T>& A){
    if(A.arbolVacio()) {
       return true;    // Podríamos considerar que un agen vacío es estrictamente ternario.
    }else{
        return AgenesTernario_rec(A.raiz(), A);
    }
}

template <typename T>
bool AgenesTernario_rec(typename Agen<T>::nodo n, const Agen<T>& A){
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

    bool si = true;
    if(NumhijosAgen(hijo, A) == 0){
        return true;
    }else if (NumhijosAgen(hijo, A) == 3){
        while (si and hijo != Agen<T>::NODO_NULO) {
            hijo = A.hermDrcho(hijo);
            si = AgenesTernario_rec(A.hermDrcho(hijo), A);
        }
        return si;
    }else{
        return false;
    }
}
#endif //APO_P5_EJ4_HPP
