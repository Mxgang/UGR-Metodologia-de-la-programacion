#include<iostream>

int encuentra(char *c, char valor){
  char *v;
  bool terminador=false;
  int pos=-1;

  while((*c != '\0') && !terminador){
    if(*c==valor){
      terminador=true;
      pos;
    }
          
    c++; pos++;
  }

  return pos;
}

int main(){

  char line[100];

  std::cout << "Escribe algo, te dire en que posicion esta el primer espacio\n";

  std::cin.getline(line, 100);

  int pos=encuentra(line, ' ');

  std::cout << "\nHay un espacio en la posicion: " << pos << "\n";

  return 0;
}