#include <iostream>
#include "AbinReflejado.hpp"
#include "../Abin_P1/abin_E-S.h"

int main() {
    Abin<int> A;
    rellenarAbin(A, -1);

    cout << "\n**** Imprimimos el Abin: ****" << endl;
    imprimirAbin(A);

    cout << "\n*** Este Abin tiene " << NumNodosReflejados(A) << " nodos reflejados. ***" << endl;
    /*cout << "\n*** Vamos a comprobar que los elementos del ABin se ha introducido correctamente en el vector *** " << endl;
    vector<int> vec;
    insertarelemAbin_inorden(A, vec);

    cout << "\n*** Mostramos el vector ***" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ", ";
    }


    if(AbinesABB(A)){
        cout << "\n\n*** Este Abin ES un Abb ***" << endl;
    }else{
        cout << "\n\n*** Este Abin NO es un Abb ***" << endl;
    }

    if(AbinesAVL(A)){
        cout << "\n\n*** Este Abin ES un AVL ***" << endl;
    }else{
        cout << "\n\n*** Este Abin NO es un AVL ***" << endl;
    }*/
    return 0;
}
