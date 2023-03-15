//
// Created by Anton on 14/03/2023.
//

#ifndef AGEN_P3_ALTURAAGEN_HPP
#define AGEN_P3_ALTURAAGEN_HPP
#include "Agen.h"

template <typename T>
int Altura(const Agen<T>& A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO){
        return -1;
    }
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        if(hijo != Agen<T>::NODO_NULO){
            return 1 + std::max(Altura(A, hijo), Altura(A, A.hermDrcho(hijo)));
            //hijo = A.hermDrcho(hijo);
        }
    }
}
#endif //AGEN_P3_ALTURAAGEN_HPP
