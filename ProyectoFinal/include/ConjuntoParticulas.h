/**
  * @file ConjuntoParticulas.h
  * @brief Fichero cabecera de Conjunto de Particulas
  *
  */



#ifndef _CONJUNTOPARTICULAS_H_
#define _CONJUNTOPARTICULAS_H_

#include <iostream>
#include "particula.h"

using namespace std;

const int TAM_BLOQUE = 5;

class ConjuntoParticulas {

private:
	Particula *set;
	int capacidad;
	int utiles;

public: 
	ConjuntoParticulas();
	ConjuntoParticulas(int size, bool tipo);
	ConjuntoParticulas(const ConjuntoParticulas &otro);
	~ConjuntoParticulas();
	void setCapacidad(int cap);
	void setUtiles(int util);
	int getCapacidad();
	int getUtiles();
	/**
		 * @brief Aumenta el tamaño del vector dinámico
		**/
	void Redimensiona();
	/**
		 * @brief Reduce el tamaño del vector dinámico hasta el número de partículas
		**/
	void RedimensionaMenor();
	/**
		 * @brief Agrega una partícula al vector
		 * @param p partícula que se va a agregar
		**/
	void AgregaParticula(Particula p);
	/**
		 * @brief Borra una partícula en una posición dada
		 * @param posicion posición de la partícula a borrar
		**/
	void BorraParticula(int posicion);
	/**
		 * @brief Obtiene la partícula en una determinada posición
		 * @param posicion posición de la partícula que se desea obtener
		 * @return Devuelve la partícula
		**/
	Particula& ObtieneParticula(int posicion);
	/**
		 * @brief Reemplaza una partícula del vector con otra
		 * @param otra partícula que va a sustituir a la del vector
		**/
	void ReemplazaParticula(int posicion, Particula &otra);
	/**
		 * @brief Mueve todas las partículas del vector
		 * @param ancho ancho de la ventana
		 * @param alto alto de la ventana
		**/
	void Mover(int ancho, int alto);
	/**
		 * @brief Gestiona las colisiones entre todos los pares de partículas del vector
		**/
	void GestionarColisiones();
	/**
		 * @brief Libera memoria
		**/
	void Liberar();
	
	//sobrecarga operadores =, <<, +
	ConjuntoParticulas operator+(const ConjuntoParticulas &otro) const;
	ConjuntoParticulas& operator=(const ConjuntoParticulas &otro);
	friend ostream& operator<< (ostream& flujo, const ConjuntoParticulas& otro);
	

};

#endif