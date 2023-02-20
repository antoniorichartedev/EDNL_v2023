#include "Abin_enlazada.hpp"

template <typename T>
int NumNodos(typename Abin<T>::nodo n, const Abin<T> A){
    if(n == Abin<T>::NODO_NULO){
        return 0;   // no hay nodo raíz, devolvemos 0;
    }
    else{
        if (A.hijoIzqdo(n) == Abin<T>::NODO_NULO and A.hijoDrcho(n) == Abin<T>::NODO_NULO){
            // si no tiene hijos, devolvemos 0.
            return 0;
        }
        else if (A.hijoIzqdo(n) != Abin<T>::NODO_NULO){
            return 1 + NumNodos(A.hijoIzqdo(n), A) + NumNodos(A.hijoDrcho(n), A);
        }
        else if (A.hijoDrcho(n) != Abin<T>::NODO_NULO){
            return 1 + NumNodos(A.hijoIzqdo(n), A) + NumNodos(A.hijoDrcho(n), A);
        }
    }
}

template <typename T>
int NumNodos(const Abin<T> A){
    return NumNodos(A.raiz(), A);
}
