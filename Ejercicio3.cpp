#include <iostream>
using namespace std; 
class Estudiante{
	public:
		string nombre;
		int edad;
		void mostrarDatos(){
	    cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
		}
};

int main(){
    Estudiante el;
    el.nombre = "Ana";
    el.edad= 21;
    el.mostrarDatos();
    return 0;
}

