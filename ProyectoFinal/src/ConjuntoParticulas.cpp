#include <iostream>
#include "ConjuntoParticulas.h"

ConjuntoParticulas::ConjuntoParticulas(){

	capacidad = 5;
	utiles = 0;
	set = new Particula[capacidad];
}

ConjuntoParticulas::ConjuntoParticulas(int size, bool tipo){

	capacidad = size;
	set = new Particula[capacidad];

	if(tipo){
		for(int i = 0; i < capacidad; i++){
			Particula p;
			set[i] = p;
		}
		utiles = capacidad;
	}
	else
		utiles = 0;
}

ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas &otro){

	capacidad = otro.capacidad;
	utiles= otro.utiles;
	set = new Particula[capacidad+1];
	for(int i = 0; i < capacidad; i++){
		set[i] = otro.set[i];
	}
}

ConjuntoParticulas::~ConjuntoParticulas(){

	delete[] set;
}
void ConjuntoParticulas::setCapacidad(int cap){

	capacidad = cap;
}

void ConjuntoParticulas::setUtiles(int util){

	utiles = util;
}

int ConjuntoParticulas::getCapacidad(){

	return capacidad;
}

int ConjuntoParticulas::getUtiles(){

	return utiles;
}

void ConjuntoParticulas::Redimensiona(){
	
	int aux = capacidad;
	capacidad += TAM_BLOQUE;
	setCapacidad(capacidad);

	Particula *set_ampliado = new Particula[capacidad];
	for(int i = 0; i < aux; i++){
		set_ampliado[i] = set[i];
	}
	delete [] set;
	set = set_ampliado;
}

void ConjuntoParticulas::RedimensionaMenor(){
	
	
	capacidad = getUtiles();

	Particula *set_disminuir = new Particula[capacidad];
	for(int i = 0; i < capacidad; i++){
		set_disminuir[i] = set[i];
	}
	delete [] set;
	set = set_disminuir;
}


void ConjuntoParticulas::AgregaParticula(Particula p){

	if(utiles == capacidad){
		Redimensiona();
	}
	set[utiles] = p;
	utiles++;
}

void ConjuntoParticulas::BorraParticula(int posicion){

	for(int i = posicion; i < utiles - 1; i++){
		set[i] = set[i+1];
	}

	utiles--;
	if((capacidad - utiles) > TAM_BLOQUE){
		RedimensionaMenor(); 
	}
}

Particula& ConjuntoParticulas::ObtieneParticula(int posicion){

	return set[posicion];
}

void ConjuntoParticulas::ReemplazaParticula(int posicion, Particula &otra){

	set[posicion] = otra;
}

void ConjuntoParticulas::Mover(int ancho, int alto){

	for(int i = 0; i < utiles; i++){
		set[i].Mover(ancho, alto);
	}
}

void ConjuntoParticulas::GestionarColisiones(){

	for(int i = 0; i < utiles-1; i++){
		for(int j = 1+1; j < utiles; j++){
			if(set[i].Colision(set[j]))
				set[i].Rebota(set[j]);
		}
	}
}


void ConjuntoParticulas::Liberar(){

	delete[] set;
	capacidad = 0;
	utiles = 0;
}

ConjuntoParticulas ConjuntoParticulas::operator+(const ConjuntoParticulas &otro) const{

	int suma_utiles = utiles + otro.utiles;
	ConjuntoParticulas final(suma_utiles, false);

	int j = 0;

	//recorro el primer conjunto de particulas hasta su capacidad
	for(int i = 0; i < utiles; i++){
		final.set[i] = set[i];

	}

	//recorro el segundo conjunto de particulas hasta su capacidad
	for(int i = utiles; i < suma_utiles; i++){
		final.set[i] = otro.set[j];
		j++;
	}
	final.utiles = suma_utiles;
	return final;
}


ConjuntoParticulas& ConjuntoParticulas::operator=(const ConjuntoParticulas &otro){

	if(&otro != this){
		delete [] set;
		utiles = otro.utiles;
		capacidad = otro.capacidad;
		set = new Particula[capacidad];
		for(int i = 0; i < capacidad; ++i){
			set[i] = otro.set[i];
		}
	}

	return *this;
}

ostream& operator<< (ostream& flujo, const ConjuntoParticulas& otro){

    flujo << "Hay " << otro.utiles << " particulas" << endl;
    flujo << "La capacidad es de " << otro.capacidad << endl;
    flujo << "------------------------------------------" << endl;
    for(int i = 0; i < otro.utiles; i++){
    	cout << "Particula " << i+1 << ": " << endl;
    	flujo << "Posicion: " << otro.set[i].getX() << "," << otro.set[i].getY() << endl;
    	flujo << "Velocidad: " << otro.set[i].getDX() << "x," << otro.set[i].getDY() << "y" << endl;
    	flujo << "Color: " << otro.set[i].getColor() << endl;
    	flujo << "-----------------------------------------" << endl;
    }
    return flujo;
}

