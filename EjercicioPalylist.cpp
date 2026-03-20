#include <iostream>
using namespace std;

// Clase Nodo
template <typename T>
class NodoDoble {
public:
    T info;
    NodoDoble* next;
    NodoDoble* prev;

    NodoDoble(T valor) {
        info = valor;
        next = NULL;
        prev = NULL;
    }
};

// Clase ListaDoble (Playlist)
template <typename T>
class ListaDoble {
private:
    NodoDoble<T>* head;
    NodoDoble<T>* tail;

public:

    // Constructor
    ListaDoble() {
        head = NULL;
        tail = NULL;
    }

    // Agregar al final
    void agregarCancionFinal(T valor) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(valor);

        if (head == NULL) {
            head = tail = nuevo;
        } else {
            tail->next = nuevo;
            nuevo->prev = tail;
            tail = nuevo;
        }
    }

    // Para que funcione con tu main
    void insertarFin(T valor) {
        agregarCancionFinal(valor);
    }

    // Insertar después de una canción
    bool insertarDespuesDeCancionActual(T buscado, T valor) {
        NodoDoble<T>* actual = head;

        while (actual != NULL && actual->info != buscado) {
            actual = actual->next;
        }

        if (actual == NULL) return false;

        NodoDoble<T>* nuevo = new NodoDoble<T>(valor);

        nuevo->next = actual->next;
        nuevo->prev = actual;

        if (actual->next != NULL) {
            actual->next->prev = nuevo;
        } else {
            tail = nuevo;
        }

        actual->next = nuevo;
        return true;
    }

    bool insertarDespuesDe(T buscado, T valor) {
        return insertarDespuesDeCancionActual(buscado, valor);
    }

    // Eliminar canción
    bool eliminarCancion(T valor) {
        NodoDoble<T>* actual = head;

        while (actual != NULL && actual->info != valor) {
            actual = actual->next;
        }

        if (actual == NULL) return false;

        if (actual == head) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;
        }
        else if (actual == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
        else {
            actual->prev->next = actual->next;
            actual->next->prev = actual->prev;
        }

        delete actual;
        return true;
    }

    // Para que funcione con tu main
    bool eliminar(T valor) {
        return eliminarCancion(valor);
    }

    // Mostrar de inicio a fin
    void mostrarPlaylistInicioFin() {
        NodoDoble<T>* aux = head;

        while (aux != NULL) {
            cout << aux->info << " <-> ";
            aux = aux->next;
        }
        cout << "null" << endl;
    }

    // Para que funcione con tu main
    void imprimirAdelante() {
        mostrarPlaylistInicioFin();
    }

    // Mostrar de fin a inicio
    void mostrarPlaylistFinInicio() {
        NodoDoble<T>* aux = tail;

        while (aux != NULL) {
            cout << aux->info << " <-> ";
            aux = aux->prev;
        }
        cout << "null" << endl;
    }

    // Para que funcione con tu main
    void imprimirAtras() {
        mostrarPlaylistFinInicio();
    }
};


// MAIN
int main() {

    ListaDoble<string> canciones;

    canciones.insertarFin("Intro");
    canciones.insertarFin("Rock");
    canciones.insertarFin("Balada");

    cout << "Recorrido hacia adelante:" << endl;
    canciones.imprimirAdelante();

    cout << "Recorrido hacia atras:" << endl;
    canciones.imprimirAtras();

    canciones.insertarDespuesDe("Rock", "Pop");
    cout << "Despues de insertar Pop:" << endl;
    canciones.imprimirAdelante();

    canciones.eliminar("Rock");
    cout << "Despues de eliminar Rock:" << endl;
    canciones.imprimirAdelante();

    return 0;
}
