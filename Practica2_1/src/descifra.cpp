#include "descifra.h"

char* Descifra::descifra(char *v, int n){
	std::string rta;
	char *sol=(char*)malloc(sizeof(char));

	for(int i=0; i<n; i++){
		if(comienzaPalabra(v,n,i)){
			rta=rta + v[i];
			//std::cout << "comienza una palabra por [" << v[i] << "] llevamos [" << rta << "]\n"; 
		}
		else if(terminaPalabra(v,n,i)){
			rta+=v[i];
			//std::cout << "termina una palabra por [" << v[i] << "] llevamos [" << rta << "]\n"; 

		}
	}
	
	return std::strcpy(sol, rta.c_str());
}

bool Descifra::terminaPalabra(char *v, int n, int j){
	bool termina;

		if(j==n-1){
			termina=false;
		}
		else if(v[j+1]==' '){
			termina=true;
		}
		else{
			termina=false;
		}

	return termina;
}

bool Descifra::comienzaPalabra(char *v, int n, int j){
	bool comienza=false;

		if(j==n-1){
			comienza=false;
		}
		else if(j==0 || v[j-1]==' '){
			comienza=true;
		}
		else{
			comienza=false;
		}

	return comienza;
}

std::string Descifra::toString(char *v, int n){

	std::string salida;
	for(int i = 0; i < n; i++)
		salida += std::to_string(v[i]);
	return salida;

}