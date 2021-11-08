#include<iostream>

#include "TransaxinventarioFile.h"
#include "Transaxinventario.h"

using namespace std;

//metodos para stock
bool TransaxinventarioFile::grabarDatosInventario(TransaxInventario compra_venta)
{

    FILE *p;
    p=fopen("Inventario.dat","ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&compra_venta, sizeof (TransaxInventario), 1, p);
    fclose(p);
    return escribio;
}

 TransaxInventario* TransaxinventarioFile::obtener_Datos_Inventario()
{

    int pos=0,cant=cantidadDeTransaxGrabadas();
    TransaxInventario* vectorInventario= new TransaxInventario[cant];
    if(vectorInventario==NULL) return 0;

    FILE *p;
    p=fopen("Inventario.dat","rb");
    if(p==NULL) return 0;

        fseek(p, pos*sizeof (TransaxInventario), 0);
        fread(&vectorInventario[pos], sizeof (TransaxInventario), cant, p);

    fclose(p);
    return vectorInventario;
}


int TransaxinventarioFile::cantidadDeTransaxGrabadas()
{

    TransaxInventario inventario;
        int bytes, Qregistros=0;

    FILE *p;
    p=fopen("Inventario.dat","rb");
    if(p==NULL) return false;

        fseek(p, 0, SEEK_END);
		bytes = ftell(p);
		Qregistros = bytes / sizeof(TransaxInventario);
		fclose(p);

    return Qregistros;
}

int TransaxinventarioFile::getStock(int pos){
        TransaxInventario datos;
        FILE *p;
        p=fopen("Inventario.dat","rb");
        if(p==NULL) return 0;
        fseek(p, sizeof (TransaxInventario)*pos, 0);
        fread(&datos, sizeof (TransaxInventario), 1, p);


        return datos.getStock();
}

bool TransaxinventarioFile::leerCompra_vta(TransaxInventario &reg, int pos)
{

    FILE *p;
    p=fopen("Inventario.dat", "rb");
    if(p==NULL) return false;
    fseek(p,sizeof(reg)*pos,0);
    bool leyo=fread(&reg, sizeof(reg), 1, p);
    fclose(p);
    return leyo;
}


//metodos para compras


TransaxInventario* TransaxinventarioFile::obtener_Datos_Compras(){

        int pos=0,cant=cantidadDeDatosComprasGrabadas();
        TransaxInventario* vectorCompras= new TransaxInventario[cant];
        if(vectorCompras==NULL) return 0;

        FILE *p;
        p=fopen("Compras.dat","rb");
        if(p==NULL) return 0;

        for(pos;pos<cant;pos++){

        fseek(p, pos*sizeof (TransaxInventario), 0);
        fread(&vectorCompras[pos], sizeof (TransaxInventario), 1, p);

        }

        fclose(p);
        return vectorCompras;
    }

const char * TransaxinventarioFile::getFacturaCompras(){
        TransaxInventario datos;
        FILE *p;
        p=fopen("Compras.dat","rb");
        if(p==NULL) return 0;
        fseek(p, -sizeof (TransaxInventario), 2);
        fread(&datos, sizeof (TransaxInventario), 1, p);

        return datos.getNroFactura();
}

bool TransaxinventarioFile::grabarDatosCompraEnDisco(TransaxInventario compra)
{

    FILE *p;
    p=fopen("Compras.dat","ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&compra, sizeof (TransaxInventario), 1, p);
    fclose(p);
    return escribio;
}


int TransaxinventarioFile::cantidadDeDatosComprasGrabadas()
{

    TransaxInventario inventario;
    int cantidad=0;

    FILE *p;
    p=fopen("Compras.dat","rb");
    if(p==NULL) return false;

    while(fread(&inventario, sizeof (TransaxInventario), 1, p)==true)cantidad++;


    fclose(p);
    return cantidad;
}

//metodos para ventas

TransaxInventario* TransaxinventarioFile::obtener_Datos_Ventas(){

        int pos=0,cant=cantidadDeDatosVentasGrabadas();
        TransaxInventario* vectorVentas= new TransaxInventario[cant];
        if(vectorVentas==NULL) return 0;

        FILE *p;
        p=fopen("Ventas.dat","rb");
        if(p==NULL) return 0;

        for(pos;pos<cant;pos++){

        fseek(p, pos*sizeof (TransaxInventario), 0);
        fread(&vectorVentas[pos], sizeof (TransaxInventario), 1, p);

        }

        fclose(p);
        return vectorVentas;
    }

    bool TransaxinventarioFile::grabarDatosVentasEnDisco(TransaxInventario venta)
{

    FILE *p;
    p=fopen("Ventas.dat","ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&venta, sizeof (TransaxInventario), 1, p);
    fclose(p);
    return escribio;
}


int TransaxinventarioFile::cantidadDeDatosVentasGrabadas()
{

    TransaxInventario inventario;
    int cantidad=0;

    FILE *p;
    p=fopen("Ventas.dat","rb");
    if(p==NULL) return false;

    while(fread(&inventario, sizeof (TransaxInventario), 1, p)==true)cantidad++;


    fclose(p);
    return cantidad;
}




