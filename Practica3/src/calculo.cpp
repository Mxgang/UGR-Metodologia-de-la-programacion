#include <iostream>
#include "calculo.h"

void Calculo::RellenarMatriz(){
	
	int i,j, util_f, util_c;

	
	time_t t;
	srand ((int) time(&t));
	
	// relleno la matriz con valores aleatorios
	for(i = 0; i < filas; i++)
		for(j = 0; j < columnas; j++)
			m[i][j] = (rand() % NUM_VALORES) + MIN;
	
	util_f = filas; util_c = columnas;
	
	// muestro la matriz 
	mostrarMatriz();


}

int Calculo::MediaMensualAjustada(int mes){

	int media;
	for(int i = 0; i < columnas; i++){
		media += m[mes][i];
	}

	media /= 31;
	return media;

}

void Calculo::ResumenMaximasMinimas(int minimo[], int maximo[]){

	int min = 0;
	int max = 0;
	//calculo del minimo
	for(int i = 0; i < filas; i++){
		min = m[i][0];
		for(int j = 0; j < columnas; j++){
			if(m[i][j] < min)
				min = m[i][j];
		}
		minimo[i] = min;	
	}
	//calculo del maximo
	for(int i = 0; i < filas; i++){
		max = m[i][0];
		for(int j = 0; j < columnas; j++){
			if(m[i][j] > max)
				max = m[i][j];
		}
		maximo[i] = max;
	}

}

bool Calculo::secuenciaDiasCalidos(int t, int dias, int mes){

	int contador = 0;
	for(int i = 0; i < columnas; i++){
		if(m[mes][i] > t && contador < dias)
			contador++;
		else if(m[mes][i] <= t && contador < dias)
			contador = 0;
	}
	if(contador == dias)
		return true;
	else
		return false;

}

void Calculo::mostrarMatriz(){
	for(int i = 0; i < filas; i++){
		cout << "Temperatura en el mes " << i+1 << ": ";
		for(int j = 0; j < columnas; j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

}