#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){

	const int TAM = 100;
	char cadena[TAM];
	char *puntero = cadena;
	char *aux;
	bool resultado = true;
	int tamanio;

	cout << "Introduzca la cadena" << endl;
	cin.getline(cadena,TAM);

	tamanio = strlen(puntero); //tamaño del puntero
	aux = &puntero[tamanio-1]; //apunto aux al final del puntero

	for(int j = 0; j < tamanio; j++, puntero++, aux--){
		if((*puntero == *aux) && resultado){
			resultado = true;
		}
		else{
			resultado = false;
		}
	}

	if(resultado){
		cout << "La cadena es palíndromo" << endl;
	}
	else
		cout << "La cadena no es palíndromo" << endl;
}