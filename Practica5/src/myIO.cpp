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


void MyIO::imprimeVector(char *v, int n, int col){
  std::cout << "Vector:{\n";
  for(int i=0; i<n-1; i++){
    std::cout << *v << ",\t";
    v++;
    if((i+1)%col == 0) std::cout << "\n";
  }
  std::cout << *v << "\t}\n";
}


void MyIO::imprimeMatriz(char **m, int fil, int col){
  std::cout << "Matriz:\n";
  for(int i=0; i<fil; i++){
    for(int j=0; j<col; j++){
      std::cout << m[i][j] << "   ";
    }
    std::cout << "\n";
  }
}

void MyIO::imprimeMatriz(float **m, int fil, int col){
  std::cout << "Matriz:\n";
  for(int i=0; i<fil; i++){
    for(int j=0; j<col; j++){
      std::cout << m[i][j] << "   ";
    }
    std::cout << "\n";
  }
}

void MyIO::imprimeMatriz(double **m, int fil, int col){
  std::cout << "Matriz:\n";
  for(int i=0; i<fil; i++){
    for(int j=0; j<col; j++){
      std::cout << m[i][j] << "   ";
    }
    std::cout << "\n";
  }
}

void MyIO::imprimeMatriz(int **m, int fil, int col){
  std::cout << "Matriz:\n";
  for(int i=0; i<fil; i++){
    for(int j=0; j<col; j++){
      std::cout << m[i][j] << "   ";
    }
    std::cout << "\n";
  }
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

int MyIO::leeFiltrado(int min, int max){
  int elemento;
  
  do{
    std::cout << "\n-->";
    std::cin >> elemento;
  }while(!filtro(elemento,min,max));

  return elemento;
}

void MyIO::error(const char * mensaje){
  std::cout << mensaje << "\n";
}

int MyIO::menu(std::string opciones[], int n){
  for(int i=0; i<n; i++){
    std::cout << "[" << i << "]- " << opciones[i] << "\n"; 
  }
  
  int opcion=-1;
  do{
    std::cout << "\nIntoduce una opcion\n--> ";
    std::cin >> opcion;
  }while(!filtro(opcion,0,n));

  return opcion;
}