#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstring>
#include <cstdio>
#include<string.h>
#include<iomanip>
#include "CompraVista.h"
#include "TransaxinventarioNegocio.h"
#include "Transaxinventario.h"
#include "VentaNegocio.h"
#include "VentaVista.h"

using namespace std;

void VentaVista::menuVentas()
{
    int opc;
    setlocale(LC_ALL,"Spanish");
    system("color 02");

    do
    {
        cout<<"MENU VENTAS"<<endl<<endl;
        cout<<"1-CARGAR VENTAS"<<endl;
        cout<<"0-VOLVER AL MENU ANTERIOR"<<endl<<endl;
        cout<<"Ingresar Opcion: ";
        cin>>opc;

        system("cls");
        switch(opc)
        {

        case 1:

            if(cargarVentas()==true) cout<<"¡¡DATOS GUARDADOS CON EXITO!!"<<endl;
            else cout<<"¡¡ERROR, NO SE PUDIERON GUARDAR LOS DATOS!!"<<endl;

            system("pause");
            system("cls");
            break;

        case 0:

		break;

        default:
            break;

        }

    }
    while(opc!=0);


}


bool VentaVista::cargarVentas()
{
    CompraVista obj;
    TransaxinventarioNegocio negocio;
    char cadena[20];
    int entero,dia,mes,anio;;
    float decimal;
    VentaNegocio reg;

    cout<<"Datos de la fecha actual: "<<endl;
    cout<<"Dia: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Anio: ";
    cin>>anio;

    TransaxInventario venta(dia,mes,anio);

    cout<<"------------------------------"<<endl;

    cout << "Datos de la Venta:"<<endl;
    cout<<"Ingresar: "<<endl;

    cout<<"ID del Articulo: ";
    negocio.cargarCadena(cadena,20);
    if(reg.ValidacionDeArticulo(cadena)) {venta.setTRID_Articulo(cadena);}
        else {obj.messageValidacionCompra(reg.ValidacionDeArticulo(cadena));
				return 0;}

    cout<<"Factura de Venta: ";
    negocio.cargarCadena(cadena,20);
    venta.setNroFactura(cadena);

	cout<<"Categoria: ";
    negocio.cargarCadena(cadena,20);
    venta.setCategoria(cadena);

    cout<<"Marca: ";
    negocio.cargarCadena(cadena,20);
    venta.setMarca(cadena);

    cout<<"Cantidad:";
    cin>>entero;
    venta.setTRCantidad(entero);

    cout<<"Precio Unitario: ";
    cin>>decimal;
    venta.setTRprecioUnitario(decimal);

	venta.setStatus(true);

    negocio.actualizarstock(0,venta);

    return negocio.guardarDatosVenta(venta);
}


bool VentaVista::mostrarVentas(){

	TransaxinventarioNegocio negocio;
    TransaxInventario *vectorVentas;

    vectorVentas=negocio.Cargar_Vector_de_Ventas();///get ventas
		cout<< "LISTADO DE VENTAS REALIZADAS"<<endl;
		cout<<endl;
        for(int x;x<negocio.CantidadDeVentas();x++){
		if(vectorVentas[x].getStatus()==true){
        cout<< "ID del Articulo: "<<vectorVentas[x].getTRID_Articulo() <<endl;
        cout<< "Nro de Factura de Venta: "<<vectorVentas[x].getNroFactura() <<endl;
        cout<< "Categoria: "<<vectorVentas[x].getCategoria() <<endl;
		cout<< "Marca: "<<vectorVentas[x].getMarca() <<endl;
		cout<< "Fecha de venta: ";vectorVentas[x].getFechaTransax().MostrarFecha();
        cout<< "Cantidad: "<<vectorVentas[x].getTRCantidad() <<endl;
        cout<< "Precio Unitario: "<<vectorVentas[x].getTRprecioUnitario() <<endl;
        cout<< "Cantidad Valorizada: "<<vectorVentas[x].getTRValorizada() <<endl;
        cout<<"------------------------------"<<endl;
		}
		else{
		cout<< "-FACTURA ANULADA-"<<endl;
		cout<< "ID del Articulo: "<<vectorVentas[x].getTRID_Articulo() <<endl;
        cout<< "Nro de Factura de Venta: "<<vectorVentas[x].getNroFactura() <<endl;
        cout<< "Categoria: "<<vectorVentas[x].getCategoria() <<endl;
		cout<< "Marca: "<<vectorVentas[x].getMarca() <<endl;
		cout<< "Fecha de venta: ";vectorVentas[x].getFechaTransax().MostrarFecha();
        cout<< "Cantidad: "<<vectorVentas[x].getTRCantidad() <<endl;
        cout<< "Precio Unitario: "<<vectorVentas[x].getTRprecioUnitario() <<endl;
        cout<< "Cantidad Valorizada: "<<vectorVentas[x].getTRValorizada() <<endl;
        cout<<"------------------------------"<<endl;


		}
        //cout<<"status"<<vectorVentas[x].getStatus()<<endl;
        }

    delete vectorVentas;

}


