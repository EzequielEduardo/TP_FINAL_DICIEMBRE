#ifndef COMPRAVISTA_H
#define COMPRAVISTA_H


class CompraVista
{
    private:


	public:


	bool cargarCompras();
	bool mostrarCompras();
	void MostrarComprasxFecha();
	void ListarComprasxFactura();
	void messageAnulacionOK();
	void messageAnulacionNotOK();
	void messageReversoAnulacionOK();
	int PideNewQFacturaCompras();
	void messageFacturaModifOK();
	void messageValidacionCompra();
};

#endif // COMPRAVISTA_H
