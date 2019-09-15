#ifndef __Descifra_h__
#define __Descifra_h__

#include <iostream>
#include <string>
#include <cstring>

class Descifra
{

	public:

		char* descifra(char *v, int n);
		bool  terminaPalabra(char *v, int n, int j);
		bool	comienzaPalabra(char *v, int n, int j);
		std::string toString(char *v, int n);

};

#endif
