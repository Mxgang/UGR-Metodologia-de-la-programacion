#include "myIO.h"

void MyIO::imprimeVector(int *v, int n, int col){
  std::cout << "Vector:{\n";
  for(int i=0; i<n-1; i++){
    std::cout << *v << ",\t";
    v++;
    if((i+1)%col == 0) std::cout << "\n";
  }
  std::cout << *v << "\t}\n";
}

void MyIO::imprimeVector(float *v, int n, int col){
  std::cout << "Vector:{\n";
  for(int i=0; i<n-1; i++){
    std::cout << *v << ",\t";
    v++;
    if((i+1)%col == 0) std::cout << "\n";
  }
  std::cout << *v << "\t}\n";
}


int MyIO::leeNumeroFiltrado(int min, int max){
  int numero;
  
  do{
    std::cout << "Introduce un numero comprendido en [" << min << "," << max << "]\n-->";
    std::cin >> numero;
  }while((numero < min) && (numero > max));

  return numero;
}


float MyIO::leeNumeroFiltrado(float min, float max){
  float numero;
  
  do{
    std::cout << "Introduce un numero comprendido en [" << min << "," << max << "]\n-->";
    std::cin >> numero;
  }while((numero < min) && (numero > max));

  return numero;
}


double MyIO::leeNumeroFiltrado(double min, double max){
  double numero;
  
  do{
    std::cout << "Introduce un numero comprendido en [" << min << "," << max << "]\n-->";
    std::cin >> numero;
  }while((numero < min) && (numero > max));

  return numero;
}


bool MyIO::filtro(int elemento, int min, int max){
  bool correcto=false;
  if((elemento >= min) && (elemento <= max))
    correcto=true;
  return correcto;
}


bool MyIO::filtro(char elemento, char min, char max){
  bool correcto=false;
  if((elemento >= min) && (elemento <= max))
    correcto=true;
  return correcto;
}

void MyIO::error(const char * mensaje){
  std::cout << mensaje << "\n";
}