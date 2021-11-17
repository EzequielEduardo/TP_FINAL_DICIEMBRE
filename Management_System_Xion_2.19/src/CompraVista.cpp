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
	CompraNegocio reg;
	CompraVista obj;
    cout<<"Datos de la fecha actual: "<<endl;
    cout<<"Dia: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Anio: ";
    cin>>anio;

    TransaxInventario compra(dia,mes,anio);

    cout<<"-----------------------------------"<<endl;

    cout << "Datos de la Compra:"<<endl;
    cout<<"Ingresar: "<<endl;

    cout<<"Nro de Factura de Compra: ";
        negocio.cargarCadena(cadena,20);
        compra.setNroFactura(cadena);

    cout<<"ID del Articulo: ";
        negocio.cargarCadena(cadena,20);

        if(reg.ValidacionDeArticulo(cadena)) {compra.setTRID_Articulo(cadena);}//VALIDACION ART
        else {obj.messageValidacionCompra();
				return 0;}

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

	compra.setTipoTransax(1);

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
        cout<< "ID del Articulo: "<<vectorCompras[x].getTRID_Articulo() <<endl;
		cout<< "Nro de Factura de Compra: "<<vectorCompras[x].getNroFactura() <<endl;
        cout<< "Categoria: "<<vectorCompras[x].getCategoria() <<endl;
        cout<< "Marca: "<<vectorCompras[x].getMarca() <<endl;
		cout<< "Fecha de Compra: ";vectorCompras[x].getFechaTransax().MostrarFecha();
        cout<< "Cantidad: "<<vectorCompras[x].getTRCantidad() <<endl;
        cout<< "Costo Unitario: "<<vectorCompras[x].getTRprecioUnitario() <<endl;
        cout<< "Cantidad Valorizada: "<<vectorCompras[x].getTRValorizada() <<endl;
        cout<< "-----------------------------"<<endl;
        }
        else{
			cout<<"-FACTURA ANULADA-"<<endl;
        cout<< "ID del Articulo: "<<vectorCompras[x].getTRID_Articulo() <<endl;
		cout<< "Nro de Factura de Compra: "<<vectorCompras[x].getNroFactura() <<endl;
        cout<< "Categoria: "<<vectorCompras[x].getCategoria() <<endl;
        cout<< "Marca: "<<vectorCompras[x].getMarca() <<endl;
		cout<< "Fecha de Compra: ";vectorCompras[x].getFechaTransax().MostrarFecha();
        cout<< "Cantidad: "<<vectorCompras[x].getTRCantidad() <<endl;
        cout<< "Costo Unitario: "<<vectorCompras[x].getTRprecioUnitario() <<endl;
        cout<< "Cantidad Valorizada: "<<vectorCompras[x].getTRValorizada() <<endl;
        cout<< "-----------------------------"<<endl;
        }
        }
    delete vectorCompras;

}


