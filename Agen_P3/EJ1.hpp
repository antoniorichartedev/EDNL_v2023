//
// Created by Anton on 13/03/2023.
//

#ifndef AGEN_P3_EJ1_HPP
#define AGEN_P3_EJ1_HPP
#include "Agen.h"
#include <algorithm>

template <typename T>
int NumHijosAgen (typename Agen<T>::nodo n, const Agen<T>& A){
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
        return 0;
    }else{
        return NumHermanos(A.hijoIzqdo(n), A);
    }
}

template <typename T>
int NumHermanos(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        return 1 + NumHermanos(A.hermDrcho(n), A);
    }
}
//----------------------------------------------------------------------------------

template <typename T>
int GradoAgen(typename Agen<T>::nodo n, const Agen<T>& A);

template <typename T>
int GradoAgen(const Agen<T>& A){
    return GradoAgen(A.raiz(), A);
}

template <typename T>
int GradoAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        return 1 + std::max(NumHijosAgen(A.hijoIzqdo(n), A), NumHijosAgen(A.hermDrcho(A.hijoIzqdo(n)), A));
        /*int grado = NumHijosAgen(n, A);

        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            grado = std::max(grado, GradoAgen(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return grado;*/
    }

}
#endif //AGEN_P3_EJ1_HPP
