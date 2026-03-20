#include <iostream>
using namespace std;

// Definición del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

// Lista (puntero al inicio)
typedef Nodo* ListaTotal;

// ?? Insertar al inicio
void InsertarNodo(ListaTotal &lista, int valor) {
    Nodo* nuevo = new Nodo;

    nuevo->dato = valor;
    nuevo->siguiente = lista;
    nuevo->anterior = NULL;

    if (lista != NULL) {
        lista->anterior = nuevo;
    }

    lista = nuevo;
}

// ?? Buscar nodo
bool BuscarNodo(ListaTotal lista, int valor, int &posicion) {
    Nodo* aux = lista;
    posicion = 1;

    while (aux != NULL) {
        if (aux->dato == valor) {
            return true;
        }
        aux = aux->siguiente;
        posicion++;
    }

    return false;
}

// ?? Imprimir lista
void ImprimirLista(ListaTotal lista) {
    Nodo* aux = lista;

    cout << "\nLista:\n";

    while (aux != NULL) {
        cout << aux->dato << " <-> ";
        aux = aux->siguiente;
    }

    cout << "NULL\n";
}

// ?? Programa principal
int main() {
    ListaTotal lista = NULL;

    int valorElemento, opcion, posicion;
    char seleccion = 's';

    do {
        cout << "\n1. Insertar elemento al inicio\n";
        cout << "2. Buscar elemento\n";
        cout << "3. Mostrar lista\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            seleccion = 's';
            while (seleccion == 's' || seleccion == 'S') {
                cout << "Ingrese el valor: ";
                cin >> valorElemento;

                InsertarNodo(lista, valorElemento);

                cout << "Fin\n";
                cout << "Desea seguir ingresando (s/n): ";
                cin >> seleccion;
            }
            break;

        case 2:
            cout << "Ingrese el valor a buscar: ";
            cin >> valorElemento;

            if (BuscarNodo(lista, valorElemento, posicion)) {
                cout << "Elemento encontrado en la posicion: " << posicion << endl;
            } else {
                cout << "Elemento no encontrado\n";
            }
            break;

        case 3:
            ImprimirLista(lista);
            break;

        case 4:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 4);

    return 0;
}
