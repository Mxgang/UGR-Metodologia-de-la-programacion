#ifndef __Fruteria_h__
#define __Fruteria_h__

#include <iostream>
#include <string>

using namespace std;

struct Producto
{
    string nombre;
    int peso; // en gramos
    float precio_kg;
};

struct Compra
{
    static const int MAX = 10;
    Producto lista[MAX];
};


class Fruteria
{

	public:
		string productoToString(Producto a);

		Producto creaProducto(string nombre, int peso, float precio);

		void incrementarPrecios(Compra & c, int k);

		void listarCompra(const Compra & c);

		void obtenerImporteYPeso(const Compra & c, float & precio, float & peso);

		void mostrarTicketCompra(const Compra & c);

};

#endif
