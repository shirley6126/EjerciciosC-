#include <iostream>
using namespace std;

// Definición del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Nodo cabecera
struct NodoCabecera {
    Nodo* siguiente;
};

int main() {
    NodoCabecera lista;
    Nodo* nuevo;
    Nodo* aux;

    int contador, numElementos;

    // Inicializar lista vacía
    lista.siguiente = NULL;

    cout << "Ingrese el numero de elementos de la lista: ";
    cin >> numElementos;

    // Insertar elementos
    for (contador = 0; contador < numElementos; contador++) {
        cout << "El elemento " << contador + 1 << ": ";

        nuevo = new Nodo; // crear nodo
        cin >> nuevo->dato;

        // Insertar al inicio
        nuevo->siguiente = lista.siguiente;
        lista.siguiente = nuevo;
    }

    // Mostrar lista
    cout << "\nLista de elementos:\n";

    aux = lista.siguiente;

    while (aux != NULL) {
        cout << aux->dato << endl;
        aux = aux->siguiente;
    }

    return 0;
}
