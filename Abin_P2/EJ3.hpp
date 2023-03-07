//
// Created by Anton on 07/03/2023.
//

#ifndef ABIN_P2_EJ3_HPP
#define ABIN_P2_EJ3_HPP
#include "Abin_enlazada.hpp"
#include <iostream>

using namespace std;

struct tOP{
    char oper; /// operador
    double op; /// operando

    friend std::ostream& operator <<(std::ostream& os, const tOP& opera);
    friend std::istream& operator >>(std::istream& is,  tOP& opera);
    friend bool operator !=(const tOP& oper1, const tOP& oper2);
};



std::ostream& operator <<(std::ostream& os, const tOP& opera){
    os << opera.oper << " " << opera.op;

    return os;
}

std::istream& operator >>(std::istream& is,  tOP& opera){
    cout << "\nIntroduce el operador: ";
    is >> opera.oper;

    cout << "\nIntroduce el operando: ";
    is >> opera.op;

    return is;
}

bool operator !=(const tOP& oper1, const tOP& oper2){
    return (oper1.op != oper2.op);
}


// ******************************************************************
// ******************************************************************
// ******************************************************************
// ******************************************************************
// ******************************************************************


double Abinexpresion_rec (typename Abin<tOP>::nodo n, const Abin<tOP>& A);


// función general.
double Abinexpresion (const Abin<tOP>& A){
    return Abinexpresion_rec(A.raiz(), A);
}

double Abinexpresion_rec (typename Abin<tOP>::nodo n, const Abin<tOP>& A){
    if(A.hijoIzqdo(n) != Abin<tOP>::NODO_NULO){
        return A.elemento(n).op;
    }else{
        switch (A.elemento(n).oper) {
            case '+': return Abinexpresion_rec(A.hijoIzqdo(n), A) + Abinexpresion_rec(A.hijoDrcho(n), A); break;
            case '-': return Abinexpresion_rec(A.hijoIzqdo(n), A) - Abinexpresion_rec(A.hijoDrcho(n), A); break;
            case '*': return Abinexpresion_rec(A.hijoIzqdo(n), A) * Abinexpresion_rec(A.hijoDrcho(n), A); break;
            case '/': return Abinexpresion_rec(A.hijoIzqdo(n), A) / Abinexpresion_rec(A.hijoDrcho(n), A); break;
        }
    }
}
#endif //ABIN_P2_EJ3_HPP
