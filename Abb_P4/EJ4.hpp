//
// Created by antonio on 17/04/23.
//

#ifndef ABB_P4_EJ4_HPP
#define ABB_P4_EJ4_HPP
#include "Abb.hpp"
#include "EJ2.hpp"


template <typename T>
void interseccionAbb_Rec(const Abb<T>& A, const Abb<T>& B, Abb<T>& res);


template <typename T>
Abb<T> interseccionAbb(const Abb<T>& A, const Abb<T>& B){
    Abb<T> res;
    interseccionAbb_Rec(A, B, res);
    equilibrarAbb(res);
    return res;
}

template <typename T>
void interseccionAbb_Rec(const Abb<T>& A, const Abb<T>& B, Abb<T>& res){
    if(!A.vacio() and !B.vacio()){
        if(!B.buscar(A.elemento()).vacio()){
            res.insertar(A.elemento());
            interseccionAbb_Rec(A.izqdo(),B, res);
            interseccionAbb_Rec(A.drcho(),B, res);
        }
    }
}
#endif //ABB_P4_EJ4_HPP
