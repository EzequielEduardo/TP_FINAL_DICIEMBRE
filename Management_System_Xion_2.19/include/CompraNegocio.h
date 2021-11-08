#ifndef COMPRANEGOCIO_H
#define COMPRANEGOCIO_H
#include "Transaxinventario.h"
#include "Articulo.h"
class CompraNegocio
{
    private:

	public:

	bool guardarDatos(TransaxInventario);
	void cargarCadena(char *pal, int tam);
	TransaxInventario* Cargar_Vector_de_Compras();
	int CantidadDeCompras();
	int buscarPosicionInvoice(const char *id);
	void AnularCompra(const char * id);
	void ReversarAnulacionCompra(const char * id);
	void ModifQenFacturaDeCompras(const char * invoice);
	bool ValidacionDeArticulo(const char * id);
};

#endif // COMPRANEGOCIO_H
