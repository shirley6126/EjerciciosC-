#include <iostream>
using namespace std; 

// CLASE PADRE/BASE: molde general para cualquier vehículo
class Vehiculo {
public:
    // ATRIBUTOS: características generales de todo vehículo
    string marca;
    string modelo;
    
    // MÉTODO VIRTUAL: puede ser reemplazado por las clases hijas
    virtual void mostrarInfo(){
        cout << "Informacion del vehiculo: " << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
    }
};

// CLASE HIJA: hereda todo lo de Vehiculo y agrega lo suyo
class Auto : public Vehiculo {
public:
    // ATRIBUTO PROPIO de Auto
    int numPuertas;
    
    // OVERRIDE: reemplaza el método de la clase padre con uno propio
    void mostrarInfo() override {
        cout << "---AUTO---" << endl;
        Vehiculo::mostrarInfo(); // LLAMA al método del padre 
        cout << "Numero de puertas: " << numPuertas << endl;
    }
};

// CLASE HIJA: hereda todo lo de Vehiculo y agrega lo suyo
class Moto : public Vehiculo {
public:
    // ATRIBUTO PROPIO de Moto
    int cilindraje;
    
    // OVERRIDE: reemplaza el método de la clase padre con uno propio
    void mostrarInfo() override {
        cout << "---MOTO---" << endl;
        Vehiculo::mostrarInfo(); // LLAMA al método del padre 
        cout << "Cilindraje: " << cilindraje << endl;
    }
};

int main(){
    Auto a;  // INSTANCIA: objeto "a" creado desde la clase Auto
    Moto m;  // INSTANCIA: objeto "m" creado desde la clase Moto
    
    // ASIGNACIÓN DE VALORES al objeto Auto
    a.marca = "Toyota";
    a.modelo = "camioneta 4x4"; 
    a.numPuertas = 4;
    a.mostrarInfo(); // LLAMADA AL MÉTODO: imprime datos del auto
    
    // ASIGNACIÓN DE VALORES al objeto Moto
    m.marca = "Honda";
    m.modelo = "deportivo"; 
    m.cilindraje = 200;
    m.mostrarInfo(); // LLAMADA AL MÉTODO: imprime datos de la moto
        
    return 0; // programa termina correctamente
}

