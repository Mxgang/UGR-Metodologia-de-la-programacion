/**
  * @file simulador.h
  * @brief Fichero cabecera del simulador
  *
  */



#ifndef _SIMULADOR_H_
#define _SIMULADOR_H_

#include <iostream>
#include "miniwin.h"
#include "ConjuntoParticulas.h"

using namespace miniwin;

class Simulador{
	

private:

	ConjuntoParticulas moviles;
	ConjuntoParticulas fijas;
	int ancho, alto;

public:

	Simulador(ConjuntoParticulas A, ConjuntoParticulas B, int anc, int alt);
	~Simulador();
	void setMoviles(ConjuntoParticulas A);
	void setFijas(ConjuntoParticulas A);
	ConjuntoParticulas getMoviles();
	ConjuntoParticulas getFijas();
	/**
		 * @brief Llama a los métodos de pinter partículas
		**/
	void Pintar();
	/**
		 * @brief Pinta las partículas móviles
		**/
	void PintarMoviles();
	/**
		 * @brief Pinta las partículas fijas
		**/
	void PintarFijas();
	/**
		 * @brief Llama a los métodos Mover y GestionarColisiones
		**/
	void Step();
	/**
		 * @brief Gestiona los rebotes entre las partículas móviles y las fijas
		**/
	void Rebotes();
	/**
		 * @brief Pone la velocidad de la partículas fijas a 0
		**/
	void VelocidadNula();

};

#endif