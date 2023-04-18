//
// Created by antonio on 17/04/23.
//

#ifndef ABB_P4_EJ5_HPP
#define ABB_P4_EJ5_HPP
#include "Abb.hpp"


template <typename T>
struct Conjunto{

    Conjunto(const Abb<T> A = Abb<T>()): abb{A}{}
    bool pertenece(const T& e) const {return !abb.buscar(e).vacio();};
    Abb<T> abb;
};

template <typename T>
void rombo_rec(const Conjunto<T>& c1, const Conjunto<T>& c2, Conjunto<T>& res);


template <typename T>
Conjunto<T> operator ^(const Conjunto<T>& c1, const Conjunto<T>& c2){
    Conjunto<T> res;
    rombo_rec(c1, c2, res);
    rombo_rec(c2, c1, res);

    return res;
}

template <typename T>
void rombo_rec(const Conjunto<T>& c1, const Conjunto<T>& c2, Conjunto<T>& res){
    if(!c1.abb.vacio()){
        if(!c2.pertenece(c1.abb.elemento())){
            res.abb.insertar(c1.abb.elemento());
        }
        rombo_rec(Conjunto<T>(c1.abb.izqdo()), c2, res);
        rombo_rec(Conjunto<T>(c1.abb.drcho()), c2, res);
    }
}
#endif //ABB_P4_EJ5_HPP
