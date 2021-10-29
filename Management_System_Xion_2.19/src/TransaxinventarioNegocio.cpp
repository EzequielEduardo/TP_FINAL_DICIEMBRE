#include "TransaxinventarioNegocio.h"
#include "TransaxinventarioFile.h"
#include "Articulo.h"
#include "ArticuloFile.h"
//METODOS TRANSAX
void TransaxinventarioNegocio::actualizarstock(bool tipoTrans,TransaxInventario &compra_vta)
{
    TransaxinventarioFile archivo;
	ArticuloFile reg;

	int stock=archivo.getStock();

    if(tipoTrans==0) // 0 es venta
    {
        compra_vta.setTipoTransax(0);
        stock-=compra_vta.getTRCantidad();

    }
    else
    {
        compra_vta.setTipoTransax(1); //1 es compra
        stock+=compra_vta.getTRCantidad();
    }
        compra_vta.setStock(stock);

        float precioOK= reg.getPrecioArticulo(compra_vta.getTRID_Articulo());
        float stockValorizado=stock*precioOK;
        compra_vta.setStockValorizado(stockValorizado);
        archivo.grabarDatosInventario(compra_vta);
}

int TransaxinventarioNegocio::CantidadDeTransax()
{

    TransaxinventarioFile archivo;

    return archivo.cantidadDeTransaxGrabadas();

}

void TransaxinventarioNegocio::cargarCadena(char *pal, int tam){
			int i;
			fflush(stdin);
			for(i=0;i<tam;i++){
				pal[i]=cin.get();
				if(pal[i]=='\n') break;
				}
				pal[i]='\0';
				fflush(stdin);
				}

TransaxInventario* TransaxinventarioNegocio::Cargar_Vector_de_Stocks()
{
    TransaxInventario *vectorStocks;
    TransaxinventarioFile archivo;
    vectorStocks=archivo.obtener_Datos_Inventario();

return vectorStocks;
}


float getStock(){
TransaxinventarioFile archivo;
return archivo.getStock();
}


//METODOS COMPRAS
bool TransaxinventarioNegocio::guardarDatosCompra(TransaxInventario compra)
{
    TransaxinventarioFile archivo;
    return archivo.grabarDatosCompraEnDisco(compra);
}

TransaxInventario* TransaxinventarioNegocio::Cargar_Vector_de_Compras()
{
    TransaxInventario *vectorCompras;
    TransaxinventarioFile archivo;
    vectorCompras=archivo.obtener_Datos_Compras();

return vectorCompras;
}


int TransaxinventarioNegocio::CantidadDeCompras()
{

    TransaxinventarioFile archivo;

    return archivo.cantidadDeDatosComprasGrabadas();

}


//METODOS VENTAS

bool TransaxinventarioNegocio::guardarDatosVenta(TransaxInventario venta)
{
    TransaxinventarioFile archivo;
    return archivo.grabarDatosVentasEnDisco(venta);
}

TransaxInventario* TransaxinventarioNegocio::Cargar_Vector_de_Ventas()
{
    TransaxInventario *vectorVentas;
    TransaxinventarioFile archivo;
    vectorVentas=archivo.obtener_Datos_Ventas();

return vectorVentas;
}

int TransaxinventarioNegocio::CantidadDeVentas()
{

    TransaxinventarioFile archivo;

    return archivo.cantidadDeDatosVentasGrabadas();

}


void TransaxinventarioNegocio::MostrarVtasxFecha(TransaxInventario reg){

	TransaxInventario *vectorStock=Cargar_Vector_de_Stocks(); // vector que contiene todo el file inventario

	  for(int x=0;x<CantidadDeTransax();x++){
			if(reg.getFechaTransax()==vectorStock[x].getFechaTransax() &&
				strcmp(reg.getTRID_Articulo(),vectorStock[x].getTRID_Articulo())==0 &&
				strcmp("venta",vectorStock[x].getTipoTransax())==0){
				cout<<"CODIGO DE ARTICULO: "<<vectorStock[x].getTRID_Articulo()<<endl;
				cout<<"CATEGORIA: "<<vectorStock[x].getCategoria()<<endl;
				cout<<"MARCA: "<<vectorStock[x].getMarca()<<endl;
				cout<<"CANTIDAD VENDIDA: "<<vectorStock[x].getTRCantidad()<<endl;
				cout<<"PRECIO DE ARTICULO VENDIDO: "<<vectorStock[x].getTRprecioUnitario()<<endl;
				system("pause");
			}
}
}

