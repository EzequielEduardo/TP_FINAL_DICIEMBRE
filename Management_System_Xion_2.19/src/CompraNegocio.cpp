#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstring>
#include <cstdio>
#include<string.h>
#include "TransaxinventarioNegocio.h"
#include "TransaxinventarioFile.h"
#include "Transaxinventario.h"
#include "CompraNegocio.h"
#include "CompraFile.h"
#include"CompraVista.h"
#include"ArticuloNegocio.h"
using namespace std;

bool CompraNegocio::guardarDatos(TransaxInventario articulo)
{
    CompraFile archivo;
    return archivo.grabarEnDisco(articulo);
}

TransaxInventario* CompraNegocio::Cargar_Vector_de_Compras()
{
    TransaxInventario *vectorCompras;
    CompraFile archivo;
    vectorCompras=archivo.obtener_Datos_Compras();

return vectorCompras;
}


int CompraNegocio::CantidadDeCompras()
{

    CompraFile archivo;

    return archivo.cantidadDeDatosGrabados();

}

void CompraNegocio::cargarCadena(char *pal, int tam){
			int i;
			fflush(stdin);
			for(i=0;i<tam;i++){
				pal[i]=cin.get();
				if(pal[i]=='\n') break;
				}
				pal[i]='\0';
				fflush(stdin);
				}

int CompraNegocio::buscarPosicionInvoice(const char *invoice){
    TransaxInventario reg;
    CompraFile obj;
    int pos = 0;
    while(obj.leerCompra(reg, pos)){ // Mandar a vista file
        if (strcmp(invoice, reg.getNroFactura()) == 0){
            return pos;
        }
        pos++;
    }
    return -1;
}

void CompraNegocio::AnularCompra(const char * invoice){
	CompraFile reg;
	TransaxInventario obj;
	TransaxinventarioNegocio stock;
	CompraVista obj2;
	int pos = buscarPosicionInvoice(invoice);
	if (pos >= 0){ 		//porque lo encuentra

			reg.leerCompra(obj,pos);
			obj.setStatus(false); //camio el estado para que no lo muestre. Baja logica
			obj.setTRCantidad(obj.getTRCantidad()*-1);
			obj2.messageAnulacionOK();
			reg.grabarEnDisco(obj,pos);//tengo que poner la posicion
			stock.actualizarstock(1,obj);

		}
	 else{
				obj2.messageAnulacionNotOK();

    }
    cout << endl << endl;


}



void CompraNegocio::ReversarAnulacionCompra(const char * invoice){
	CompraFile reg;
	TransaxInventario obj;
	CompraVista obj2;
	TransaxinventarioNegocio stock;
	int pos = buscarPosicionInvoice(invoice);
	if (pos >= 0){ 		//porque lo encuentra

			reg.leerCompra(obj,pos);
			obj.setStatus(true); //camio el estado para que no lo muestre. Baja logica
			obj.setTRCantidad(obj.getTRCantidad()*-1);
			obj2.messageReversoAnulacionOK();
			reg.grabarEnDisco(obj,pos);//tengo que poner la posicion
			stock.actualizarstock(1,obj);
		}
	 else{
				obj2.messageAnulacionNotOK();

    }
    cout << endl << endl;

}


void CompraNegocio::ModifQenFacturaDeCompras(const char * invoice){
	CompraFile reg;
	TransaxInventario obj;
	TransaxinventarioNegocio stock;
	CompraVista obj2;
	int pos = buscarPosicionInvoice(invoice);
	if (pos >= 0){ 		//porque lo encuentra

			reg.leerCompra(obj,pos);
			int NewQ = obj2.PideNewQFacturaCompras();
			obj.setTRCantidad(NewQ);
			obj2.messageFacturaModifOK();
			reg.grabarEnDisco(obj,pos);//tengo que poner la posicion
			stock.actualizarstock(1,obj);
		}
	 else{
				obj2.messageAnulacionNotOK();

    }
    cout << endl << endl;
}


	bool CompraNegocio::ValidacionDeArticulo(const char * id){
	ArticuloNegocio obj;
	if(obj.buscarPosicion(id)>=0) return 1;
	else return 0;


	}


