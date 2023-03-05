//
// Created by Anton on 05/03/2023.
//

#ifndef EDNL_EJ7_HPP
#define EDNL_EJ7_HPP
#include "Abin_enlazada.hpp"
#include "EJ2.hpp"

template <typename T>
int NumHijos(typename Abin<T>::nodo n, const Abin<T>& A){
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO and A.hijoDrcho(n) == Abin<T>::NODO_NULO){
        return 0;
    }
    else if (A.hijoIzqdo(n) == Abin<T>::NODO_NULO or A.hijoDrcho(n) == Abin<T>::NODO_NULO){
        return 1;
    }
    else if (A.hijoIzqdo(n) != Abin<T>::NODO_NULO and A.hijoDrcho(n) != Abin<T>::NODO_NULO){
        return 2;
    }
}

template <typename T>
bool Abinpseudocompleto(const Abin<T>& A){
    // árbol vacío.
    if(A.arbolVacio()){
        return true;
    }

        // raíz no tiene hijos.
    else if(NumHijos(A.raiz(), A) == 0){
        return true;
    }

    else {
        return Abinpseudocompleto(A.raiz(), A);
    }
}

template <typename T>
bool Abinpseudocompleto(typename Abin<T>::nodo nodo, const Abin<T>& A){

    // si la altura es 1, estamos en el penúltimo nivel.
    if(Altura(A, nodo) == 1){
        return (NumHijos(nodo,A) == 2 or NumHijos(nodo,A) == 0);
    }else{
        return (Abinpseudocompleto(A.hijoIzqdo(nodo), A) and Abinpseudocompleto(A.hijoDrcho(nodo), A));
    }
}
#endif //EDNL_EJ7_HPP
