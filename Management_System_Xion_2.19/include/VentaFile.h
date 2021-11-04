#ifndef VENTAFILE_H
#define VENTAFILE_H
#include"Transaxinventario.h"

class VentaFile
{
	private:

	public:

	bool grabarEnDisco(TransaxInventario);
	bool grabarEnDisco(TransaxInventario obj,int pos);
	TransaxInventario* obtener_Datos_Compras();
	int  cantidadDeDatosGrabados();
	bool leerVenta(TransaxInventario &,int pos);

};

#endif // VENTAFILE_H
