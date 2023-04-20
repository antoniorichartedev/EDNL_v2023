#include <iostream>
#include "AbinesAVL.hpp"
#include "../Abin_P1/abin_E-S.h"

int main() {
    Abin<int> A;
    rellenarAbin(A, -1);

    cout << "\n**** Imprimimos el Abin: ****" << endl;
    imprimirAbin(A);

    cout << "\n*** Vamos a comprobar que este Abin es un AVL -----> ";
    if(AbinesAVL(A)){
        cout << "ES un Abb ***" << endl;
    }else{
        cout << "NO es un Abb ***" << endl;
    }
    return 0;
}
