#include<iostream>
#include<clocale>
#include<cstdlib>
#include<cstring>
#include <cstdio>
#include<string.h>
#include "Empleado.h"
#include "EmpleadoFile.h"
#include "EmpleadoNegocio.h"
#include "EmpleadoVista.h"

using namespace std;

bool EmpleadoNegocio::guardarDatos(Empleado Employee)
{

    EmpleadoFile archivo;
    return archivo.grabarEnDisco(Employee);

}

Empleado* EmpleadoNegocio::Cargar_Vector_de_Empleados()
{
    Empleado *vectorEmpleados;
    EmpleadoFile archivo;
    vectorEmpleados=archivo.obtener_Datos_de_Empleados();

return vectorEmpleados;
}

int EmpleadoNegocio::CantidadDeRegEmpleados()
{

    EmpleadoFile archivo;

    return archivo.cantidadDeDatosGrabados();

}

		void EmpleadoNegocio::cargarCadena(char *pal, int tam){
			int i;
			fflush(stdin);
			for(i=0;i<tam;i++){
				pal[i]=cin.get();
				if(pal[i]=='\n') break;
				}
				pal[i]='\0';
				fflush(stdin);
				}
