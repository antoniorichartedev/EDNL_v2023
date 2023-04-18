//
// Created by antonio on 18/04/23.
//

#ifndef APO_P5_APO_E_S_HPP
#define APO_P5_APO_E_S_HPP
#include "apo.hpp"
#include <iostream>

using namespace std;

template <typename T>
void imprimirApo (const Apo<T>& A)
// Post: Muestra los nodos de A en la salida estándar.
{
    if (!A.vacio())
    {
        cout << "Raíz del árbol: "
             << A.elemento(A.cima()) << endl;
        imprimirDescendientesApo(A.cima(), A);
    }
    else
        cout << "Árbol vacío\n";
}

template <typename T>
void imprimirDescendientesApo (typename Apo<T>::nodo n, const Apo<T>& A)
// Post: Muestra los descendientes de n en la salida estándar.
{
    if (A.izqdo() != A.izqdo().vacio())
    {
        cout << "Hijo izqdo de " << A.elemento(n) << ": "
             << A.elemento(A.hijoIzqdo(n)) << endl;
        imprimirDescendientes(A.hijoIzqdo(n), A);
    }
    if (A.drcho() != A.drcho().vacio())
    {
        cout << "Hijo derecho de " << A.elemento(n) << ": "
             << A.elemento(A.drcho(n)) << endl;
        imprimirDescendientes(A.drcho(n), A);
    }
}

#endif //APO_P5_APO_E_S_HPP
