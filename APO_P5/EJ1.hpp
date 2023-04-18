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

void eliminarnodo(Abin<int>& A, int x){

    // primero, buscamos el nodo a eliminar.
    typename Abin<int>::nodo nodobuscar = Buscar(A.raiz(), A, x);

    cout << "\nEl nodo que buscabas tiene como elemento -> " << A.elemento(nodobuscar) << ". \n" << endl;

    cout << "Vamos a eliminar el nodo que hemos buscado.\n" << endl;

    // si lo hemos encontrado, eliminamos dicho elemento.
    if(nodobuscar != Abin<int>::NODO_NULO){
        // si nodobuscar es igual al hizq del padre de nodobuscar, quiere decir
        // que nodobuscar es hizq.
        if(nodobuscar == A.hijoIzqdo(A.padre(nodobuscar))){
            A.eliminarHijoIzqdo(nodobuscar);

            // De forma análoga para el hder.
        }else if(nodobuscar == A.hijoDrcho(A.padre(nodobuscar))){
            A.eliminarHijoDrcho(nodobuscar);
        }
    }
}

#endif //APO_P5_EJ1_HPP
