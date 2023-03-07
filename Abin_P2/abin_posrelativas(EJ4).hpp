//
// Created by Anton on 07/03/2023.
//

#ifndef ABIN_P2_ABIN_POSRELATIVAS_EJ4_HPP
#define ABIN_P2_ABIN_POSRELATIVAS_EJ4_HPP
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "funpow.hpp"

template <typename T> class Abin {
public:
    typedef size_t nodo;
    static const nodo NODO_NULO;
    Abin(size_t Hmaximo, const T& elemvac);
    void insertarRaiz(const T& e);
    void insertarHijoIzqdo(nodo n, const T& e);
    void insertarHijoDrcho(nodo n, const T& e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHijoDrcho(nodo n);
    void eliminarRaiz();
    bool arbolVacio() const;
    const T& elemento(nodo n) const; // acceso a elto, lectura
    T& elemento(nodo n); // acceso a elto, lectura/escritura
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;
    Abin(const Abin<T>& a); // ctor. de copia
    Abin<T>& operator =(const Abin<T>& A); // asig.de árboles
    ~Abin(); // destructor
private:
    size_t Hmax; // altura máx que puede alcanzar el árbol.
    size_t Tmax; // tamaño máx del vector.
    T *eltos, ELEM_NULO;

    int AlturaMax(nodo n, const Abin<T>& A);
    int Profundidad(nodo n, const Abin<T>& A);

};


/* Definición del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(SIZE_MAX);

/*--------------------------------------------------------*/
/*                   Métodos públicos                     */
/*--------------------------------------------------------*/


template <typename T>
inline Abin<T>::Abin(size_t Hmaximo, const T& elemvac) :
    Hmax(Hmaximo),
    ELEM_NULO(elemvac),
    Tmax(pow(2, Hmax+1) - 1),
    eltos(new T[Tmax])
    {
        // ponemos a ELEM_NULO todos las posiciones del vector.
        for(size_t i = 0; i < Tmax; i++){
            eltos[i] = ELEM_NULO;
        }
    }

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e)
{
    // comprobamos que no hay raíz en Tmax/2, que es donde tiene que estar la raíz.
    assert(eltos[Tmax/2] == ELEM_NULO);

    // si no hay raíz, insertamos el elemento.
    eltos[Tmax/2] = e;
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T& e)
{
    unsigned h = AlturaMax(n,*this);

    assert(n >= 0 && n <= Tmax-1); // Nodo válido.
    assert(eltos[n] != ELEM_NULO); // Nodo del árbol.
    assert((n - powi(2, h - 1)) < Tmax); // ese hizq cabe en el árbol.
    assert(eltos[n - powi(2, h - 1)] == ELEM_NULO);   // n no tiene hizq.

    eltos[n - powi(2, h - 1)] = e;
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T& e)
{
    unsigned h = AlturaMax(n,*this);

    assert(n >= 0 && n <= Tmax-1); // Nodo válido.
    assert(eltos[n] != ELEM_NULO); // Nodo del árbol.
    assert((n + powi(2, h - 1)) < Tmax); // ese hder cabe en el árbol.
    assert(eltos[n + powi(2, h - 1)] == ELEM_NULO);   // n no tiene hder.

    eltos[n + powi(2, h - 1)] = e;
}


template <typename T>
inline bool Abin<T>::arbolVacio() const
{
    return (eltos[Tmax/2] == ELEM_NULO);
}

template <typename T>
inline const T& Abin<T>::elemento(nodo n) const
{
    return eltos[n];
}

template <typename T>
inline T& Abin<T>::elemento(nodo n)
{
    return eltos[n];
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const {
    unsigned h = AlturaMax(n,*this);

    return (eltos[n - powi(2, h-1)] == ELEM_NULO) ? NODO_NULO : n - powi(2, h-1);
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const {
    unsigned h = AlturaMax(n,*this);

    return (eltos[n + powi(2, h-1)] == ELEM_NULO) ? NODO_NULO : n + powi(2, h-1);
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const {
    return (eltos[Tmax/2] == ELEM_NULO) ? NODO_NULO : Tmax/2;
}

template <typename T>
typename Abin<T>::nodo Abin<T>::padre(nodo n) const {
    unsigned h = AlturaMax(n,*this);

    assert(n >= 0 && n <= Tmax-1); // Nodo válido.
    assert(eltos[n] != ELEM_NULO); // Nodo del árbol

    if (n % powi(2, h+2) == pow(2, h) - 1){
        return (eltos[n + powi(2, h)] == ELEM_NULO) ? NODO_NULO : n + powi(2, h);
    }else{
        return (eltos[n - powi(2, h)] == ELEM_NULO) ? NODO_NULO : n - powi(2, h);
    }
}

template <typename T>
int Abin<T>::Profundidad(nodo n, const Abin<T> &A) {
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + Profundidad(A.padre(n), A);
    }
}

template <typename T>
int Abin<T>::AlturaMax(nodo n, const Abin<T> &A) {
    return Hmax - Profundidad(n, A);
}
#endif //ABIN_P2_ABIN_POSRELATIVAS_EJ4_HPP
