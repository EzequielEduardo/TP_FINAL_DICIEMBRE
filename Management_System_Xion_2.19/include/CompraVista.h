#ifndef COMPRAVISTA_H
#define COMPRAVISTA_H


class CompraVista
{
    private:


	public:

    void menuCompras();
	bool cargarCompras();
	bool mostrarCompras();
	void MostrarComprasxFecha();
	void ListarComprasxFactura();
	void messageAnulacionOK();
	void messageAnulacionNotOK();
	void messageReversoAnulacionOK();
	int PideNewQFacturaCompras();
	void messageFacturaModifOK();
	void messageValidacionCompra(bool flagValidacion);
};

#endif // COMPRAVISTA_H
