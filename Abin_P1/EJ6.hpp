//
// Created by antonio on 20/02/23.
//

#ifndef P1_EJ6_HPP
#define P1_EJ6_HPP

#include "Abin_enlazada.hpp"
#include "EJ2.hpp"


template <typename T>
int DesequilibrioAbin(const Abin<T>& A){
    typename Abin<T>::nodo n = A.raiz();
    int desequilibrio = 0;

    if (n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        int alturasubarbolIZQ = Altura(A, A.hijoIzqdo(n));
        int alturasubarbolDER = Altura(A, A.hijoDrcho(n));

        // calculamos el desequilibrio.
        desequilibrio = std::abs(alturasubarbolIZQ - alturasubarbolDER);
    }

    return desequilibrio;
}
#endif //P1_EJ6_HPP
