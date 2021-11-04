#ifndef VENTANEGOCIO_H
#define VENTANEGOCIO_H
#include"Transaxinventario.h"

class VentaNegocio
{
    private:

	public:

	bool guardarDatos(TransaxInventario);
	void cargarCadena(char *pal, int tam);
	int buscarPosicion(const char *id);
	void AnularVenta(const char * id);
	void ReversarAnulacionVenta(const char * id);
};

#endif // VENTANEGOCIO_H
