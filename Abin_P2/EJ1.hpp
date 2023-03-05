//
// Created by Anton on 05/03/2023.
//

#ifndef ABIN_P2_EJ1_HPP
#define ABIN_P2_EJ1_HPP
#include "Abin_enlazada.hpp"
#include "../EJ7.hpp"

template <typename T>
bool ReflexAbin(const Abin<T>& A, typename Abin<T>::nodo nA, const Abin<T>& B, typename Abin<T>::nodo nB);

template <typename T>
bool ReflexAbin(const Abin<T>& A, const Abin<T>& B){
    return ReflexAbin(A, A.raiz(), B, B.raiz());
}

template <typename T>
bool ReflexAbin(const Abin<T>& A, typename Abin<T>::nodo nA, const Abin<T>& B, typename Abin<T>::nodo nB){

    if(nA == Abin<T>::NODO_NULO and nB == Abin<T>::NODO_NULO){
        return true;
    }
    else{
        if(nA == Abin<T>::NODO_NULO or nB == Abin<T>::NODO_NULO){
            return false;
        }else{
            return ReflexAbin(A, A.hijoIzqdo(nA), B, B.hijoIzqdo(nB)) and ReflexAbin(A, A.hijoDrcho(nA), B, B.hijoDrcho(nB));
        }
    }


}
#endif //ABIN_P2_EJ1_HPP
