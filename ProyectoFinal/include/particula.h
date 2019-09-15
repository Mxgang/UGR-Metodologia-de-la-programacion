/**
  * @file particula.h
  * @brief Fichero cabecera de la partícula
  *
  */


#ifndef _PARTICULA_H_
#define _PARTICULA_H_

#include <iostream>
#include "miniwin.h"
#include "definiciones.h"

using namespace miniwin;

const int RADIO = 10;

class Particula{
	

private:

	float x, y;
	float dx, dy;
	Color c;

public:

	/**
		 * @brief Constructor por defecto
		**/
	Particula();
	/**
		 * @brief Constructor con parámetros
		 * @param valor_x valor de la posición x
		 * @param valor_y valor de la posición y
		**/
	Particula(float valor_x, float valor_y);
	/**
		 * @brief Calcula la distancia entre dos partículas
		 * @param B partícula a la que calcular la distancia
		 * @return Devuelve la distancia de las 2 partículas
		**/
	float Distancia(Particula B);
	/**
		 * @brief Determina si hay colisión entre 2 partículas
		 * @param B partícula a la que averiguar si se colisiona
		 * @return Devuelve true o false si ha habido o no colisión
		**/
	bool Colision(Particula B);
	/**
		 * @brief Mueve la partícula a una ubicación determinada
		 * @param ancho ancho de la ventana
		 * @param alto alto de la ventana
		**/
	void Mover(int ancho, int alto);
	/**
		 * @brief Realiza el rebote entre 2 partículas
		 * @param otra partícula a la que averiguar si se rebota
		**/
	void Rebota(Particula & otra);
	float getX();
	float getY();
	float getDX();
	float getDY();
	Color getColor();
	void setX(float valor);
	void setY(float valor);
	void setDX(float valor);
	void setDY(float valor);
	void setColor(Color colour);

};


#endif