#include <iostream>

/* MP 18-19. David Pelta

C�digo de ejemplo de una lista con celdas enlazadas.
(se explicar� en clase de pr�cticas)

Se muestra 
1.- c�mo agregar elementos a la lista, 
2.- c�mo recorrer la lista
3.- c�mo liberar la memoria reservada

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
 
 cout << "Ingrese un n�mero. 0 para terminar: ";
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
 	
	cout << "Ingrese un n�mero. 0 para terminar: ";
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


