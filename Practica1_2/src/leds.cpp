#include "leds.h"
#include <iostream>

void Led::apagaTodo(bool v[], int n){

	for(int i = 0; i < n; i++)
		v[i] = false;

}

void Led::enciendeTodo(bool v[], int n){

	for(int i = 0; i < n; i++)
		v[i] = true;
	
}

void Led::enciendeLed(bool v[], int n, int j){

	v[j] = true;

}

void Led::apagaLed(bool v[], int n, int j){

	v[j] = false;
	
}

string Led::toString(bool v[], int n){

	string salida;
	for(int i = 0; i < n; i++)
		salida += to_string(v[i]);
	return salida;

}