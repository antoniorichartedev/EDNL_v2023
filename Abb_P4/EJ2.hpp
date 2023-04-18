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
void equilibrarAbb(Abb<T>& A){
    vector<T> v;
    insertarelemAbb_inorden(v, A);
    Abb<T> res;
    equilibrarAbb_rec(v, res);
    A = res;
}

template <typename T>
void equilibrarAbb_rec(const vector<T>& v, Abb<T>& res){
    int mediana = (v.size() + 1) / 2 - 1;
    int i = 0;
    if(!v.empty()){
        res.insertar(*(v.begin() + mediana));

        vector<T> vizq, vder;
        for(i = 0; i < mediana; i++){
            vizq.push_back(*(v.begin() + i));
        }
        for(i = mediana + 1; i < v.size(); i++){
            vder.push_back(*(v.begin() + i));
        }

        equilibrarAbb_rec(vizq, res);
        equilibrarAbb_rec(vder, res);

    }
}
#endif //ABB_P4_EJ2_HPP
