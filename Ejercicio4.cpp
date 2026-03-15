#include <iostream>
using namespace std; 

// CLASE: molde/plantilla para crear libros
class Libro {
	public: // todo lo de abajo es accesible desde afuera
	
		// ATRIBUTOS: características del libro
		string nombre;
		string autor;
		int numEdicion;
		string genero;
		string fechaPublicacion;
		
		// MÉTODO: acción que puede hacer el objeto
		void mostrarDatos(){
		    cout << "Nombre del libro: " << nombre << endl;
		    cout << "Autor: " << autor << endl;
            cout << "Numero de Edicion: " << numEdicion << endl;
            cout << "Genero: " << genero << endl;
            cout << "Fecha de Publicacion: " << fechaPublicacion << endl;
		}
};

int main(){
    Libro el; // INSTANCIA: se crea un objeto llamado "el" a partir de la clase Libro
    
    // ASIGNACIÓN DE VALORES a cada atributo del objeto
    el.nombre= "Porque las vacas lloran";
    el.autor = "Maria Torres";
    el.numEdicion= 21;
    el.genero= "Drama";
    el.fechaPublicacion= "08/03/1981";
    
    el.mostrarDatos(); // LLAMADA AL MÉTODO: imprime todos los datos en pantalla
    
    return 0; 

