#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstring>
#include <cstdio>
#include<string.h>
#include"MenuPrincipal.h"
#include"ArticuloVista.h"
#include"ClienteVista.h"
#include"ProveedorVista.h"
#include"EmpleadoVista.h"
#include"CompraVista.h"
#include "VentaVista.h"
#include"TransaxinventarioVista.h"
#include"CompraNegocio.h"
#include"VentaNegocio.h"


using namespace std;


void MenuPrincipal::menuPrincipal()
{
    int opc;
    setlocale(LC_ALL,"Spanish");
    system("color 02");

    do
    {
        cout<<"MENU PRINCIPAL"<<endl<<endl;
        cout<<"1-GESTION DE MAESTROS"<<endl;
        cout<<"2-GESTION DE INVENTARIOS"<<endl;
        cout<<"3-GESTION DE COMPRAS"<<endl;
		cout<<"4-GESTION DE VENTAS"<<endl;
        cout<<"0-SALIR DEL PROGRAMA"<<endl<<endl;
        cout<<"Ingresar Opcion: ";
        cin>>opc;

        system("cls");
        switch(opc)
        {

		case 1:
		submenuMaestros();
		system("cls");
		break;

		case 2:
		submenuInventarios();
		system("cls");
		break;

		case 3:
		submenuCompras();
		system("cls");
		break;

		case 4:
		submenuVentas();
		system("cls");
		break;

        case 0:
		cout<<"-----FIN DEL PROGRAMA-----";
        break;

        default:
            break;

        }

    }
    while(opc!=0);

}

void MenuPrincipal::submenuMaestros()

{
    int opc;
    setlocale(LC_ALL,"Spanish");
    system("color 02");

    do
    {
		cout<<"MENU DE MAESTROS"<<endl<<endl;
        cout<<"1-MAESTRO DE EMPLEADOS"<<endl;
        cout<<"2-MAESTRO DE CLIENTES"<<endl;
		cout<<"3-MAESTRO DE PROVEEDORES"<<endl;
		cout<<"4-MAESTRO DE ARTICULOS"<<endl;
        cout<<"0-SALIR DEL PROGRAMA"<<endl<<endl;
        cout<<"Ingresar Opcion: ";
        cin>>opc;

        system("cls");
        switch(opc)
        {

		case 1:
           EmpleadoVista obj1;
           obj1.menuEmpleados();
           system("cls");
		break;

		case 2:
			ClienteVista obj2;
			obj2.menuClientes();
            system("cls");
		break;

		case 3:
			ProveedorVista obj3;
			obj3.menuProveedores();
			system("cls");
		break;

		case 4:
			ArticuloVista obj4;
			obj4.menuArticulos();

        case 0:
            cout<<"-----FIN DEL PROGRAMA-----";
            break;

        default:
            break;

        }

    }
    while(opc!=0);
}



void MenuPrincipal::submenuInventarios(){
    CompraVista obj1;
    VentaVista obj2;
    int opc;
    system("color 02");

    do
    {
		cout<<"MENU DE INVENTARIOS"<<endl<<endl;
		cout<<"1-LISTAR TODAS LAS TRANSACCIONES SOBRE EL STOCK COMPLETO"<<endl;
		cout<<"2-LISTAR TODAS LAS TRANSACCIONES SOBRE EL STOCK DE UNA CATEGORIA"<<endl;
		cout<<"3-LISTAR TODAS LAS TRANSACCIONES SOBRE EL STOCK DE UNA MARCA"<<endl;
		cout<<"4-LISTAR STOCK X PRODUCTO Y FECHA"<<endl;
        cout<<"0-SALIR DEL PROGRAMA"<<endl<<endl;
        cout<<"Ingresar Opcion: ";
        cin>>opc;

        system("cls");
        switch(opc)
        {

		case 1:

			TransaxinventarioVista obj3;
			obj3.MostrarInventario();
			system("pause");
			system("cls");
            break;

		case 2:

			obj3.MostrarInventarioxCategoria();
			system("pause");
			system("cls");
            break;

		case 3:

		obj3.MostrarInventarioxMarca();
			system("pause");
			system("cls");
            break;

		case 4:

			obj3.MostrarStockxFecha();
			system("pause");
			system("cls");

		break;


		break;

        case 0:
            cout<<"-----FIN DEL PROGRAMA-----";
            break;

        default:
            break;

        }

    }
    while(opc!=0);
}


