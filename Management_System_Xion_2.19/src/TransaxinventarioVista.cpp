#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include "TransaxinventarioVista.h"
#include "TransaxinventarioNegocio.h"
#include "Transaxinventario.h"

void TransaxinventarioVista::MostrarInventario(){

	TransaxinventarioNegocio negocio;
    TransaxInventario *vectorStock;

    vectorStock=negocio.Cargar_Vector_de_Stocks();
		cout<<"LISTAR TODAS LAS TRANSACCIONES DEL STOCK COMPLETO"<<endl;
		cout<<endl;
        for(int x;x<negocio.CantidadDeTransax();x++){
        cout<< "ID_Articulo: "<<vectorStock[x].getTRID_Articulo() <<endl;
		cout<< "ID_Articulo: "<<vectorStock[x].getNroFactura() <<endl;
		cout<< "Fecha de Stock: ";vectorStock[x].getFechaTransax().MostrarFecha();
		cout<< "Categoria: "<<vectorStock[x].getCategoria()<<endl;
		cout<< "Marca: "<<vectorStock[x].getMarca()<<endl;
        cout<< "Tipo de Transaccion: "<<vectorStock[x].getTipoTransax() <<endl;
        cout<< "Cantidad: "<<vectorStock[x].getTRCantidad() <<endl;
        cout<< "Precio Unitario: "<<vectorStock[x].getTRprecioUnitario() <<endl;
        cout<< "STOCK: "<<vectorStock[x].getStock() <<endl;
        cout<< "StockValorizado: "<<vectorStock[x].getStockValorizado() <<endl;
        cout<< "-------------------------"<<endl;}

    delete vectorStock;
}

void TransaxinventarioVista::MostrarStockxFecha(){

int dia, mes, anio;
char CODEART[20];
			cout<<"LISTADO DE STOCK X PRODUCTO Y FECHA"<<endl;
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
TransaxinventarioNegocio obj1;

obj1.MostrarStockxFecha(obj);
;
}

void TransaxinventarioVista::MostrarVtasxFecha(){

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
TransaxinventarioNegocio obj1;

obj1.MostrarVtasxFecha(obj);
}

void TransaxinventarioVista::MostrarInventarioxCategoria(){

	TransaxinventarioNegocio negocio;
    TransaxInventario *vectorStock;

    vectorStock=negocio.Cargar_Vector_de_Stocks();
		cout<<"LISTAR TODAS LAS TRANSACCIONES DEL STOCK COMPLETO"<<endl;
		cout<<endl;
        for(int x;x<negocio.CantidadDeTransax();x++){
        cout<< "ID_Articulo: "<<vectorStock[x].getTRID_Articulo() <<endl;
		cout<< "ID_Articulo: "<<vectorStock[x].getNroFactura() <<endl;
		cout<< "Fecha de Stock: ";vectorStock[x].getFechaTransax().MostrarFecha();
		cout<< "Categoria: "<<vectorStock[x].getCategoria()<<endl;
		cout<< "Marca: "<<vectorStock[x].getMarca()<<endl;
        cout<< "Tipo de Transaccion: "<<vectorStock[x].getTipoTransax() <<endl;
        cout<< "Cantidad: "<<vectorStock[x].getTRCantidad() <<endl;
        cout<< "Precio Unitario: "<<vectorStock[x].getTRprecioUnitario() <<endl;
        cout<< "STOCK: "<<vectorStock[x].getStock() <<endl;
        cout<< "StockValorizado: "<<vectorStock[x].getStockValorizado() <<endl;
        cout<< "-------------------------"<<endl;}

    delete vectorStock;
}
