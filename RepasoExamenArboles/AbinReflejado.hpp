//
// Created by antonio on 19/04/23.
//

#ifndef REPASOEXAMENARBOLES_ABINREFLEJADO_HPP
#define REPASOEXAMENARBOLES_ABINREFLEJADO_HPP
#include "../Abin_P1/Abin_enlazada.hpp"

template <typename T>
bool AbinesReflejado(const Abin<T>& A){
    return AbinesReflejado_rec(A.raiz(), A);
}

template <typename T>
bool AbinesReflejado_rec(typename Abin<T>::nodo n, const Abin<T>& A){

}

template <typename T>
int NumNodosReflejados(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        return AbinesReflejado_rec(n, A) + NumNodosReflejados(A.hijoIzqdo(n), A) + NumNodosReflejados(A.hijoDrcho(n), A);
    }
}
#endif //REPASOEXAMENARBOLES_ABINREFLEJADO_HPP
