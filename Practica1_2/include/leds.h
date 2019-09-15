#ifndef __Led_h__
#define __Led_h__

#include <iostream>
#include <string>

using namespace std;

class Led
{

	public:
		void apagaTodo(bool v[], int n);

		void enciendeTodo(bool v[], int n);

		void enciendeLed(bool v[], int n, int j);

		void apagaLed(bool v[], int n, int j);

		string toString(bool v[], int n);

};

#endif
