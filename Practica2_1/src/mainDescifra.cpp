#include "descifra.h"
#include <iostream>
#include <cstring>

int main(){
	Descifra descifrador;

	char* frase1("Hidrogeno limpia ");
	char* frase2("Hidrogeno limpia");
	char* frase3("Hidrogeno");
	char* frase4("Hidrogeno ");
	char* frase5("H");
	char* frase6("H ");

	std::cout << "Prueba: n="<< std::strlen(frase1) << " resultado=" << descifrador.terminaPalabra(frase1, std::strlen(frase1), std::strlen(frase1)-1) << "\n";
	
	std::string sol = descifrador.descifra(frase1, std::strlen(frase1));
	std::cout << "[Hidrogeno limpia ] -> " << sol ;

	sol = descifrador.descifra(frase2, std::strlen(frase2));
	std::cout << "\n[Hidrogeno limpia] -> " << sol ;

	sol = descifrador.descifra(frase3, std::strlen(frase3));
	std::cout << "\n[Hidrogeno] -> " << sol ;

	sol = descifrador.descifra(frase4, std::strlen(frase4));
	std::cout << "\n[Hidrogeno ] -> " << sol ;

	sol = descifrador.descifra(frase5, std::strlen(frase5));
	std::cout << "\n[H] -> " << sol;

	sol = descifrador.descifra(frase6, std::strlen(frase6));
	std::cout << "\n[H ] -> " << sol << "\n";					

 return 0;
}