#include <iostream>
using namespace std; 

class Animal {
public:
	virtual void hacersonido (){
		cout << "El animal hace un sonido" <<endl;
	}

};

class Perro : public Animal {
public:
	void hacersonido () override {
		cout << "Guau , Guau" << endl;
	}
};
class Gato : public Animal {
public:
	void hacersonido () override {
		cout << "Miau, Miau" << endl;
	}
};

int main (){
	Animal* a1;
	Perro p;
	Gato g;
	
	a1=&p;
	a1 ->hacersonido ();
	
	a1=&g;
	a1 ->hacersonido();
		
	return 0;
}
