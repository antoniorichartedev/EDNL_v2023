#include <iostream>
#include <fstream>
#include "Abin_enlazada.hpp"
#include "abin_E-S.h"

#include "EJ2.hpp"
#include "EJ6.hpp"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

template <typename T>
void ejercicio1(Abin<T>& A);

template <typename T>
void ejercicio2(const Abin<T>& A){
    int res = Altura(A, A.raiz());
    cout << "\nAltura del árbol: " << res;
}

template <typename T>
void ejercicio3(Abin<T>& A){
    typename Abin<T>::nodo n = A.hijoIzqdo(A.hijoIzqdo(A.raiz()));
    int res = Profundidad(n, A);

    cout << "\nProfundidad desde el nodo " << A.elemento(n) << ": " << res;
}

template <typename T>
void ejercicio6 (Abin<T>& A){
    int res = DesequilibrioAbin(A);

    cout << "\nGrado de desequilibrio: " << res << endl;
}
int main() {
    Abin<tElto> A, B;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // Desde std::cin

    cout << "\n*** Mostrar árbol binario A ***\n";
    imprimirAbin(A);

    ejercicio6(A);
    return 0;
}

template <typename T>
void ejercicio1(Abin<T>& A){
    int res = NumNodos(A);

    cout << "Número de nodos: " << res;
}

