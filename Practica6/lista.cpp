#include <iostream>

/* MP 18-19. David Pelta

Código de ejemplo de una lista con celdas enlazadas.
(se explicará en clase de prácticas)

Se muestra 
1.- cómo agregar elementos a la lista, 
2.- cómo recorrer la lista
3.- cómo liberar la memoria reservada

*/ 

using namespace std;

struct Celda{
	int valor;
	Celda* sig;
};


 int main(){
 Celda *actual;
 Celda *inicio;
 int n;
 bool primera = true;
 
 cout << "Ingrese un número. 0 para terminar: ";
 cin >> n;
 while (n != 0){
 	Celda *nueva = new Celda;
 	nueva->valor = n;
 	nueva->sig = 0;

 	if(primera){
		inicio = nueva;
	   primera = false;
	}
	else
		actual->sig = nueva;
		
 	actual = nueva;		
 	
	cout << "Ingrese un número. 0 para terminar: ";
 	cin >> n;
 }
 
 
 // muestro la lista;
 Celda *tmp = inicio;
 while (tmp != 0){
  cout << tmp->valor << " ";
  tmp = tmp->sig;
}
 cout << endl;

 // libero la memoria
 Celda *aux = inicio;
 while (aux != 0){
 	tmp = aux;
 	aux = aux->sig;
 	delete tmp;
 }
 
}


