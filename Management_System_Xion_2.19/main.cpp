#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstring>
#include <cstdio>
#include<string.h>
#include "Fecha.h"
#include "Cliente.h"
#include "ClienteNegocio.h"
#include "ClienteFile.h"
#include "ClienteVista.h"
#include "Proveedor.h"
#include "MenuPrincipal.h"
#include"TransaxinventarioNegocio.h"
#include"Articulo.h"
using namespace std;

// punto1)BUSCA LA MAYOR DE LAS COMPRAS X IMPORTE
//

void Punto1(){
TransaxinventarioNegocio negocio;
TransaxInventario *vectorStock;
vectorStock= negocio.Cargar_Vector_de_Compras();
float maximaCOmpra=0;
        for(int x=0;x<negocio.CantidadDeCompras();x++){

			if(vectorStock[x].getTRprecioUnitario()>maximaCOmpra){
			maximaCOmpra=vectorStock[x].getTRprecioUnitario();

		}
}
        cout<< "-----maximaCOmpra--------------------"<<maximaCOmpra<<endl;
        //return maximaCOmpra;
    delete vectorStock;
}

void Punto1b(){


}





int main()
{

Punto1();

MenuPrincipal mainMenu;
mainMenu.menuPrincipal();






return 0;
}
