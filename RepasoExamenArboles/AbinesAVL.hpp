//
// Created by antonio on 20/04/23.
//

#ifndef REPASOEXAMENARBOLES_ABINESAVL_HPP
#define REPASOEXAMENARBOLES_ABINESAVL_HPP
#include "../Abin_P1/Abin_enlazada.hpp"
#include "../Abin_P1/EJ2.hpp"

template <typename T>
bool AbinesABB_rec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return true;
    }else if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO and A.hijoDrcho(n) != Abin<T>::NODO_NULO){
        if(A.elemento(n) > A.elemento(A.hijoIzqdo(n)) and A.elemento(n) < A.elemento(A.hijoDrcho(n))){
            return AbinesABB_rec(A.hijoIzqdo(n), A) and AbinesABB_rec(A.hijoDrcho(n), A);
        }else{
            return false;
        }
    }else{
        return true;
    }
}

template <typename T>
bool AbinesABB(const Abin<T>& A){
    return AbinesABB_rec(A.raiz(), A);
}

template <typename T>
bool AbinesAVL_rec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(A.arbolVacio()){
        // Como el árbol está vacío, no podemos demostrar que no lo sea o que lo sea, por lo tanto devolvemos true.
        return true;
    }else{
        int factorEQ = (Altura(A, A.hijoIzqdo(n)) - Altura(A, A.hijoDrcho(n)));
        if(factorEQ == 0 or factorEQ == 1 or factorEQ == -1){
            // Si cumple con la condición de AVL, entonces es un AVL.
            return AbinesAVL_rec(A.hijoIzqdo(n), A) and AbinesAVL_rec(A.hijoDrcho(n), A);
        }else{
            return false;
        }
    }
}

template <typename T>
bool AbinesAVL(const Abin<T>& A){
    if(AbinesABB(A)){
        return AbinesAVL_rec(A.raiz(), A);
    }else{
        return false;
    }
}


#endif //REPASOEXAMENARBOLES_ABINESAVL_HPP
