//
// Created by Anton on 14/03/2023.
//

#ifndef AGEN_P3_EJ4_HPP
#define AGEN_P3_EJ4_HPP
#include "Agen.h"
#include "buscarAgen.hpp"

void poda(int x, Agen<int>& A, typename Agen<int>::nodo buscarnodo);

void poda(int x, Agen<int>& A){
    poda(x, A, BuscarAgen(x, A, A.raiz()));
}

void poda(int x, Agen<int>& A, typename Agen<int>::nodo buscarnodo){
    if (buscarnodo != Agen<int>::NODO_NULO){
        typename Agen<int>::nodo hijo = A.hijoIzqdo(buscarnodo);
        while(hijo != Agen<int>::NODO_NULO){
            poda(x, A, hijo);
            hijo = A.hermDrcho(hijo);
        }

        while(A.hijoIzqdo(buscarnodo) != Agen<int>::NODO_NULO){
            A.eliminarHijoIzqdo(buscarnodo);
        }
    }
}
#endif //AGEN_P3_EJ4_HPP
