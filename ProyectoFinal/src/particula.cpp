#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "particula.h"

Particula::Particula(){

	x = rand()%MIN_X+1;
	y = rand()%MIN_Y+1;
	dx = rand()%UMBRAL+1;
	dy = rand()%UMBRAL+1;
	c = AZUL;
}

Particula::Particula(float valor_x, float valor_y){

	x = valor_x;
	y = valor_y;
	dx = 1.0;
	dy = 1.0;
	c = ROJO;
}

float Particula::Distancia(Particula B){

	float distancia;

	distancia = sqrt((B.getX() - getX())*(B.getX() - getX()) + (B.getY() - getY())*(B.getY() - getY()));

	return distancia;
}

bool Particula::Colision(Particula B){

	float distancia;
	bool hay_colision;
	distancia = Distancia(B);
	if(distancia > UMBRAL)
		hay_colision = false;
	else
		hay_colision = true;

	return hay_colision;
}


void Particula::Mover(int ancho, int alto){

	const float factor = 0.95;
   x += dx;
   y += dy;
   if (x > ancho - RADIO) {
      dx = -dx * factor;
      x = ancho - RADIO;
   }
    else if (x < RADIO) {
      dx = -dx * factor;
      x = RADIO;
   }
    else if (y >alto - RADIO) {
      dy = -dy * factor;
      y = alto - RADIO;
   }
    else if (y < RADIO) {
      dy = -dy * factor;
      y = RADIO;
   }
}

void Particula::Rebota(Particula & otra){

	float aux;

	aux = dx;
	dx = otra.getDX();
	otra.setDX(aux);
	
	aux = dy;
	dy = otra.getDY();
	otra.setDY(aux);
}

float Particula::getX(){

	return x;
}

float Particula::getY(){

	return y;
}

float Particula::getDX(){

	return dx;
}

float Particula::getDY(){

	return dy;
}

Color Particula::getColor(){

	return c;
}

void Particula::setX(float valor){

	x = valor;
}

void Particula::setY(float valor){

	y = valor;
}

void Particula::setDX(float valor){

	dx = valor;
}

void Particula::setDY(float valor){

	dy = valor;
}

void Particula::setColor(Color colour){
	
	c = colour;
}


