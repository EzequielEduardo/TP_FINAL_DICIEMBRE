#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstring>
#include <cstdio>
#include<string.h>

#include "ArticuloNegocio.h"
#include "Transaxinventario.h"
#include "TransaxinventarioNegocio.h"
#include "CompraNegocio.h"
#include "CompraVista.h"

using namespace std;


bool CompraVista::cargarCompras()
{
    TransaxinventarioNegocio negocio;
	char cadena[20];
    int entero,dia,mes,anio;
    float decimal;

    cout<<"Datos de la fecha actual: "<<endl;
    cout<<"Dia: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Anio: ";
    cin>>anio;

    TransaxInventario compra(dia,mes,anio);

    cout<<"--------------------------------------"<<endl;

    cout << "Datos de la Compra:"<<endl;
    cout<<"Ingresar: "<<endl;

    cout<<"Factura de Compra: ";
        negocio.cargarCadena(cadena,20);
        compra.setNroFactura(cadena);

    cout<<"ID_Articulo: ";
        negocio.cargarCadena(cadena,20);
        compra.setTRID_Articulo(cadena);

    cout<<"Categoria:";
        negocio.cargarCadena(cadena,20);
        compra.setCategoria(cadena);

	cout<<"Marca:";
    negocio.cargarCadena(cadena,20);
    compra.setMarca(cadena);

    cout<<"Cantidad:";
        cin>>entero;
        compra.setTRCantidad(entero);

    cout<<"Costo Unitario: ";
		cin>>decimal;
        compra.setTRprecioUnitario(decimal);

    negocio.actualizarstock(1,compra); //  llamo al metodo de la clase TransaxinventarioNegocio que va a modificar el stock y stockValorizado
    return negocio.guardarDatosCompra(compra); // guarda reg en file compras.dat
}

bool CompraVista::mostrarCompras(){

	TransaxinventarioNegocio negocio;
    TransaxInventario *vectorCompras;

    vectorCompras=negocio.Cargar_Vector_de_Compras();///get_compras

		 cout<< "LISTADO DE COMPRAS REALIZADAS"<<endl;
        for(int x;x<negocio.CantidadDeCompras();x++){
		cout<< "Factura de Compra: "<<vectorCompras[x].getNroFactura() <<endl;
        cout<< "ID_Articulo: "<<vectorCompras[x].getTRID_Articulo() <<endl;
        cout<< "Categoria: "<<vectorCompras[x].getCategoria() <<endl;
        cout<< "Marca: "<<vectorCompras[x].getMarca() <<endl;
		cout<< "Fecha de compra: ";vectorCompras[x].getFechaTransax().MostrarFecha();
        cout<< "Cantidad: "<<vectorCompras[x].getTRCantidad() <<endl;
        cout<< "Costo Unitario: "<<vectorCompras[x].getTRprecioUnitario() <<endl;
        cout<< "-------------------------"<<endl;}

    delete vectorCompras;

}
