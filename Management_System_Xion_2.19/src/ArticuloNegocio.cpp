#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstring>
#include <cstdio>
#include<string.h>
#include "Articulo.h"
#include "ArticuloFile.h"
#include "ArticuloNegocio.h"
#include "ArticuloVista.h"
#include "Transaxinventario.h"
using namespace std;


bool ArticuloNegocio::guardarDatos(Articulo articulo)
{
    ArticuloFile archivo;
    return archivo.grabarEnDisco(articulo);
}

int ArticuloNegocio::buscarPosicion(const char *id){
    Articulo reg;
    ArticuloFile obj;
    int pos = 0;
    while(obj.leerArticulo(reg, pos)){ // Mandar a vista file
        if (strcmp(id, reg.getID_Articulo()) == 0){
            return pos;
        }
        pos++;
    }
    return -1;
}

float ArticuloNegocio::ModificarPreciodeArt(const char * id){
	ArticuloFile reg;
	Articulo obj;
	ArticuloVista obj2;
	int pos = buscarPosicion(id);
	float pu=0;
	if (pos >= 0){ 		//porque lo encuentra

			reg.leerArticulo(obj,pos);
			obj.setprecioUnitario(obj2.askNewPrice());
			obj2.messageCargaOK();
			reg.grabarEnDisco(obj,pos);//tengo que poner la posicion
		}
	 else{
				obj2.messageCargaNotOK();

    }
    cout << endl << endl;


}

Articulo* ArticuloNegocio::Cargar_Vector_de_Articulos()
{
    Articulo *vectorArticulos;
    ArticuloFile archivo;
    vectorArticulos=archivo.obtener_Datos_Articulos();

return vectorArticulos;
}


int ArticuloNegocio::CantidadDeArticulos()
{

    ArticuloFile archivo;

    return archivo.cantidadDeDatosGrabados();

}


void ArticuloNegocio::cargarCadena(char *pal, int tam){
			int i;
			fflush(stdin);
			for(i=0;i<tam;i++){
				pal[i]=cin.get();
				if(pal[i]=='\n') break;
				}
				pal[i]='\0';
				fflush(stdin);
				}
