#include <iostream>
#include "Abin_enlazada.hpp"
#include "abin_E-S.h"

#include "EJ3.hpp"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

template <typename T>
void ejercicio1(Abin<T>& A, Abin<T>& B){
    bool res = ReflexAbin(A, B);

    if (res){
        cout << "\nSON SIMILARES." << endl;
    }else{
        cout << "\nNO SON SIMILARES." << endl;
    }
}


int main() {
    Abin<tElto> A, B;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // Desde std::cin

    cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A);

    /*cout << "\n\n*** Lectura del árbol binario B ***\n";
    rellenarAbin(B, fin); // Desde std::cin

    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(B);*/

    return 0;
}
