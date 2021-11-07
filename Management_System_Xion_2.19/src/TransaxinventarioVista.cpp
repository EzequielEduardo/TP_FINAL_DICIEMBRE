#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include "TransaxinventarioVista.h"
#include "TransaxinventarioNegocio.h"
#include "Transaxinventario.h"
#include<iomanip>
void TransaxinventarioVista::MostrarInventario(){

	TransaxinventarioNegocio negocio;
    TransaxInventario *vectorStock;

    vectorStock=negocio.Cargar_Vector_de_Stocks();
		cout<<"LISTAR TODAS LAS TRANSACCIONES DEL STOCK COMPLETO"<<endl;
		cout<<endl;
        for(int x;x<negocio.CantidadDeTransax();x++){
		if(vectorStock[x].getStatus()==true){
        cout<< "ID del Articulo: "<<vectorStock[x].getTRID_Articulo() <<endl;
		cout<< "Nro de Factura: "<<vectorStock[x].getNroFactura() <<endl;
		cout<< "Fecha de Stock: ";vectorStock[x].getFechaTransax().MostrarFecha();
		cout<< "Categoria: "<<vectorStock[x].getCategoria()<<endl;
		cout<< "Marca: "<<vectorStock[x].getMarca()<<endl;
        cout<< "Tipo de Transaccion: "<<vectorStock[x].getTipoTransax() <<endl;
        cout<< "Cantidad: "<<vectorStock[x].getTRCantidad() <<endl;
        cout<< "Precio Unitario: "<<vectorStock[x].getTRprecioUnitario() <<endl;
        cout<< "Stock: "<<vectorStock[x].getStock() <<endl;
        cout<< "Stock Valorizado: "<<vectorStock[x].getStockValorizado()<<endl;
        cout<< "-------------------------------------------------"<<endl;
        }
        else{
		cout<< "-FACTURA ANULADA-"<<endl;
		cout<< "ID del Articulo: "<<vectorStock[x].getTRID_Articulo() <<endl;
		cout<< "Nro de Factura: "<<vectorStock[x].getNroFactura() <<endl;
		cout<< "Fecha de Stock: ";vectorStock[x].getFechaTransax().MostrarFecha();
		cout<< "Categoria: "<<vectorStock[x].getCategoria()<<endl;
		cout<< "Marca: "<<vectorStock[x].getMarca()<<endl;
        cout<< "Tipo de Transaccion: "<<vectorStock[x].getTipoTransax() <<endl;
        cout<< "Cantidad: "<<vectorStock[x].getTRCantidad() <<endl;
        cout<< "Precio Unitario: "<<vectorStock[x].getTRprecioUnitario() <<endl;
        cout<< "Stock: "<<vectorStock[x].getStock() <<endl;
        cout<< "Stock Valorizado: "<<vectorStock[x].getStockValorizado() <<endl;
        cout<< "-------------------------------------------------"<<endl;
        }
        }


    delete vectorStock;
}

void TransaxinventarioVista::MostrarStockxFecha(){
TransaxinventarioNegocio obj1;
int dia, mes, anio;
char CODEART[20];
			cout<<"LISTADO DE STOCK X PRODUCTO Y FECHA"<<endl;
			cout<<endl;

			cout<<"Ingrese la Fecha de Stock: "<<endl;
				cout<<"Dia: ";
				cin>>dia;
				cout<<"Mes: ";
				cin>>mes;
				cout<<"Anio: ";
				cin>>anio;

			TransaxInventario obj(dia,mes,anio);

			cout<<"Ingrese el ID del Articulo: "<<endl;
			cin>>CODEART;
			cout<<endl;
			obj.setTRID_Articulo(CODEART);


TransaxInventario *vectorStock=obj1.Cargar_Vector_de_Stocks(); // vector que contiene todo el file inventario

	  for(int x=0;x<obj1.CantidadDeTransax();x++){
			if(obj.getFechaTransax()==vectorStock[x].getFechaTransax() &&
				strcmp(obj.getTRID_Articulo(),vectorStock[x].getTRID_Articulo())==0
				&& vectorStock[x].getStatus()==true){
				cout<<"ID del Articulo: "<<vectorStock[x].getTRID_Articulo()<<endl;
				cout<<"Nro de la Factura: "<<vectorStock[x].getNroFactura()<<endl;
				cout<<"Categoria: "<<vectorStock[x].getCategoria()<<endl;
				cout<<"Marca: "<<vectorStock[x].getMarca()<<endl;
				cout<<"Stock: "<<vectorStock[x].getStock()<<endl;
				cout<<"Stock Valorizado: "<<vectorStock[x].getStockValorizado()<<endl;
				cout<< "-------------------------------------------------"<<endl;
			}
					if(obj.getFechaTransax()==vectorStock[x].getFechaTransax() &&
				strcmp(obj.getTRID_Articulo(),vectorStock[x].getTRID_Articulo())==0
				&& vectorStock[x].getStatus()==false){
				cout<<"-FACTURA ANULADA-"<<endl;
				cout<<"ID del Articulo: "<<vectorStock[x].getTRID_Articulo()<<endl;
				cout<<"Nro de la Factura: "<<vectorStock[x].getNroFactura()<<endl;
				cout<<"Categoria: "<<vectorStock[x].getCategoria()<<endl;
				cout<<"Marca: "<<vectorStock[x].getMarca()<<endl;
				cout<<"Stock: "<<vectorStock[x].getStock()<<endl;
				cout<<"Stock Valorizado: "<<vectorStock[x].getStockValorizado()<<endl;
				cout<< "-------------------------------------------------"<<endl;
			}
}

}



