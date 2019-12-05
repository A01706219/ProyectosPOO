//Rodrigo Marquina Magaña
//A01706219

#include <iostream>

using namespace std; 

class Mesa { //creamos la primer clase que es mesa
private:
	int numero;
	int consumidores; //creamos los atributos
	float cuenta;
public:
	Mesa(int, int, float); //el constructor de la clase mesa define los atributos
	void cuenta_dividida(); //creamos una función para dividir la cuenta
};


Mesa::Mesa(int num, int con, float cue) { //creamos el constructor para los datos que va a poner el usuario
	numero = num;
	consumidores = con;
	cuenta = cue;
}

void Mesa::cuenta_dividida() {
	cout << "Cuenta dividida: " << cuenta / consumidores << endl; //dividimos la cuenta total entre el numero de peronas
}
//definimos que va a hacer la funcion que va a dividir el dinero total de la cuenta entre el número de personas
class Alimento { //creamos la clase padre para las demás clases de comida
protected:
	string nombre; //ambas clases tienen tamano y nombre entonces lo ponemos aqui
	int tamano;
};

class Postre: public Alimento { //Aqui creamos la clase hija y pasamos los atributos a ella 
private:
	bool cubierto; //creamos otro private porque necesitamos otro atributo
public:
	Postre(string, bool, int); //creamos el constructor
	void precio(); //creamos la funcion precio
};

Postre::Postre(string n, bool c, int t) { //los datos que va a incluir el usuario
	nombre = n;
	cubierto = c;
	tamano = t;
}

void Postre::precio() {
	cout << "Precio postre: " << tamano * 10 << endl; //el tamano puede ser de 1 a 5 para definir tamanos
} //definimos la funcion precio que depende de que tamano sea el plato (1-3) se multiplica por 10

class Bebida: public Alimento { //nuevamente creamos una clase hija que tome los atributos de la clase alimento
private:
	bool fria; //fria=true caliente=false
public:
	Bebida(string, bool, int); //constructor
	void precio(); //creamos la funcion precio
};

Bebida::Bebida(string n, bool f, int t) { 
	nombre = n;
	fria = f;
	tamano = t;
}

void Bebida::precio() {
	cout << "Precio bebida: " << tamano * 7 << endl; //ambas funciones precio estan separadas del padre porque la bebida se multiplica por 7 y el postre por 10
}


int main() { //despues de crear las clases definimos 3 objetos y usamos las funciones que es lo que finalmente se le entrega al usuario

	Mesa Mesa_1(1, 4, 84.4); //creamos un objeto mesa que es el numero 1 de mesa, con 4 consumidores y son 84.4 de cuenta

	Postre helado("helado", false, 3); //el nombre del objeto, no se necesita cubierto (false) y el tamaño es 3

	Bebida cafe("cafe", false, 2); //el nombre del objeto, como es caliente el bool frio se pone en false y el tamaño

	Mesa_1.cuenta_dividida(); //usamos la funcion cuenta_dividida para sacar el precio de la mesa 1

	helado.precio(); //sacamos el precio del helado con el tamaño por 10

	cafe.precio(); //sacamos el precio del cafe que es el tamaño por 7

	return 0; //termina el codigo
}