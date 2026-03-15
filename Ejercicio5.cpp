#include <iostream>
using namespace std; 
class Persona{
	public:
		string nombre;
		
		void saludar(){
	    cout << "Hola, soy " << nombre << endl;
		}
};
class Estudiante : public Persona {
	public:
		string carrera;
		
		void mostrarCarrera(){
	    cout << "Carrera: " << carrera << endl;
		}
};

int main(){
    Estudiante el;
    el.nombre = "Shirley";
    el.carrera= "Software";
    
    el.saludar();
    el.mostrarCarrera();
    
    return 0;
}

