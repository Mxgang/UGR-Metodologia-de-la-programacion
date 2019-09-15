#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int longitud(char *c){
	int l = 0;
	while(*c!='\0'){
		l++; c++;
	}
	return l;
}

char * subcadena(char *cadena, char * sub, int p, int l){
	char *ptr, *i;

	i = &sub[0]; //apunto al inicio

	ptr = &cadena[p]; //apunto a la direccion p

	for(int j = 0; j < l; j++, ptr++, i++){
		*i = *ptr;
	}
	return sub;
}

int main(){

	const int TAM = 100;
	int tamanio, l, posicion;
	char cadena[TAM];
	char *sub;
	char *aux;

	cout << "Introduzca la cadena" << endl;
	cin.getline(cadena,TAM);

	tamanio = longitud(cadena);
	cout << "El tamaño de la cadena es:" << tamanio << endl;

	do{
		cout << "Introduzca la posicion de inicio entre la posicion 0 y " << tamanio-1 << endl;
		cin >> posicion;
	}while(posicion <= 0 && posicion > tamanio); //comprobar que se da una posicion valida

	cout << "Introduzca la longitud de la cadena" << endl;
	cin >> l;

	if(posicion + l > tamanio){ //si la longitud se sale de la cadena, se establece de tamaño desde la posicion p hasta el final de la cadena
		l = tamanio-posicion;
	}
	cout << "Longitud de la subcadena: " << l << endl;
	char c_i[l];

	sub = subcadena(cadena, c_i, posicion, l);

	cout << "La subcadena es: ";
	
	cout << sub << endl;

}
