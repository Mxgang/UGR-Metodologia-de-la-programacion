#include <iostream>

Particula::Pelota(){

}

Particula::Pelota(float valor_x, float valor_y){
	x = valor_x;
	y = valor_y;
	dx = 1.0;
	dy = 1.0;
	c = ROJO;
}

Particula::Distancia(Particula A, Particula B){
	float distancia;

	distancia = sqrt((A.get_x() - A.get_y())*(A.get_x() - A.get_y()) + (B.get_x() - B.get_y())*(B.get_x() - B.get_y()));

	return distancia;
}

Particula::Colision(Particula A, Particula B){
	float distancia;
	//bool hay_colision;
	distancia = Distancia(A, B);
	/*if(distancia < UMBRAL)
		hay_colision = false;
	else
		hay_colision = true;*/

	return distancia < UMBRAL

}

Particula::get_x(){
	return x;
}

Particula::get_y(){
	return y;
}

Particula::get_dx(){
	return dx;
}

Particula::get_dy(){
	return dy;
}

Particula::set_x(float valor){
	x = valor;
}

Particula::set_y(float valor){
	y = valor;
}

Particula::set_dx(float valor){
	dx = valor;
}

Particula::set_dy(float valor){
	dy = valor;
}