void VentaVista::MostrarVtasxFecha(){
TransaxinventarioNegocio obj1;
int dia, mes, anio;
char CODEART[20];
			cout<<"LISTADO DE VENTAS X PRODUCTO Y FECHA"<<endl;
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
			obj1.cargarCadena(CODEART,20);
			cout<<endl;
			obj.setTRID_Articulo(CODEART);


TransaxInventario *vectorVentas=obj1.Cargar_Vector_de_Ventas(); // vector que contiene todo el file inventario

	  for(int x=0;x<obj1.CantidadDeTransax();x++){
			if(obj.getFechaTransax()==vectorVentas[x].getFechaTransax() &&
				strcmp(obj.getTRID_Articulo(),vectorVentas[x].getTRID_Articulo())==0 && vectorVentas[x].getStatus()==true){
				cout<<"ID del Articulo: "<<vectorVentas[x].getTRID_Articulo()<<endl;
				cout<<"Nro de Factura de Venta: "<<vectorVentas[x].getNroFactura()<<endl;
				cout<<"Categoria: "<<vectorVentas[x].getCategoria()<<endl;
				cout<<"Marca: "<<vectorVentas[x].getMarca()<<endl;
				cout<<"Cantidad Vendida: "<<vectorVentas[x].getTRCantidad()<<endl;
				cout<<"Precio del Articulo Vendido: "<<vectorVentas[x].getTRprecioUnitario()<<endl;
				cout<<"Cantidad Valorizada: "<<vectorVentas[x].getTRValorizada()<<endl;
				cout<<"------------------------------"<<endl;
			}

		if(obj.getFechaTransax()==vectorVentas[x].getFechaTransax() &&
				strcmp(obj.getTRID_Articulo(),vectorVentas[x].getTRID_Articulo())==0 && vectorVentas[x].getStatus()==false){

				cout<<"-FACTURA ANULADA- "<<endl;
				cout<<"ID del Articulo: "<<vectorVentas[x].getTRID_Articulo()<<endl;
				cout<<"Nro de Factura de Venta: "<<vectorVentas[x].getNroFactura()<<endl;
				cout<<"Categoria: "<<vectorVentas[x].getCategoria()<<endl;
				cout<<"Marca: "<<vectorVentas[x].getMarca()<<endl;
				cout<<"Cantidad Vendida: "<<vectorVentas[x].getTRCantidad()<<endl;
				cout<<"Precio del Articulo Vendido: "<<vectorVentas[x].getTRprecioUnitario()<<endl;
				cout<<"Cantidad Valorizada: "<<vectorVentas[x].getTRValorizada()<<endl;
				cout<<"------------------------------"<<endl;
			}

}

}

void VentaVista::ListarVtasxFactura(){
TransaxinventarioNegocio obj1;
char Invoice[30]{};
			cout<<"Ingrese el Nro de la Factura a Buscar: "<<endl;
			cin>>Invoice;
			cout<<endl;

TransaxInventario *vectorVentas=obj1.Cargar_Vector_de_Ventas(); // vector que contiene todo el file inventario

	  for(int x=0;x<obj1.CantidadDeTransax();x++){
			if(strcmp(Invoice,vectorVentas[x].getNroFactura())==0 && vectorVentas[x].getStatus()==true){
				cout<<"ID del Articulo: "<<vectorVentas[x].getTRID_Articulo()<<endl;
				cout<<"Nro de Factura de Venta: "<<vectorVentas[x].getNroFactura()<<endl;
				cout<<"Categoria: "<<vectorVentas[x].getCategoria()<<endl;
				cout<<"Marca: "<<vectorVentas[x].getMarca()<<endl;
				cout<<"Cantidad Vendida: "<<vectorVentas[x].getTRCantidad()<<endl;
				cout<<"Precio del Articulo Vendido: "<<vectorVentas[x].getTRprecioUnitario()<<endl;
				cout<<"Cantidad Valorizada: "<<vectorVentas[x].getTRValorizada()<<endl;
				cout<<"------------------------------"<<endl;
			}

			if(strcmp(Invoice,vectorVentas[x].getNroFactura())==0 && vectorVentas[x].getStatus()==false){
				cout<<"-FACTURA ANULADA-"<<endl;
				cout<<"ID del Articulo: "<<vectorVentas[x].getTRID_Articulo()<<endl;
				cout<<"Nro de Factura de Venta: "<<vectorVentas[x].getNroFactura()<<endl;
				cout<<"Categoria: "<<vectorVentas[x].getCategoria()<<endl;
				cout<<"Marca: "<<vectorVentas[x].getMarca()<<endl;
				cout<<"Cantidad Vendida: "<<vectorVentas[x].getTRCantidad()<<endl;
				cout<<"Precio del Articulo Vendido: "<<vectorVentas[x].getTRprecioUnitario()<<endl;
				cout<<"Cantidad Valorizada: "<<setprecision(4)<<vectorVentas[x].getTRValorizada()<<endl;
				cout<<"------------------------------"<<endl;
			}
}

}


void VentaVista::messageAnulacionOK(){
			cout<<"Factura Anulada"<<endl;

}

void VentaVista::messageAnulacionNotOK(){
			cout << "No existe la Factura ingresada "<<endl;

}

void VentaVista::messageReversoAnulacionOK(){
			cout<<"Se restauro la Factura anulada "<<endl;

}

int VentaVista::PideNewQFacturaVtas(){
	int Q;
	cout<<"Ingrese la nueva cantidad "<<endl;
	cin>>Q;
	return Q;
}

void VentaVista::messageFacturaModifOK(){
			cout<<"Se Modifico la Factura Correctamente "<<endl;

}
