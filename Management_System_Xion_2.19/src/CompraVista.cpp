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

	compra.setStatus(true);

    negocio.actualizarstock(1,compra); //  llamo al metodo de la clase TransaxinventarioNegocio que va a modificar el stock y stockValorizado
    return negocio.guardarDatosCompra(compra); // guarda reg en file compras.dat
}

bool CompraVista::mostrarCompras(){

	TransaxinventarioNegocio negocio;
    TransaxInventario *vectorCompras;

    vectorCompras=negocio.Cargar_Vector_de_Compras();///get_compras

		 cout<< "LISTADO DE COMPRAS REALIZADAS"<<endl;
        for(int x;x<negocio.CantidadDeCompras();x++){
		if(vectorCompras[x].getStatus()==true){
		cout<< "Factura de Compra: "<<vectorCompras[x].getNroFactura() <<endl;
        cout<< "ID_Articulo: "<<vectorCompras[x].getTRID_Articulo() <<endl;
        cout<< "Categoria: "<<vectorCompras[x].getCategoria() <<endl;
        cout<< "Marca: "<<vectorCompras[x].getMarca() <<endl;
		cout<< "Fecha de compra: ";vectorCompras[x].getFechaTransax().MostrarFecha();
        cout<< "Cantidad: "<<vectorCompras[x].getTRCantidad() <<endl;
        cout<< "Costo Unitario: "<<vectorCompras[x].getTRprecioUnitario() <<endl;
        cout<< "-------------------------"<<endl;
        }
        }
    delete vectorCompras;

}


void CompraVista::MostrarComprasxFecha(){
TransaxinventarioNegocio obj1;
int dia, mes, anio;
char CODEART[20];
			cout<<"LISTADO DE VENTAS X PRODUCTO Y FECHA"<<endl;
			cout<<endl;
			cout<<"INGRESE LA FECHA DE STOCK: "<<endl;
				cout<<"Dia: ";
				cin>>dia;
				cout<<"Mes: ";
				cin>>mes;
				cout<<"Anio: ";
				cin>>anio;

			TransaxInventario obj(dia,mes,anio);

			cout<<"INGRESE CODIGO DE ARTICULO: "<<endl;
			cin>>CODEART;
			cout<<endl;
			obj.setTRID_Articulo(CODEART);


TransaxInventario *vectorStock=obj1.Cargar_Vector_de_Compras(); // vector que contiene todo el file inventario

	  for(int x=0;x<obj1.CantidadDeTransax();x++){
			if(obj.getFechaTransax()==vectorStock[x].getFechaTransax() &&
				strcmp(obj.getTRID_Articulo(),vectorStock[x].getTRID_Articulo())==0 &&
				vectorStock[x].getStatus()==true){
				cout<<"CODIGO DE ARTICULO: "<<vectorStock[x].getTRID_Articulo()<<endl;
				cout<<"NRO DE FACTURA: "<<vectorStock[x].getNroFactura()<<endl;
				cout<<"CATEGORIA: "<<vectorStock[x].getCategoria()<<endl;
				cout<<"MARCA: "<<vectorStock[x].getMarca()<<endl;
				cout<<"CANTIDAD VENDIDA: "<<vectorStock[x].getTRCantidad()<<endl;
				cout<<"PRECIO DE ARTICULO VENDIDO: "<<vectorStock[x].getTRprecioUnitario()<<endl;
				cout<<"CANTIDAD VALORIZADA: "<<vectorStock[x].getTRValorizada()<<endl;
			}
}
}


void CompraVista::ListarComprasxFactura(){
TransaxinventarioNegocio obj1;
char Invoice[30]{};
			cout<<"INGRESE LA FACTURA A BUSCAR: "<<endl;
			cin>>Invoice;
			cout<<endl;


TransaxInventario *vectorStock=obj1.Cargar_Vector_de_Compras(); // vector que contiene todo el file inventario

	  for(int x=0;x<obj1.CantidadDeTransax();x++){
			if(strcmp(Invoice,vectorStock[x].getNroFactura())==0 &&
				vectorStock[x].getStatus()==true){
				cout<<"CODIGO DE ARTICULO: "<<vectorStock[x].getTRID_Articulo()<<endl;
				cout<<"NRO DE FACTURA: "<<vectorStock[x].getNroFactura()<<endl;
				cout<<"CATEGORIA: "<<vectorStock[x].getCategoria()<<endl;
				cout<<"MARCA: "<<vectorStock[x].getMarca()<<endl;
				cout<<"CANTIDAD VENDIDA: "<<vectorStock[x].getTRCantidad()<<endl;
				cout<<"PRECIO DE ARTICULO VENDIDO: "<<vectorStock[x].getTRprecioUnitario()<<endl;
				cout<<"CANTIDAD VALORIZADA: "<<vectorStock[x].getTRValorizada()<<endl;
			}
}

}

void CompraVista::messageAnulacionOK(){
			cout<<"Factura Anulada"<<endl;

}

void CompraVista::messageAnulacionNotOK(){
			cout << "No existe la Factura ingresada "<<endl;

}

void CompraVista::messageReversoAnulacionOK(){
			cout<<"Se restauro la Factura anulada "<<endl;

}
