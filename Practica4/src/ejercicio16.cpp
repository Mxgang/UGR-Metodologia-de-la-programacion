#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "myIO.h"

int* PosMayor (int *pv, int izda, int dcha){
  int *mayor;
  for(int i=0; i<=dcha; i++){
    if(i==izda){
      mayor=&*pv;
    }
    else if((i>izda) && (*pv > *mayor)){
      mayor=&*pv;
    }

    pv++;
  }

  return mayor;
}

void RellenaVector(int *v, int n, int min=-10, int max=10){
  srand (time(NULL));

  for(int i=0; i<n; i++){
    *v = (rand() % (abs(min)+max)) + min;
    v++;
  }
}

int main(int argc, char **argv){
  MyIO io;
  
  const int TOPE = 100;
  int vector [TOPE];

  int casillas = TOPE, izq=0, der=TOPE-1;


  // Comprobamos el numero de argumentos y asignamos las variables
  if(argc > 4){
    std::cerr << "Numero de argumentos incorrecto:\n\tejercicio16 [n_casillas [ derecha [ izquierda ]]]\n";
    return -1;
  }
  else{
    //Un argumento o mas, asignamos el num casillas a rellenar
    if(argc > 1){
      casillas = atoi(argv[1]);
      if(!io.filtro(casillas, 1, TOPE)){
        std::cerr << "casillas a rellenar fuera de limites [1," << TOPE << ')' << '\n';
        return -1;
      }
      der = casillas-1;
    }

    //Dos argumentos o mas, asignamos derecha tambien
    if(argc > 2){
      der = atoi(argv[2]);
      if(!io.filtro(der, 0, casillas-1)){
        std::cerr << "tope derecho fuera de limites [0," << casillas << ')' << '\n';
        return -1;
      }
    }

    //Tres argumentos asignamos izquierda
    if(argc > 3){
      izq = atoi(argv[3]);
      if(!io.filtro(izq, 0, der)){
        std::cerr << "tope izquierdo fuera de limites [0," << der << ']' << '\n';
        return -1;
      }
    }
    std::cout << "\n";
  }

  // Rellenamos el vector de numeros aleatorios
  RellenaVector(&vector[0], casillas);

  std::cout << "Casillas: " << casillas << "\nDer: " << der << "\nIzq: " << izq <<  "\n\n";
  
  // Buscamos el elemento mayor
  int *mayor = PosMayor(&vector[0], izq, der);

  // Imprimimos el vector y el resultado
  io.imprimeVector(&vector[0], casillas);
  std::cout << "\nMayor elemento entre [" << izq << "," << der << "] = " << *mayor << "\n";

  return 0;
}