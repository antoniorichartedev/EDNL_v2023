//
// Created by antonio on 12/04/23.
//

#ifndef APO_P5_EJ1_HPP
#define APO_P5_EJ1_HPP
#include "../Abin_P1/Abin_enlazada.hpp"


template <typename T>
typename Abin<T>::nodo Buscar(typename Abin<T>::nodo n, const Abin<T>& A, int x){
    if (n == Abin<T>::NODO_NULO || A.elemento(n) == x){
        return n;
    }
    else{
        typename Abin<T>::nodo aux = Buscar(A.hijoIzqdo(n), A, x);
        if (aux == Abin<T>::NODO_NULO){
            aux = Buscar(A.hijoDrcho(n), A, x);
            return aux;
        }
        return aux;
    }
}

void eliminarnodo(Abin<int>& A, typename Abin<int>::nodo n, int x){

    // primero, buscamos el nodo a eliminar.
    typename Abin<int>::nodo nodobuscar = Buscar(A.raiz(), A, x);

    // si lo hemos encontrado, eliminamos dicho elemento.
    if(nodobuscar != Abin<int>::NODO_NULO){
        // hay que pensarlo un poco, habría que saber QUE hijo es,
        // si hizq o hder.
    }
}

#endif //APO_P5_EJ1_HPP
