#include <iostream>
#include <fstream>
#include "abin_enlazada.hpp"
#include "abin_E-S.h"


#include "EJ1.hpp"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

int main(){
    Abin<tElto> A, B;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // Desde std::cin

    cout << "\n*** Mostrar árbol binario A ***\n";
    imprimirAbin(A);

    

    /*cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, B); // Desde fichero.
    fe.close();
    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(B); // En std::cout*/

    return 0;

    ///NumNodos(A);
}