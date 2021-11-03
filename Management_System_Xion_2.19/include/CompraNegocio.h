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
	int buscarPosicion(const char *id);
	float AnularCompra(const char * id);
};

#endif // COMPRANEGOCIO_H
