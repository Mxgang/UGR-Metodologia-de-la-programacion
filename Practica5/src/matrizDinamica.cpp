#include<iostream>
#include "myIO.h"

const int TAM_MENU=5;
std::string menu[TAM_MENU]={"Limpiar la matriz",
                            "Dibujar cuadrado",
                            "Rotar",
                            "Mostrar matriz",
                            "Salir"};

void limpiar(char **m, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      m[i][j]='.';
    }
  }
}

void dibujar_cuadrado(char **m, int n, int x, int y, int l){
  int cx=0, cy=0;
  for(int i=x; (cx<l) && (i<n);cx++, i++){
    for(int j=y; (cy<l) && (j<n);cy++, j++){
      m[i][j]='*';
    }
    cy=0;
  }
}

char **rotar(char **m, int n){
  char **r = new char*[n];
  for(int i=0; i<n;i++)
    r[i] = new char[n];

  for(int i=0; i<n/2; i++){
    for(int j=0; j<(n+1)/2; j++){
      r[i][j]=m[n-1-j][i];
      r[n-1-j][i] = m[n-1-i][n-1-j];
      r[n-1-i][n-1-j] = m[j][n-1-i];
      r[j][n-1-i] = m[i][j];
    }
  }
  return r;
}


int  main(){
  
  const int TAM=6;

  MyIO io;

  char **matriz;
  matriz = new char*[TAM];
  for(int i=0; i<TAM; i++)
    matriz[i] = new char[TAM];

  limpiar(matriz,TAM);

  io.imprimeMatriz(matriz, TAM, TAM);
  int opcion;
  do{
    opcion=io.menu(menu, TAM_MENU);

    switch(opcion){
      case 0:{
        limpiar(matriz,TAM);
        std::cout << "\n---Lienzo limpio---\n";
      }break;
      
      case 1:{
        int x, y, l;
        std::cout << "Introduce coordenada x: ";
        x= io.leeFiltrado(0,TAM-1);
        std::cout << "Introduce coordenada y: ";
        y= io.leeFiltrado(0,TAM-1);
        std::cout << "Introduce la longitud del cuadrado: ";
        l= io.leeFiltrado(1,TAM);

        dibujar_cuadrado(matriz, TAM, x, y, l);
        std::cout << "\n---Cuadrado Dibujado [" << x << "," << y << "] l=" << l << "---\n";
      }break;
      
      case 2:{
        char **r=rotar(matriz,TAM);
        std::cout << "\n---Matriz rotada---\n";
        io.imprimeMatriz(r,TAM,TAM);
      }break;
      
      case 3:{
        io.imprimeMatriz(matriz,TAM,TAM);
      }break;
      
      default:{
        std::cout << "\nAdios!\n";
      }break;
    }
  }while(opcion!=4);

  for(int i=0; i<TAM; i++)
    delete[] matriz[i];
  delete[] matriz;

}