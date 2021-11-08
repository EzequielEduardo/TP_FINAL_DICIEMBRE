#include<iostream>
#include<clocale>
#include<cstdlib>

#include "VentaFile.h"
#include "Articulo.h"
#include "VentaNegocio.h"

using namespace std;

  bool VentaFile::grabarEnDisco(TransaxInventario articulo){

        FILE *p;
        p=fopen("Ventas.dat","ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&articulo, sizeof (TransaxInventario), 1, p);
        fclose(p);
        return escribio;
    }


bool VentaFile::grabarEnDisco(TransaxInventario obj,int pos){  // Sobrecarga de funciones para modificar registro
    bool grabo;
    FILE *p;
    p = fopen("Ventas.dat", "rb+");
    if (p == NULL){return false;}
    fseek(p, sizeof(obj)*pos, SEEK_SET);
    grabo = fwrite(&obj, sizeof(obj), 1, p);
    fclose(p);
    return grabo;
}


TransaxInventario* VentaFile::obtener_Datos_Compras(){

        int pos=0,cant=cantidadDeDatosGrabados();
        TransaxInventario* vectorVentas= new TransaxInventario[cant];
        if(vectorVentas==NULL) return 0;

        FILE *p;
        p=fopen("Ventas.dat","rb");
        if(p==NULL) return 0;

        fseek(p, pos*sizeof (TransaxInventario), 0);
        fread(&vectorVentas[pos], sizeof (TransaxInventario), cant, p);

        fclose(p);
        return vectorVentas;
    }

    int VentaFile::cantidadDeDatosGrabados(){

        TransaxInventario venta;
        int cantidad=0;

        FILE *p;
        p=fopen("Ventas.dat","rb");
        if(p==NULL) return false;

        while(fread(&venta, sizeof (TransaxInventario), 1, p)==true)cantidad++;


        fclose(p);
        return cantidad;
    }

bool VentaFile::leerVenta(TransaxInventario &reg, int pos)
{

    FILE *p;
    p=fopen("Ventas.dat", "rb");
    if(p==NULL) return false;
    fseek(p,sizeof(reg)*pos,0);
    bool leyo=fread(&reg, sizeof(reg), 1, p);
    fclose(p);
    return leyo;
}
