#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//Ejercicio 1
void Redimensiona(int * &p, int tipo, int &cap){
	int aux = cap;
	if(tipo == 1){
		cap = cap+1;
		
	}
	else if(tipo == 2){
		int TAM_BLOQUE;
		cout << "Introduzca el tamaño del bloque" << endl;
		cin >> TAM_BLOQUE;
		cap = cap+TAM_BLOQUE;
	}
	else{
		cap = cap*2;
	}

	int *p_ampliado = new int[cap];
	for(int i = 0; i < aux; i++){
		p_ampliado[i] = p[i];
	}
	delete [] p;
	p = p_ampliado;

}

//Ejercicio2
int * obtenerSegmento(int * p, int longitud, int &tamanio){

	int *segmento = new int[tamanio]; //inicializo este vector a un tamaño inicial de 0
	int j = 0;
	for(int i = 0; i < longitud; i++, p++){ //recorro el puntero

		if(*p%2 != 0){ //si es impar el valor

			if(tamanio == j){ //si se ha alcanzado el tamaño máximo, se redimensiona
				Redimensiona(segmento,1,tamanio);
			}
			segmento[j] = i; 
			j++;
		}
	}

	return segmento;
}

int main(){

	int TAM;
	int centinela = -1;
	int valor;
	int longitud = 0;
	int opcion;
	int tamanio_segmento = 0;

	cout << "Introduzca el tamaño inicial del array" << endl;
	cin >> TAM;

	int *p = new int[TAM];

	cout << "Introduzca un valor (-1 para terminar)" << endl;
	cin >> valor;

	while(valor != centinela){
		
		if(longitud == TAM-1){

			do{
				cout << "Elige una de las 3 opciones de redimensionamiento" << endl;
				cin >> opcion;
			}while(opcion < 1 || opcion > 3);

			Redimensiona(p,opcion,TAM);

			cout << "El tamaño del array es ahora: " << TAM << endl;
			p[longitud] = valor;

		}
		else{

			p[longitud] = valor;

		}

		longitud++;

		cout << "Introduzca un valor (-1 para terminar)" << endl;
		cin >> valor;
	}

	int *segmento = obtenerSegmento(p,longitud,tamanio_segmento);

	int *aux = &p[0];
	cout << "El contenido del array es: ";
	for(int i = 0; i < longitud; i++, aux++){

		cout << *aux << " ";

	}
	cout << endl;

	cout << "El contenido del array con las posiciones de los valores impares es: ";
	for(int i = 0; i < tamanio_segmento; i++, segmento++){

		cout << *segmento << " ";

	}
	cout << endl;

	//delete [] segmento;
	delete [] p;


}
