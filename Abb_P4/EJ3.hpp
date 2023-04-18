//
// Created by antonio on 17/04/23.
//

#ifndef ABB_P4_EJ3_HPP
#define ABB_P4_EJ3_HPP
#include "Abb.hpp"
#include "EJ2.hpp"

template <typename T>
void unionAbb_rec(const Abb<T>& A, const Abb<T>& B, Abb<T>& res);

template <typename T>
Abb<T> unionAbb(const Abb<T>& A, const Abb<T>& B){
    Abb<T> res;
    unionAbb_rec(A, B, res);
    equilibrarAbb(res);
    return res;
}

template <typename T>
void unionAbb_rec(const Abb<T>& A, const Abb<T>& B, Abb<T>& res){

    if(!B.vacio()){
        res.insertar(B.elemento());

        // Luego, lo que haremos será insertar los subárboles izq y der.
        unionAbb_rec(Abb<T>(),B.izqdo(), res);
        unionAbb_rec(Abb<T>(), B.drcho(), res);
    }

    if(!A.vacio()){
        res.insertar(A.elemento());

        // Luego, lo que haremos será insertar los subárboles izq y der.
        unionAbb_rec(Abb<T>(),A.izqdo(), res);
        unionAbb_rec(Abb<T>(), A.drcho(), res);
    }
}
#endif //ABB_P4_EJ3_HPP
