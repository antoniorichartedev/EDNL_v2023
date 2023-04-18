#include <iostream>
#include "Abb.hpp"
#include "abb_E_S.hpp"

#include "EJ5.hpp"
#include "EJ3.hpp"

using namespace std;

int main() {
    Abb<int> A, B;
    cout << "**** Rellenamos el Árbol Binario de Búsqueda A: ****\n" << endl;
    rellenarAbb(A, -1);

    cout << "\n**** Rellenamos el Árbol Binario de Búsqueda B: ****\n" << endl;
    rellenarAbb(B,-1);

    cout << "\n**** Mostramos el árbol binario de búsqueda A ****\n" << endl;
    imprimirAbb(A);

    cout << "\n**** Mostramos el árbol binario de búsqueda A ****\n" << endl;
    imprimirAbb(B);

    cout << "Ahora, vamos a hacer la diferencia entre el árbol A y el árbol B.\n" << endl;
    Conjunto<int> A1{A}, B1{B};
    imprimirAbb((A1 ^ B1).abb);

    cout << endl;

    /*cout << "Mostramos el árbol modificado.\n" << endl;
    imprimirAbb(res);*/

    return 0;
}
