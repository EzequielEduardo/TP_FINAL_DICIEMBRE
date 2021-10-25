#define FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#ifndef TRANSAXINVENTARIO_H
#define TRANSAXINVENTARIO_H
#include"Fecha.h"

class TransaxInventario
{
	private:
        char trid_Articulo[20];
        char tipoTransax[10];
        int trcantidad;
        float trprecioUnitario;
        Fecha fechaTransax;
        int stock;
        float stockValorizado;
        float precioDeArt;
		char nroFactura[15];
		char categoria[20];
		char marca[20];


	public:
		//SETS
		void setTRID_Articulo(const char* );
        void setTipoTransax(bool);
        void setTRCantidad(int);
        void setTRprecioUnitario(float);
        void setFechaTransax(Fecha);
        void _setFechaTransax(int,int,int);
        void setStock(int);
        void setStockValorizado(float);
        void setPrecioArt(float);
 		void setNroFactura(const char* );
 		void setCategoria(const char* );
		void setMarca(const char* );

		//GETS
        const char*  getTRID_Articulo();
        const char*  getTipoTransax();
        int getTRCantidad();
        float getTRprecioUnitario();
		Fecha getFechaTransax();
        int getStock();
        float getStockValorizado();
        float getPrecioArt();
		const char*  getNroFactura();
        const char*  getCategoria();
        const char*  getMarca();

        //CONSTRUCTOR
		TransaxInventario(){};
        TransaxInventario(int,int,int);

        //sobrecarga de operadores para comparar fechas
     /*   bool operator==(TransaxInventario obj){
        if(fechaTransax.getAnio()==obj.getFechaTransax().getAnio()) return true;
        if(fechaTransax.getMes()==obj.getFechaTransax().getMes()) return true;
		if(fechaTransax.getDia()==obj.getFechaTransax().getDia()) return true;
		if(fechaTransax.getAnio()!=obj.getFechaTransax().getAnio()) return false;
        if(fechaTransax.getMes()!=obj.getFechaTransax().getMes()) return false;
		if(fechaTransax.getDia()!=obj.getFechaTransax().getDia()) return false;
        }
*/
};

#endif // TRANSAXINVENTARIO_H
