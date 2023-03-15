//
// Created by Anton on 14/03/2023.
//

#ifndef AGEN_P3_BUSCARAGEN_HPP
#define AGEN_P3_BUSCARAGEN_HPP
#include "Agen.h"

typename Agen<int>::nodo BuscarAgen(int x, const Agen<int>& A, typename Agen<int>::nodo n){
    if (n == Agen<int>::NODO_NULO){
        return Agen<int>::NODO_NULO;
    }else{
        if(A.elemento(n) == x){
            return n;
        }else{
            typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
            while(hijo != Agen<int>::NODO_NULO){
                typename Agen<int>::nodo buscarhijo = BuscarAgen(x, A, hijo);
                if(buscarhijo != Agen<int>::NODO_NULO){
                    return buscarhijo;
                }
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}
#endif //AGEN_P3_BUSCARAGEN_HPP
