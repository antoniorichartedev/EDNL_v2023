//
// Created by Anton on 05/03/2023.
//

#ifndef ABIN_P2_EJ2_HPP
#define ABIN_P2_EJ2_HPP
#include "Abin_enlazada.hpp"

template <typename T>
Abin<T> Abinreflejado(const Abin<T>& A){
    // creamos árbol.
    Abin<T> B;

    // insertamos raíz de A a B.
    if(A.arbolVacio()){
        return B;
    }else{
        B.insertarRaiz(A.elemento(A.raiz()));
        Abinreflejado_Rec(A.raiz(), A, B.raiz(), B);
        return B;
    }
}

template <typename T>
void Abinreflejado_Rec(typename Abin<T>::nodo nA, const Abin<T>& A, typename Abin<T>::nodo nB, Abin<T>& B){

    if(A.hijoIzqdo(nB) != Abin<T>::NODO_NULO){
        B.insertarHijoDrcho(nB, A.elemento(A.hijoIzqdo(nA)));
        Abinreflejado_Rec(A.hijoIzqdo(nA), A, B.hijoDrcho(nB), B);
    }
    if(A.hijoDrcho(nA) != Abin<T>::NODO_NULO){
        B.insertarHijoIzqdo(nB, A.elemento(A.hijoDrcho(nA)));
        Abinreflejado_Rec(A.hijoDrcho(nA), A, B.hijoIzqdo(nB), B);
    }


}
#endif //ABIN_P2_EJ2_HPP
