#include <iostream>
#include "simulador.h"

using namespace miniwin;

Simulador::Simulador(ConjuntoParticulas A, ConjuntoParticulas B, int anc, int alt){

	moviles = A;
	fijas = B;
	ancho = anc;
	alto = alt;
	vredimensiona(ancho, alto);
}

Simulador::~Simulador(){

	vcierra();
}

void Simulador::setMoviles(ConjuntoParticulas A){

	moviles = A;
}

void Simulador::setFijas(ConjuntoParticulas A){

	fijas = A;
}

ConjuntoParticulas Simulador::getMoviles(){

	return moviles;
}

ConjuntoParticulas Simulador::getFijas(){

	return fijas;
}
void Simulador::Pintar(){

	borra();
	PintarFijas();
	PintarMoviles();
	refresca();
    espera(25);
}

void Simulador::PintarMoviles(){

	int size = moviles.getUtiles();
	Particula p;
	for(int i = 0; i < size; i++){
		p = moviles.ObtieneParticula(i);
		color(p.getColor());
		circulo_lleno(p.getX(), p.getY(), RADIO);
	}
}

void Simulador::PintarFijas(){

	int size = fijas.getUtiles();
	Particula p;
	for(int i = 0; i < size; i++){
		p = fijas.ObtieneParticula(i);
		color(p.getColor());
		rectangulo_lleno(p.getX()-RADIO/2,p.getY()-RADIO/2,p.getX()+RADIO/2,p.getY()+RADIO/2);
	}
}

void Simulador::Step(){

	moviles.Mover(ancho, alto);
	moviles.GestionarColisiones();
	Rebotes();
}

void Simulador::Rebotes(){


	for(int i = 0; i < moviles.getUtiles(); i++){
		for(int j = 1+1; j < fijas.getUtiles(); j++){
			if(moviles.ObtieneParticula(i).Colision(fijas.ObtieneParticula(j))){
				moviles.ObtieneParticula(i).setDX(-moviles.ObtieneParticula(i).getDX());
				moviles.ObtieneParticula(i).setDY(-moviles.ObtieneParticula(i).getDY());
				
			}
		}
	}
}

void Simulador::VelocidadNula(){

	for(int j = 0; j < fijas.getUtiles(); j++){
		fijas.ObtieneParticula(j).setDX(0);
		fijas.ObtieneParticula(j).setDY(0);
	}
}