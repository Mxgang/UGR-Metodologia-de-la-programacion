#include <iostream>
#include "fruteria.h"

int main()
{
    const int TAM = 10;
    Producto actual;
    Compra mi_compra;
    float precio;
    float peso;
    string nombre;
    Fruteria mi_fruteria;

    for(int i = 0; i < TAM; i++)
    {
        cin >> nombre >> peso >> precio;
        mi_compra.lista[i] = mi_fruteria.creaProducto(nombre, peso, precio);
    }

    // se muestra la lista de productos.
    cout << "\n ******** Prueba de funcion listarCompra ******** \n";
    mi_fruteria.listarCompra(mi_compra);

    // se muestra el importe total de la compra y el peso
    cout << "\n ******** Prueba de funcion obtenerImporteYPeso ******** \n";
    mi_fruteria.obtenerImporteYPeso(mi_compra, precio, peso);
    cout << "\nEl importe de la compra es: " << precio << ", su compra pesa:" 
		 << peso << " Kg. " << endl;

    // se muestra el ticket de la compra.
    cout << "\n ******** Prueba de la funcion mostrarTicketCompra ******** \n";
    mi_fruteria.mostrarTicketCompra(mi_compra);

    cout << "\n ******** Prueba de la funcion incrementarPrecio ********";
    mi_fruteria.incrementarPrecios(mi_compra, 10);
    cout << "\n ******** y listarCompra de nuevo   \t\t********\n\n";
    mi_fruteria.listarCompra(mi_compra);

    return(0);
}