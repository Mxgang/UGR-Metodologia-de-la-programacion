#include <iostream>
#include<math.h>

const int TOPE=100;

struct Punto2D{
  double x;
  double y;
};

int longitud(char *c){
	int l = 0;
	while(*c!='\0'){
		l++; c++;
	}
	return l;
}

//Funcion para separar las dos coordenadas dada una linea del fichero
char* subcadena(char *cadena) {
    char *puntero;
    int pos = 0;

    for (puntero = cadena; *puntero != ' '; puntero++)
        pos++;

    *puntero= '\0'; puntero++;

    return puntero;
}

double distanciaEuclidea (Punto2D *p1, Punto2D *p2)
{
	double dif_x = pow (p1->x - p2->x, 2);
	double dif_y = pow (p1->y - p2->y, 2);

	return (sqrt(dif_x + dif_y));
}

int leePuntos(Punto2D *puntos, int n){
  char linea[TOPE], *c, *x, *y;

  //terminamos la linea
  std::cin.getline(linea,TOPE);

  for(int i=0; i<n && !std::cin.eof(); i++){
    
    std::cin.getline(linea,TOPE);

    c = linea;
    x = new char(longitud(c));
    y = new char(longitud(c));

    y=subcadena(c);
    x=c;

    puntos->x=atoi(x);
    puntos->y=atoi(y);

    puntos++;
  }

  return n;
}

void imprimePuntos(Punto2D *puntos, int n){
  
  std::cout << "Hay " << n << " puntos:\n";
  for(int i=0; i<n; i++){
    std::cout << "P" << i << "=[" << puntos->x << "," << puntos->y << "]\n";
    puntos++;
  }

}

int main(){
  int n = 0;
  std::cin >> n;
  Punto2D *puntos = new Punto2D[n];
  
  leePuntos(puntos, n);

  imprimePuntos(puntos, n);

  double menor_distancia = distanciaEuclidea(&puntos[0],&puntos[1]);
  int p1=0, p2=1;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      double tmp = distanciaEuclidea(&puntos[i], &puntos[j]);
      if(menor_distancia > tmp){
        menor_distancia = tmp;
        p1=i;
        p2=j;
      }
    }
  }

  std::cout << "\nLa menor distancia es " << menor_distancia << " y es entre P" << p1 << " y P" << p2 << "\n";

  delete [] puntos;

  return 0;
}