void MenuPrincipal::submenuCompras(){
    CompraVista obj1;
    VentaVista obj2;
    int opc;
    system("color 02");

    do
    {
		cout<<"SUBMENU GESTION DE COMPRAS"<<endl<<endl;
        cout<<"1-CARGAR FACTURAS DE COMPRAS"<<endl;
        cout<<"2-LISTAR COMPRAS REALIZADAS"<<endl;
		cout<<"3-MODIFICAR FACTURAS DE COMPRAS"<<endl;
		cout<<"4-ANULAR FACTURAS DE COMPRAS"<<endl;
		cout<<"5-REVERSAR DE ANULACION DE FACTURAS DE COMPRAS"<<endl;
		cout<<"6-LISTAR COMPRAS X PRODUCTO Y FECHA"<<endl;
		cout<<"7-LISTAR COMPRAS X FACTURA"<<endl;
        cout<<"0-SALIR DEL PROGRAMA"<<endl<<endl;
        cout<<"Ingresar Opcion: ";
        cin>>opc;

        system("cls");
        switch(opc)
        {

		case 1:

           if(obj1.cargarCompras()==true) cout<<"　DATOS GUARDADOS CON EXITO!!"<<endl;
            else cout<<"　ERROR, NO SE PUDIERON GUARDAR LOS DATOS!!"<<endl;
			system("pause");
			system("cls");
		break;

		case 2:
			obj1.mostrarCompras();
            system("pause");
            system("cls");
		break;

		case 3:

			system("pause");
			system("cls");
		break;

		case 4:
			CompraNegocio obj4;
			char Invoice[15];

		cout<<"INGRESE LA FACTURA DE LA COMPRA A ANULAR:"; // La factura es el ID que no se repita
		cin>>Invoice;

			obj4.AnularCompra(Invoice);

			system("pause");
			system("cls");
            break;

 		case 5:
			CompraNegocio obj3;
			char Invoice2[15];

		cout<<"INGRESE LA FACTURA DE LA COMPRA QUE DESEA REVERAR LA ANULACION:"; // La factura es el ID que no se repita
		cin>>Invoice2;

			obj3.ReversarAnulacionCompra(Invoice2);

			system("pause");
			system("cls");
            break;


		case 6:
		obj1.MostrarComprasxFecha();
			system("pause");
			system("cls");
            break;

		case 7:
		obj1.ListarComprasxFactura();
			system("pause");
			system("cls");
            break;

        case 0:
            cout<<"-----FIN DEL PROGRAMA-----";
            break;

        default:
            break;

        }

    }
    while(opc!=0);
}


void MenuPrincipal::submenuVentas(){
    CompraVista obj1;
    VentaVista obj2;
    int opc;
    system("color 02");

    do
    {
		cout<<"SUBMENU GESTION DE VENTAS"<<endl<<endl;
        cout<<"1-CARGAR FACTURAS DE VENTAS"<<endl;
        cout<<"2-LISTAR VENTAS REALIZADAS"<<endl;
		cout<<"3-MODIFICAR FACTURAS DE VENTAS"<<endl;
		cout<<"4-ANULAR FACTURAS DE VENTAS"<<endl;
		cout<<"5-REVERSAR DE ANULACION DE FACTURAS DE COMPRAS"<<endl;
		cout<<"6-LISTAR VENTAS X PRODUCTO Y FECHA"<<endl;
		cout<<"7-LISTAR VENTAS X FACTURA"<<endl;
        cout<<"0-SALIR DEL PROGRAMA"<<endl<<endl;
        cout<<"Ingresar Opcion: ";
        cin>>opc;

        system("cls");
        switch(opc)
        {

		case 1:

           if(obj2.cargarVentas()==true) cout<<"　DATOS GUARDADOS CON EXITO!!"<<endl;
            else cout<<"　ERROR, NO SE PUDIERON GUARDAR LOS DATOS!!"<<endl;
			system("pause");
			system("cls");
		break;

		case 2:
			obj2.mostrarVentas();
            system("pause");
            system("cls");
		break;

		case 3:

			system("pause");
			system("cls");
		break;

		case 4:{
			VentaNegocio obj4;
			char Invoice[15];

		cout<<"INGRESE LA FACTURA DE LA COMPRA A ANULAR:"; // La factura es el ID que no se repita
		cin>>Invoice;

			obj4.AnularVenta(Invoice);

			system("pause");
			system("cls");
			}

            break;

 		case 5:{
			VentaNegocio obj3;
			char Invoice2[15];

		cout<<"INGRESE LA FACTURA DE LA COMPRA QUE DESEA REVESAR LA ANULACION:"; // La factura es el ID que no se repita
		cin>>Invoice2;

			obj3.ReversarAnulacionVenta(Invoice2);
			system("pause");
			system("cls");
 		}
            break;


		case 6:
			obj2.MostrarVtasxFecha();
			system("pause");
			system("cls");
            break;

		case 7:
			obj2.ListarVtasxFactura();
			system("pause");
			system("cls");
            break;


        case 0:
            cout<<"-----FIN DEL PROGRAMA-----";
            break;

        default:
            break;

        }

    }
    while(opc!=0);
}





