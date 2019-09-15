#include <iostream>
#include "calculo.h"

using namespace std;



int main(){

	Calculo matriz;
	int mes, temperatura, dias;
	int minimo[12], maximo[12];

	cout << "Creando matriz y mostrandola" << endl;

	matriz.RellenarMatriz();

	cout << "/----------------------------------------------------/" << endl;

	cout << "Introduce el mes para ver la media mensual" << endl;
	cin >> mes;

	cout << "En el mes " << mes << " ha hecho " << matriz.MediaMensualAjustada(mes) << " grados de media" << endl;

	cout << "/----------------------------------------------------/" << endl;

	matriz.ResumenMaximasMinimas(minimo,maximo);
	cout << "Temperaturas minimas de cada mes" << endl;
	for (int i = 0; i < 12; i++){
		cout << "Mes " << i+1 << ": " << minimo[i] << " grados" << endl;
	}

	cout << endl;

	cout << "Temperaturas maximas de cada mes" << endl;
	for (int i = 0; i < 12; i++){
		cout << "Mes " << i+1 << ": " << maximo[i] << " grados" << endl;
	}

	cout << "/----------------------------------------------------/" << endl;
	cout << "Introduzca la temperatura, numero de dias y mes para ver si en ese mes ha habido X dias seguidos que haya habido más de esa temperatura" << endl;
	cout << "Temperatura: " << endl;
	cin >> temperatura;
	cout << "Numero de dias: " << endl;
	cin >> dias;
	cout << "Mes: " << endl;
	cin >> mes;

	if(matriz.secuenciaDiasCalidos(temperatura, dias, mes)){
		cout << "Si ha ocurrido esa secuencia" << endl;
	}
	else
		cout << "No ha ocurrido esa secuencia" << endl;
 	
 	cout << "/----------------------------------------------------/" << endl;

	cout << "Mostrando la matriz" << endl;

	matriz.mostrarMatriz();

	cout << "/----------------------------------------------------/" << endl;




}