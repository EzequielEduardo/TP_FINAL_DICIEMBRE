#include<iostream>
#include<clocale>
#include<cstdlib>

#include "CompraFile.h"
#include "TransaxInventario.h"
#include "TransaxinventarioFile.h"
#include "CompraNegocio.h"

using namespace std;

bool CompraFile::grabarEnDisco(TransaxInventario compra){

        FILE *p;
        p=fopen("Compras.dat","ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&compra, sizeof (compra), 1, p);
        fclose(p);
        return escribio;
    }

bool CompraFile::grabarEnDisco(TransaxInventario obj,int pos){  // Sobrecarga de funciones para modificar registro
    bool grabo;
    FILE *p;
    p = fopen("Compras.dat", "rb+");
    if (p == NULL){return false;}
    fseek(p, sizeof(obj)*pos, SEEK_SET);
    grabo = fwrite(&obj, sizeof(obj), 1, p);
    fclose(p);
    return grabo;
}


TransaxInventario* CompraFile::obtener_Datos_Compras(){

        int pos=0,cant=cantidadDeDatosGrabados();
        TransaxInventario* vectorCompras= new TransaxInventario[cant];
        if(vectorCompras==NULL) return 0;

        FILE *p;
        p=fopen("Compras.dat","rb");
        if(p==NULL) return 0;

        fseek(p, pos*sizeof (TransaxInventario), 0);
        fread(&vectorCompras[pos], sizeof (TransaxInventario), cant, p);

        fclose(p);
        return vectorCompras;
    }

    int CompraFile::cantidadDeDatosGrabados(){

        TransaxInventario compra;
        int cantidad=0;

        FILE *p;
        p=fopen("Compras.dat","rb");
        if(p==NULL) return false;

        while(fread(&compra, sizeof (TransaxInventario), 1, p)==true)cantidad++;


        fclose(p);
        return cantidad;
    }

bool CompraFile::leerCompra(TransaxInventario &reg, int pos)
{

    FILE *p;
    p=fopen("Compras.dat", "rb");
    if(p==NULL) return false;
    fseek(p,sizeof(reg)*pos,0);
    bool leyo=fread(&reg, sizeof(reg), 1, p);
    fclose(p);
    return leyo;
}

