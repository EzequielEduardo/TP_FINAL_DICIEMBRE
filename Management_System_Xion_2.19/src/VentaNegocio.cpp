#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstring>
#include <cstdio>
#include<string.h>

#include "Articulo.h"
#include "VentaNegocio.h"
#include "VentaFile.h"
#include"Transaxinventario.h"
#include"VentaVista.h"
#include "TransaxinventarioNegocio.h"

using namespace std;

bool VentaNegocio::guardarDatos(TransaxInventario articulo)
{
    VentaFile archivo;
    return archivo.grabarEnDisco(articulo);
}

void VentaNegocio::cargarCadena(char *pal, int tam){
			int i;
			fflush(stdin);
			for(i=0;i<tam;i++){
				pal[i]=cin.get();
				if(pal[i]=='\n') break;
				}
				pal[i]='\0';
				fflush(stdin);
				}

int VentaNegocio::buscarPosicion(const char *id){
    TransaxInventario reg;
    VentaFile obj;
    int pos = 0;
    while(obj.leerVenta(reg, pos)){ // Mandar a vista file
        if (strcmp(id, reg.getNroFactura()) == 0){
            return pos;
        }
        pos++;
    }
    return -1;
}

void VentaNegocio::AnularVenta(const char * id){
	VentaFile reg;
	TransaxInventario obj;
	TransaxinventarioNegocio stock;
	VentaVista obj2;
	int pos = buscarPosicion(id);
	if (pos >= 0){ 		//porque lo encuentra

			reg.leerVenta(obj,pos);
			obj.setStatus(false); //camio el estado para que no lo muestre. Baja logica
			obj.setTRCantidad(obj.getTRCantidad()*-1);
			obj2.messageAnulacionOK();
			reg.grabarEnDisco(obj,pos);//tengo que poner la posicion
			stock.actualizarstock(0,obj);
		}
	 else{
				obj2.messageAnulacionNotOK();

    }
    cout << endl << endl;


}


void VentaNegocio::ReversarAnulacionVenta(const char * id){
	VentaFile reg;
	TransaxInventario obj;
	TransaxinventarioNegocio stock;
	VentaVista obj2;
	int pos = buscarPosicion(id);
	if (pos >= 0){ 		//porque lo encuentra

			reg.leerVenta(obj,pos);
			obj.setStatus(true); //camio el estado para que no lo muestre. Baja logica
			obj.setTRCantidad(obj.getTRCantidad()*-1);
			obj2.messageReversoAnulacionOK();
			reg.grabarEnDisco(obj,pos);//tengo que poner la posicion
			stock.actualizarstock(0,obj);
		}
	 else{
				obj2.messageAnulacionNotOK();

    }
    cout << endl << endl;

}