void TransaxinventarioVista::MostrarInventarioxCategoria(){

	TransaxinventarioNegocio negocio;
    TransaxInventario *vectorStock;
	char categ[20]{};
    vectorStock=negocio.Cargar_Vector_de_Stocks();
		cout<<"LISTAR TODAS LAS TRANSACCIONES SOBRE EL STOCK DE UNA CATEGORIA"<<endl;
		cout<<endl;
		cout<<"Ingrese la categoria que busca: "<<endl;
		negocio.cargarCadena(categ,20);

        for(int x;x<negocio.CantidadDeTransax();x++){
		if(strcmp(categ,vectorStock[x].getCategoria())==0 && vectorStock[x].getStatus()==true){
        cout<< "ID del Articulo: "<<vectorStock[x].getTRID_Articulo() <<endl;
		cout<< "Nro de Factura: "<<vectorStock[x].getNroFactura() <<endl;
		cout<< "Fecha de Stock: ";vectorStock[x].getFechaTransax().MostrarFecha();
		cout<< "Categoria: "<<vectorStock[x].getCategoria()<<endl;
		cout<< "Marca: "<<vectorStock[x].getMarca()<<endl;
        cout<< "Tipo de Transaccion: "<<vectorStock[x].getTipoTransax() <<endl;
        cout<< "Cantidad: "<<vectorStock[x].getTRCantidad() <<endl;
        cout<< "Precio Unitario: "<<vectorStock[x].getTRprecioUnitario() <<endl;
        cout<< "Stock: "<<vectorStock[x].getStock() <<endl;
        cout<< "Stock Valorizado: "<<vectorStock[x].getStockValorizado() <<endl;
        cout<< "---------------------------------------------------------"<<endl;}

        if(strcmp(categ,vectorStock[x].getCategoria())==0 && vectorStock[x].getStatus()==false){
		cout<<"-FACTURA ANULADA-"<<endl;
        cout<< "ID del Articulo: "<<vectorStock[x].getTRID_Articulo() <<endl;
		cout<< "Nro de Factura: "<<vectorStock[x].getNroFactura() <<endl;
		cout<< "Fecha de Stock: ";vectorStock[x].getFechaTransax().MostrarFecha();
		cout<< "Categoria: "<<vectorStock[x].getCategoria()<<endl;
		cout<< "Marca: "<<vectorStock[x].getMarca()<<endl;
        cout<< "Tipo de Transaccion: "<<vectorStock[x].getTipoTransax() <<endl;
        cout<< "Cantidad: "<<vectorStock[x].getTRCantidad() <<endl;
        cout<< "Precio Unitario: "<<vectorStock[x].getTRprecioUnitario() <<endl;
        cout<< "Stock: "<<vectorStock[x].getStock() <<endl;
        cout<< "Stock Valorizado: "<<vectorStock[x].getStockValorizado() <<endl;
        cout<< "--------------------------------------------------------"<<endl;}
        }

    delete vectorStock;
}

void TransaxinventarioVista::MostrarInventarioxMarca(){

	TransaxinventarioNegocio negocio;
    TransaxInventario *vectorStock;
	char brand[20]{};
    vectorStock=negocio.Cargar_Vector_de_Stocks();
		cout<<"LISTAR TODAS LAS TRANSACCIONES SOBRE EL STOCK DE UNA MARCA"<<endl;
		cout<<endl;
		cout<<"Ingrese la categoria que busca: "<<endl;
		negocio.cargarCadena(brand,20);

        for(int x;x<negocio.CantidadDeTransax();x++){
		if(strcmp(brand,vectorStock[x].getMarca())==0 && vectorStock[x].getStatus()==true){
        cout<< "ID del Articulo: "<<vectorStock[x].getTRID_Articulo() <<endl;
		cout<< "Nro de Factura: "<<vectorStock[x].getNroFactura() <<endl;
		cout<< "Fecha de Stock: ";vectorStock[x].getFechaTransax().MostrarFecha();
		cout<< "Categoria: "<<vectorStock[x].getCategoria()<<endl;
		cout<< "Marca: "<<vectorStock[x].getMarca()<<endl;
        cout<< "Tipo de Transaccion: "<<vectorStock[x].getTipoTransax() <<endl;
        cout<< "Cantidad: "<<vectorStock[x].getTRCantidad() <<endl;
        cout<< "Precio Unitario: "<<vectorStock[x].getTRprecioUnitario() <<endl;
        cout<< "Stock: "<<vectorStock[x].getStock() <<endl;
        cout<< "Stock Valorizado: "<<vectorStock[x].getStockValorizado() <<endl;
        cout<< "---------------------------------------------------------"<<endl;
        }
        if(strcmp(brand,vectorStock[x].getMarca())==0 && vectorStock[x].getStatus()==false){
		cout<<"-FACTURA ANULADA-"<<endl;
        cout<< "ID del Articulo: "<<vectorStock[x].getTRID_Articulo() <<endl;
		cout<< "Nro de Factura: "<<vectorStock[x].getNroFactura() <<endl;
		cout<< "Fecha de Stock: ";vectorStock[x].getFechaTransax().MostrarFecha();
		cout<< "Categoria: "<<vectorStock[x].getCategoria()<<endl;
		cout<< "Marca: "<<vectorStock[x].getMarca()<<endl;
        cout<< "Tipo de Transaccion: "<<vectorStock[x].getTipoTransax() <<endl;
        cout<< "Cantidad: "<<vectorStock[x].getTRCantidad() <<endl;
        cout<< "Precio Unitario: "<<vectorStock[x].getTRprecioUnitario() <<endl;
        cout<< "Stock: "<<vectorStock[x].getStock() <<endl;
        cout<< "Stock Valorizado: "<<vectorStock[x].getStockValorizado() <<endl;
        cout<< "-------------------------------------------------"<<endl;
        }
        }

    delete vectorStock;
}
