#define FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#ifndef ARTICULO_H
#define ARTICULO_H


class Articulo
{
   private:
        char id_Articulo[20];
        float precioUnitario;
        char marca[15];
		char categoria[20];

    public:
        void setID_Articulo(const char* );
        void setprecioUnitario(float);
		void setMarca(const char* );
        void setCategoria(const char* );

        const char*  getID_Articulo();
        float getprecioUnitario();
        void menuArticulos();
        const char*  getMarca();
        const char*  getCategoria();
};

#endif // ARTICULO_H
