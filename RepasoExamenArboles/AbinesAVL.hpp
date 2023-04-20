//
// Created by antonio on 20/04/23.
//

#ifndef REPASOEXAMENARBOLES_ABINESAVL_HPP
#define REPASOEXAMENARBOLES_ABINESAVL_HPP
#include "../Abin_P1/Abin_enlazada.hpp"
#include "../Abin_P1/EJ2.hpp"
#include <vector>


using namespace std;

template <typename T>
void insertarelemAbin_inorden_rec(vector<T>& v, typename Abin<T>::nodo n, const Abin<T>& A){
    if(n != Abin<T>::NODO_NULO){
        insertarelemAbin_inorden_rec(v, A.hijoIzqdo(n), A);
        v.push_back(A.elemento(n));
        insertarelemAbin_inorden_rec(v, A.hijoDrcho(n), A);
    }
}

template <typename T>
void insertarelemAbin_inorden(const Abin<T>& A, vector<T>& v){
    insertarelemAbin_inorden_rec(v, A.raiz(), A);
}

// -------------------------------------------------------------------------

template <typename T>
bool AbinesABB_rec(typename Abin<T>::nodo n, const Abin<T>& A){
    // Creamos un vector, ¿para qué?. Para introducir los elem del árbol
    // en el vector y si ese vector tiene los elementos ordenados,
    // quiere decir que es un ABB. Por lo tanto, mandamos a que nos den dicho vector.
    vector<T> v;
    insertarelemAbin_inorden(A, v);

    // Ahora, mediante la función is_sorted, veremos si está ordenado el vector.
    if(std::is_sorted(v.begin(), v.end())){
        return true;
    }else{
        return false;
    }
}

template <typename T>
bool AbinesABB(const Abin<T>& A){
    return AbinesABB_rec(A.raiz(), A);
}

template <typename T>
bool AbinesAVL_rec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return true;
    }else{
        if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO and A.hijoDrcho(n) != Abin<T>::NODO_NULO){
            return (std::abs(Altura(A, A.hijoIzqdo(n)) - Altura(A, A.hijoDrcho(n))) <= 1 and
                    AbinesAVL_rec(A.hijoIzqdo(n), A) and AbinesAVL_rec(A.hijoDrcho(n), A));
        }
        if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO and A.hijoDrcho(n) != Abin<T>::NODO_NULO){
            return 1 + Altura(A, A.hijoDrcho(n)) <= 1;
        }
        if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO and A.hijoDrcho(n) == Abin<T>::NODO_NULO){
            return 1 + Altura(A, A.hijoIzqdo(n)) <= 1;
        }else{
            return true;
        }
    }
}

template <typename T>
bool AbinesAVL(const Abin<T>& A){
    if(!A.arbolVacio() and AbinesABB(A)){
        return AbinesAVL_rec(A.raiz(), A);
    }else{
        return false;
    }
}


#endif //REPASOEXAMENARBOLES_ABINESAVL_HPP
