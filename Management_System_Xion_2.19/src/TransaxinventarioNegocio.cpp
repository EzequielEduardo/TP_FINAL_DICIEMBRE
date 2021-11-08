#include "TransaxinventarioNegocio.h"
#include "TransaxinventarioFile.h"
#include "Articulo.h"
#include "ArticuloFile.h"
//METODOS TRANSAX
int TransaxinventarioNegocio::buscarPosicionIDArticulo(const char *id){
    TransaxInventario reg;
    TransaxinventarioFile obj;
    int pos = 0;
    int maxpos = 0;
    while(obj.leerCompra_vta(reg, pos)){ // Mandar a vista file
        if (strcmp(id, reg.getTRID_Articulo()) == 0 && pos>maxpos){
			maxpos=pos;
        }
        pos++;

	}
    if(maxpos!=0)return maxpos;
    else return -1;
}

void TransaxinventarioNegocio::actualizarstock(bool tipoTrans,TransaxInventario &compra_vta)
{
    TransaxinventarioFile archivo;
	ArticuloFile reg;
	int stock;
	int pos = buscarPosicionIDArticulo(compra_vta.getTRID_Articulo());
	if (pos >= 0){ 		//porque lo encuentra

	stock=archivo.getStock(pos); // deberia darme el stock actual + la posicion en el file

    if(tipoTrans==0 ) // 0 es venta
    {
        compra_vta.setTipoTransax(0);
        stock-=compra_vta.getTRCantidad();
    }
    else {
        compra_vta.setTipoTransax(1); //1 es compra
        stock+=compra_vta.getTRCantidad();
    }
        compra_vta.setStock(stock);

        float precioOK= reg.getPrecioArticulo(compra_vta.getTRID_Articulo());
        float stockValorizado=stock*precioOK;
        compra_vta.setStockValorizado(stockValorizado);
        archivo.grabarDatosInventario(compra_vta);
	}

	else{	// si el producto no esta en stock. Primer ingreso al stock
		if(tipoTrans==0 ) // 0 es venta
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




