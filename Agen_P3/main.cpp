#include <iostream>
#include "Agen.h"
#include "agen_E-S.h"

#include "EJ4.hpp"

using namespace std;
typedef int tElto;
const tElto fin = -1; // fin de lectura


int main() {
    Agen<tElto> A, B;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    imprimirAgen(A); // En fichero.

    poda(5, A);
    cout << "\nPoda realizada, imprimimos arbol resultante:\n\n" << endl;
    imprimirAgen(A);
    return 0;
}
