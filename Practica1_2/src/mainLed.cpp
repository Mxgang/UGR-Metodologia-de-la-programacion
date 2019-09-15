#include "leds.h"

int main(){
 
 	const int TAM = 100;

	bool vectorLeds[TAM];
	Led miLed;
	string salida;


	/*-------------------------------*/
	miLed.apagaTodo(vectorLeds, TAM);
	salida = miLed.toString(vectorLeds, TAM);
	cout << "Todo apagado " << endl;
	cout << salida << endl;
	cout << endl;

	/*-------------------------------*/
	for(int i = 0; i < TAM; i+=2){
		miLed.enciendeLed(vectorLeds, TAM, i);
	}
	salida = miLed.toString(vectorLeds, TAM);
	cout << "Pares encendidos" << endl;
	cout << salida << endl;
	cout << endl;

	/*-------------------------------*/
	for(int i = 0; i < TAM; i+=2){
		miLed.apagaLed(vectorLeds, TAM, i);
	}
	for(int i = 1; i < TAM; i+=2){
		miLed.enciendeLed(vectorLeds, TAM, i);
	}
	salida = miLed.toString(vectorLeds, TAM);
	cout << "Pares apagados e impares encendidos" << endl;
	cout << salida << endl;
	cout << endl;



}