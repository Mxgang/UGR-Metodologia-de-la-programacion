#ifndef _PARTICULA_H_
#define _PARTICULA_H_

#include <iostream>
#include "miniwin.h"

class Pelota{
	

private:

	float x, y;
	float dx, dy;
	Color c;

public:

	Particula();
	Pelota(float valor_x, float valor_y);
	float Distancia(Particula A, Particula B);
	bool Colision(Particula A, Particula B);
	float get_x();
	float get_y();
	float get_dx();
	float get_dy();
	void set_x(float valor);
	void set_y(float valor);
	void set_dx(float valor);
	void set_dy(float valor);

};


#endif