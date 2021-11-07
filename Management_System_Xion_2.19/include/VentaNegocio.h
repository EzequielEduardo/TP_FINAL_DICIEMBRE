#ifndef VENTANEGOCIO_H
#define VENTANEGOCIO_H
#include"Transaxinventario.h"

class VentaNegocio
{
    private:

	public:

	bool guardarDatos(TransaxInventario);
	void cargarCadena(char *pal, int tam);
	int buscarPosicionInvoice(const char *id);
	void AnularVenta(const char * id);
	void ReversarAnulacionVenta(const char * id);
	void ModifQenFacturaDeVtas(const char * invoice);
};

#endif // VENTANEGOCIO_H
