//
// Created by antonio on 19/04/23.
//

#ifndef REPASOEXAMENARBOLES_MAXDIFERENCIANODOSHOJAAGEN_HPP
#define REPASOEXAMENARBOLES_MAXDIFERENCIANODOSHOJAAGEN_HPP
#include "../Agen_P3/Agen.h"
#include <algorithm>

template <typename T>
int NumNodosHojaAgen_rec(typename Agen<T>::nodo n, const Agen<T>& A){

    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else if (A.hijoIzqdo(n) == Agen<T>::NODO_NULO){ // el nodo es hoja.
        return 1;
    }else{  // el nodo no es hoja.
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int nodoshojas = 0;
        while(hijo != Agen<T>::NODO_NULO){
            nodoshojas += NumNodosHojaAgen_rec(hijo, A);
            hijo = A.hermDrcho(hijo);
        }
        return nodoshojas;
    }
}

template <typename T>
int NumNodosHojaAgen(const Agen<T>& A){
    return NumNodosHojaAgen_rec(A.raiz(), A);
}

template <typename T>
int DesequilibrioAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    if (n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int max = 0, min = NumNodosHojaAgen_rec(n, A);


        while(hijo != Agen<T>::NODO_NULO){
            max = std::max(max, NumNodosHojaAgen_rec(hijo, A));
            min = std::min(min, NumNodosHojaAgen_rec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }

        int des = std::abs(max - min);
        return des;
    }
}

template <typename T>
int DesequilibrioAgen(const Agen<T>& A){
    return DesequilibrioAgen(A.raiz(), A);
}
#endif //REPASOEXAMENARBOLES_MAXDIFERENCIANODOSHOJAAGEN_HPP
