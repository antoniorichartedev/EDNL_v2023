#include <iostream>
#include "../Agen_P3/Agen.h"
#include "../Agen_P3/agen_E-S.h"
using namespace std;

#include "EJ4.hpp"

int main() {
    Agen<int> A;

    cout << "**** Rellenamos Agen ****\n" << endl;
    rellenarAgen(A, -1);

    cout << "\n**** Mostramos Agen ****\n" << endl;
    imprimirAgen(A);

    if(AgenesTernario(A)){
        cout << "\nEste Agen ES TERNARIO\n" << endl;
    }else{
        cout << "\nEste Agen NO es TERNARIO\n" << endl;
    }
    return 0;
}
