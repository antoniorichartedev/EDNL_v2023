//
// Created by antonio on 19/04/23.
//

#ifndef REPASOEXAMENARBOLES_ABINREFLEJADO_HPP
#define REPASOEXAMENARBOLES_ABINREFLEJADO_HPP
#include "../Abin_P1/Abin_enlazada.hpp"

template <typename T>
bool AbinesReflejado_rec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return true;
    }else if (n == A.raiz()){
        return false;
    }else{
        if(n == A.hijoIzqdo(A.padre(n))){
            if(A.elemento(n) == A.elemento(A.hijoDrcho(A.padre(n)))){
                return AbinesReflejado_rec(A.hijoIzqdo(n), A) and AbinesReflejado_rec(A.hijoDrcho(n), A);
            }else{
                return false;
            }
        }else{
            if(A.elemento(n) == A.elemento(A.hijoIzqdo(A.padre(n)))){
                return AbinesReflejado_rec(A.hijoIzqdo(n), A) and AbinesReflejado_rec(A.hijoDrcho(n), A);
            }else{
                return false;
            }
        }
    }
}

template <typename T>
int NumNodosReflejados(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        int NodosReflejos = 0;
        if(AbinesReflejado_rec(n, A)){
            NodosReflejos = 1;
        }
        return NodosReflejos + NumNodosReflejados(A.hijoIzqdo(n), A) + NumNodosReflejados(A.hijoDrcho(n), A);
    }
}

template <typename T>
int NumNodosReflejados(const Abin<T>& A){
    if(A.arbolVacio()){
        return 0;
    }else{
        return NumNodosReflejados(A.raiz(), A);
    }
}



#endif //REPASOEXAMENARBOLES_ABINREFLEJADO_HPP
