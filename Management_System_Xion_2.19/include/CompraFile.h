#ifndef COMPRAFILE_H
#define COMPRAFILE_H
#include"TransaxInventario.h"
#include"CompraNegocio.h"
class CompraFile
{
    private:

	public:

	bool grabarEnDisco(TransaxInventario);
	bool grabarEnDisco(TransaxInventario obj,int pos);
	TransaxInventario* obtener_Datos_Compras();
	int  cantidadDeDatosGrabados();
	bool leerCompra(TransaxInventario &,int pos);

};

#endif // COMPRAFILE_H
