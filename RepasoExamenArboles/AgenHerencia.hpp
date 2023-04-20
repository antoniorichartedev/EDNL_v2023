//
// Created by antonio on 20/04/23.
//

#ifndef REPASOEXAMENARBOLES_AGENHERENCIA_HPP
#define REPASOEXAMENARBOLES_AGENHERENCIA_HPP
#include "../Agen_P3/Agen.h"

struct heredero{
    bool vivo;
    double riqueza;
};


bool tieneHerederosVivo(typename Agen<heredero>::nodo n, const Agen<heredero>& A){
    bool herencia = false;
    Agen<heredero>::nodo hijo = A.hijoIzqdo(n);

    while(hijo != Agen<heredero>::NODO_NULO){
        if(A.elemento(hijo).vivo){
            herencia = true;
        }else{
            herencia = tieneHerederosVivo(hijo, A);
        }
        hijo = A.hermDrcho(hijo);
    }
    return herencia;
}

int num_herederos(typename Agen<heredero>::nodo n, const Agen<heredero>& A){
    int herederos = 0;
    Agen<heredero>::nodo hijo = A.hijoIzqdo(n);

    while(hijo != Agen<heredero>::NODO_NULO){
        if(A.elemento(hijo).vivo){
            herederos++;
        }else{
            bool herederosVivos = tieneHerederosVivo(hijo, A);
            if(herederosVivos){
                herederos++;
            }
        }
        hijo = A.hermDrcho(hijo);
    }
    return herederos;
}

void repartirRiqueza(typename Agen<heredero>::nodo n, Agen<heredero>& A){
    if(num_herederos(n, A) > 0){
        double riquezaherederoppal = A.elemento(n).riqueza / num_herederos(n, A);
        typename Agen<heredero>::nodo hijo = A.hijoIzqdo(n);

        while(hijo != Agen<heredero>::NODO_NULO){
            if(A.elemento(hijo).vivo){
                A.elemento(hijo).riqueza = riquezaherederoppal;
            }else{
                repartirRiqueza(hijo, A);
            }
            hijo = A.hermDrcho(hijo);
        }
    }else{
        typename Agen<heredero>::nodo hijo = A.hijoIzqdo(n);
        if(hijo != Agen<heredero>::NODO_NULO){
            A.elemento(hijo).riqueza = A.elemento(n).riqueza;
        }
    }
}
#endif //REPASOEXAMENARBOLES_AGENHERENCIA_HPP
