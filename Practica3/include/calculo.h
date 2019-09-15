#ifndef __Calculo_h__
#define __Calculo_h__

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

const int MIN = -10, MAX=10, NUM_VALORES = MAX-MIN+1;
const int filas = 12;
const int columnas = 12;


class Calculo
{
	private:

		int m[filas][columnas];

	public:

		void RellenarMatriz();

		int MediaMensualAjustada(int mes);

		void ResumenMaximasMinimas(int minimo[], int maximo[]);

		bool secuenciaDiasCalidos(int t, int d, int m);

		void mostrarMatriz();

};

#endif
