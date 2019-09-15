#include <iostream>
#include <string>
#include "fruteria.h"

using namespace std;

// función para devolver los datos de un producto como un string
string Fruteria::productoToString(Producto a){

    string rta;
    rta = a.nombre + "\t\t" + to_string(a.peso) + "\t" + to_string(a.precio_kg);
    return rta;

}

// crea una variable de tipo Producto y la devuelve
Producto Fruteria::creaProducto(string nombre, int peso, float precio)
{
    Producto producto;
    producto.nombre = nombre;
    producto.peso = peso;
    producto.precio_kg = precio;

    return producto;
}

// incrementa el precio de cada producto en un k %
void Fruteria::incrementarPrecios(Compra & c, int k)
{
    for(int i = 0; i < 10; i++){
        c.lista[i].precio_kg = c.lista[i].precio_kg + ((c.lista[i].precio_kg * k) / 100);
    }
}

// muestra el listado de productos comprados
void Fruteria::listarCompra(const Compra & c)
{
    for(int i = 0; i < 10; i++){
        cout << productoToString(c.lista[i]) << endl;
    }
}

// función que devuelve el importe total de la compra (sin IVA) y su peso (en kgs)
void Fruteria::obtenerImporteYPeso(const Compra & c, float & precio, float & peso)
{
    for(int i = 0; i < 10; i++){
        precio = precio + (c.lista[i].precio_kg * c.lista[i].peso);
        peso = peso + c.lista[i].peso;
    }
    //se pasa el peso a kilogramos
    peso = peso/1000;
    //pasamos el precio a precio/kg
    precio = precio/1000;
}

// función que muestra el "ticket" de compra según el formato sugerido
void Fruteria::mostrarTicketCompra(const Compra & c)
{
    float pr, pe, iva_producto, precio_con_iva;
    const int iva = 21;
    listarCompra(c);
    obtenerImporteYPeso(c,pr,pe);
    iva_producto = (pr * iva )/100;
    precio_con_iva = pr + iva_producto;
    cout << "Subtotal: " << "\t\t" << pr << endl;
    cout << "IVA(21): " << "\t\t" << iva_producto << endl;
    cout << "Total de la compra: " << "\t" << precio_con_iva << endl;
}



