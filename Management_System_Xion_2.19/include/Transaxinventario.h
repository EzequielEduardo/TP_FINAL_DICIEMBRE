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

		//GETS
        const char*  getTRID_Articulo();
        const char*  getTipoTransax(){return tipoTransax;};
        int getTRCantidad();
        float getTRprecioUnitario();
		Fecha getFechaTransax();
        int getStock();
        float getStockValorizado();
        float getPrecioArt();

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
