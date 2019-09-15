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

char * invierte(char *cadena, char *invertida, int tamanio){
	char *p,*i;

	i = &invertida[tamanio-1];	
	
	for(p=cadena; *p!='\0'; p++, i--){
		*i = *p;
	}

	return invertida;
}



int main(){

	const int TAM = 100;
	int tamanio;
	char cadena[TAM];
	char *invertida;

	cout << "Introduzca la cadena" << endl;
	cin.getline(cadena,TAM);

	tamanio = longitud(cadena);
	cout << "El tamaño de la cadena es:" << tamanio << endl;
	
	char c_i[tamanio];

	invertida = invierte(cadena, c_i, tamanio);

	cout << "La cadena invertida es: ";

	cout << invertida;

	cout << endl;

}
