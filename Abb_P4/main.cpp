#include <iostream>
#include "Abb.hpp"
#include "abb_E_S.hpp"
#include <vector>
#include "EJ2.hpp"

using namespace std;

int main() {
    Abb<int> A, B;
    cout << "**** Rellenamos el Árbol Binario de Búsqueda A: ****\n" << endl;
    rellenarAbb(A, -1);

    cout << "\n**** Mostramos el árbol binario de búsqueda A ****\n" << endl;
    imprimirAbb(A);

    cout << "\n**** Ahora, vamos a obtener sus elementos recorriéndolos en inorden. ****" << endl;
    vector<int> vec = equilibrarAbb(A);

    cout << "\n**** Mostramos los elem del abb ordenados. ****" << endl;
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << ", ";
    }

    /*cout << "Mostramos el árbol modificado.\n" << endl;
    imprimirAbb(res);*/

    return 0;
}
