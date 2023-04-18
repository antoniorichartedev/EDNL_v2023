#include <iostream>
#include "apo.hpp"
using namespace std;


int main() {
    Apo<int> A(20);

    A.insertarAPOMINMAX(1);
    //A.insertarAPOMINMAX(2);
    //A.insertarAPOMINMAX(5);
    //A.insertarAPOMINMAX(9);
    /*A.insertarAPOMINMAX(15);
    A.insertarAPOMINMAX(22);
    A.insertarAPOMINMAX(27);
    A.insertarAPOMINMAX(30);
    A.insertarAPOMINMAX(33);
    A.insertarAPOMINMAX(35);
    A.insertarAPOMINMAX(39);
    A.insertarAPOMINMAX(40);
    A.insertarAPOMINMAX(42);
    A.insertarAPOMINMAX(45);
    A.insertarAPOMINMAX(48);
    A.insertarAPOMINMAX(52);*/

    cout << "\nElementos introducidos con éxito." << endl;
    cout << "**** Mostramos el Apo que hemos formado: ****\n" << endl;

    A.imprimirApo(A);





    /*Abin<int> A;

    cout << "**** Rellenamos Abin ****\n" << endl;
    rellenarAbin(A, -1);

    cout << "\n**** Mostramos Abin ****\n" << endl;
    imprimirAbin(A);

    //typename Abin<int>::nodo n = Buscar(A.raiz(), A, 8);

    cout << "\nEl nodo que buscabas tiene como elemento -> " << A.elemento(n) << ". \n\n" << endl;

    cout << "Vamos a eliminar el nodo que hemos buscado.\n" << endl;
    eliminarnodo(A, 3);

    cout << "\n¡Elemento eliminado! Mostramos el Abin resultante: \n" << endl;
    imprimirAbin(A);
    //cout << "\nHijos raíz: " << NumhijosAgen(A.raiz(), A) << endl;

    if(!AgenesTernario(A)){
        cout << "\nEste Agen NO es TERNARIO\n" << endl;
    }else{
        cout << "\nEste Agen es TERNARIO\n" << endl;
    }*/
    return 0;
}
