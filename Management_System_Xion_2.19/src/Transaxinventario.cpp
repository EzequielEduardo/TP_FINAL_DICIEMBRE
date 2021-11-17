#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include "Transaxinventario.h"

		void TransaxInventario::setTRID_Articulo(const char* cadena){strcpy(trid_Articulo,cadena);}
        void TransaxInventario::setTRCantidad(int n){trcantidad=n;}
        void TransaxInventario::setTRprecioUnitario(float n){trprecioUnitario=n;}
		void TransaxInventario::setFechaTransax(Fecha xx){fechaTransax=xx;}
		void TransaxInventario::setStock(int n){stock=n;}
        void TransaxInventario::setStockValorizado(float n){stockValorizado=n;}
        void TransaxInventario::setPrecioArt(float n){precioDeArt=n;}
		void TransaxInventario::setNroFactura(const char* cadena){strcpy(nroFactura,cadena);}
		void TransaxInventario::setCategoria(const char* cadena){strcpy(categoria,cadena);}
		void TransaxInventario::setMarca(const char* cadena){strcpy(marca,cadena);}
		void TransaxInventario::setStatus(bool _status){status=_status;}

        void TransaxInventario::setTipoTransax(int n){
                if(n==0)strcpy(tipoTransax,"Venta\0");
				if(n==1)strcpy(tipoTransax,"Compra\0");
				if(n==2)strcpy(tipoTransax,"Modificacion de Compra\0");
				if(n==3)strcpy(tipoTransax,"Modificacion de Venta\0");
            }


        TransaxInventario::TransaxInventario(int d,int m,int a){
            fechaTransax.setFecha(d,m,a);
            stock=stockValorizado=precioDeArt=0;
            }

        const char*  TransaxInventario::getTRID_Articulo(){return trid_Articulo;}
		const char*  TransaxInventario::getTipoTransax(){return tipoTransax;}
        int          TransaxInventario::getTRCantidad(){return trcantidad;}
        float        TransaxInventario::getTRprecioUnitario(){return trprecioUnitario;}
		Fecha        TransaxInventario::getFechaTransax(){return fechaTransax;}
		int          TransaxInventario::getStock(){return stock;}
        float        TransaxInventario::getStockValorizado(){return stockValorizado;}
        float        TransaxInventario::getPrecioArt(){return precioDeArt;}
        const char*  TransaxInventario::getNroFactura(){return nroFactura;}
        const char*  TransaxInventario::getCategoria(){return categoria;}
		const char*  TransaxInventario::getMarca(){return marca;}
		bool 		 TransaxInventario::getStatus(){return status;}
		float 		 TransaxInventario::getTRValorizada(){return trcantidad*trprecioUnitario;}
