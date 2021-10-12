#define FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#ifndef ARTICULOFILE_H
#define ARTICULOFILE_H


class ArticuloFile
{
	public:
		bool grabarEnDisco(Articulo );
		bool grabarEnDisco(Articulo obj,int pos);
        Articulo* obtener_Datos_Articulos();
        int  cantidadDeDatosGrabados();

		float getPrecioArticulo(const char * IdArticulo);
        bool leerArticulo(Articulo &,int pos);


	private:
};

#endif // ARTICULOFILE_H
