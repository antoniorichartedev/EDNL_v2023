//
// Created by antonio on 29/03/23.
//

#ifndef ABB_P4_EJ2_HPP
#define ABB_P4_EJ2_HPP
#include "Abb.hpp"
#include <vector>

using namespace std;

template <typename T>
void insertarelemAbb_inorden(vector<T>& v, const Abb<T>& A){
    if(!A.vacio()){
        insertarelemAbb_inorden(v, A.izqdo());
        v.push_back(A.elemento());
        insertarelemAbb_inorden(v, A.drcho());
    }
}

template <typename T>
vector<T> equilibrarAbb(Abb<T>& A){
    vector<T> v;
    insertarelemAbb_inorden(v, A);
    Abb<T> res;
    equilibrarAbb_rec(v, res, 0, v.size() - 1);
    A = res;
    return v;
}

template <typename T>
void equilibrarAbb_rec(const vector<T>& v, Abb<T>& res, size_t inicio, size_t fin){
    size_t mediana = (fin + inicio) / 2;
    res.insertar(v[mediana]);

    if(mediana - 1 >= inicio and mediana - 1 <= fin){
        equilibrarAbb_rec(v, res, inicio, mediana - 1);
    }
    if(mediana + 1 >= inicio and mediana + 1 <= fin){
        equilibrarAbb_rec(v, res, mediana + 1, fin);
    }
}
#endif //ABB_P4_EJ2_HPP
