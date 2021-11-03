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



int CompraNegocio::buscarPosicion(const char *id){
    TransaxInventario reg;
    CompraFile obj;
    int pos = 0;
    while(obj.leerCompra(reg, pos)){ // Mandar a vista file
        if (strcmp(id, reg.getNroFactura()) == 0){
            return pos;
        }
        pos++;
    }
    return -1;
}

float CompraNegocio::AnularCompra(const char * id){
	CompraFile reg;
	TransaxInventario obj;
	CompraVista obj2;
	int pos = buscarPosicion(id);
	float pu=0;
	if (pos >= 0){ 		//porque lo encuentra

			reg.leerCompra(obj,pos);
			obj.setStatus(false); //camio el estado para que no lo muestre. Baja logica
			obj2.messageAnulacionOK();
			reg.grabarEnDisco(obj,pos);//tengo que poner la posicion
		}
	 else{
				obj2.messageAnulacionNotOK();

    }
    cout << endl << endl;


}