void CompraVista::MostrarComprasxFecha(){
TransaxinventarioNegocio obj1;
int dia, mes, anio;
char CODEART[20];
			cout<<"LISTADO DE COMPRAS X PRODUCTO Y FECHA"<<endl;
			cout<<endl;
			cout<<"Ingrese la Fecha de la Compra: "<<endl;
				cout<<"Dia: ";
				cin>>dia;
				cout<<"Mes: ";
				cin>>mes;
				cout<<"Anio: ";
				cin>>anio;

			TransaxInventario obj(dia,mes,anio);

			cout<<"Ingrese el ID del Articulo: "<<endl;
			obj1.cargarCadena(CODEART,20);
			cout<<endl;
			obj.setTRID_Articulo(CODEART);


TransaxInventario *vectorCompras=obj1.Cargar_Vector_de_Compras(); // vector que contiene todo el file inventario

	  for(int x=0;x<obj1.CantidadDeTransax();x++){
			if(obj.getFechaTransax()==vectorCompras[x].getFechaTransax() &&
				strcmp(obj.getTRID_Articulo(),vectorCompras[x].getTRID_Articulo())==0 &&
				vectorCompras[x].getStatus()==true){
				cout<<"ID del Articulo: "<<vectorCompras[x].getTRID_Articulo()<<endl;
				cout<<"Nro de Factura de Compra: "<<vectorCompras[x].getNroFactura()<<endl;
				cout<<"Categoria: "<<vectorCompras[x].getCategoria()<<endl;
				cout<<"Marca: "<<vectorCompras[x].getMarca()<<endl;
				cout<<"Cantidad Comprada: "<<vectorCompras[x].getTRCantidad()<<endl;
				cout<<"Precio de Compra del Articulo: "<<vectorCompras[x].getTRprecioUnitario()<<endl;
				cout<<"Cantidad Valorizada: "<<vectorCompras[x].getTRValorizada()<<endl;
				cout<< "-----------------------------"<<endl;
			}
			if(obj.getFechaTransax()==vectorCompras[x].getFechaTransax() &&
				strcmp(obj.getTRID_Articulo(),vectorCompras[x].getTRID_Articulo())==0 &&
				vectorCompras[x].getStatus()==false){
				cout<<"-FACTURA ANULADA-"<<endl;
				cout<<"ID del Articulo: "<<vectorCompras[x].getTRID_Articulo()<<endl;
				cout<<"Nro de Factura de Compra: "<<vectorCompras[x].getNroFactura()<<endl;
				cout<<"Categoria: "<<vectorCompras[x].getCategoria()<<endl;
				cout<<"Marca: "<<vectorCompras[x].getMarca()<<endl;
				cout<<"Cantidad Comprada: "<<vectorCompras[x].getTRCantidad()<<endl;
				cout<<"Precio de Compra del Articulo: "<<vectorCompras[x].getTRprecioUnitario()<<endl;
				cout<<"Cantidad Valorizada: "<<vectorCompras[x].getTRValorizada()<<endl;
				cout<< "-----------------------------"<<endl;
			}
}
}


void CompraVista::ListarComprasxFactura(){
TransaxinventarioNegocio obj1;
char Invoice[30]{};
			cout<<"Ingrese el Nro de la Factura a Buscar: "<<endl;
			cin>>Invoice;
			cout<<endl;


TransaxInventario *vectorCompra=obj1.Cargar_Vector_de_Compras(); // vector que contiene todo el file inventario

	  for(int x=0;x<obj1.CantidadDeTransax();x++){
			if(strcmp(Invoice,vectorCompra[x].getNroFactura())==0 &&
				vectorCompra[x].getStatus()==true){
				cout<<"ID del Articulo: "<<vectorCompra[x].getTRID_Articulo()<<endl;
				cout<<"Nro de Factura de Compra: "<<vectorCompra[x].getNroFactura()<<endl;
				cout<<"Categoria: "<<vectorCompra[x].getCategoria()<<endl;
				cout<<"Marca: "<<vectorCompra[x].getMarca()<<endl;
				cout<<"Cantidad Vendida: "<<vectorCompra[x].getTRCantidad()<<endl;
				cout<<"Precio de Articulo Comprado: "<<vectorCompra[x].getTRprecioUnitario()<<endl;
				cout<<"Cantidad Valorizada: "<<vectorCompra[x].getTRValorizada()<<endl;
				cout<< "-----------------------------"<<endl;
			}
			if(strcmp(Invoice,vectorCompra[x].getNroFactura())==0 &&
				vectorCompra[x].getStatus()==false){
				cout<<"-FACTURA ANULADA-"<<endl;
				cout<<"ID del Articulo: "<<vectorCompra[x].getTRID_Articulo()<<endl;
				cout<<"Nro de Factura de Compra: "<<vectorCompra[x].getNroFactura()<<endl;
				cout<<"Categoria: "<<vectorCompra[x].getCategoria()<<endl;
				cout<<"Marca: "<<vectorCompra[x].getMarca()<<endl;
				cout<<"Cantidad Vendida: "<<vectorCompra[x].getTRCantidad()<<endl;
				cout<<"Precio de Articulo Comprado: "<<vectorCompra[x].getTRprecioUnitario()<<endl;
				cout<<"Cantidad Valorizada: "<<vectorCompra[x].getTRValorizada()<<endl;
				cout<< "-----------------------------"<<endl;
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

int CompraVista::PideNewQFacturaCompras(){
	int Q;
	cout<<"Ingrese la nueva cantidad "<<endl;
	cin>>Q;
	return Q;
}

void CompraVista::messageFacturaModifOK(){
			cout<<"Se Modifico la Factura Correctamente "<<endl;

}

void CompraVista::messageValidacionCompra(){
			 cout<<"Ingrese un Articulo Valido (Cargar previamente en Maestro de Articulos) "<<endl;
			system("pause");
}
