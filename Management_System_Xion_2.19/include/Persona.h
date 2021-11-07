#define FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#ifndef PERSONA_H
#define PERSONA_H
#include"Persona.h"

class Persona
{
		protected:

		char nombre[50];
        char apellido [50];
        char cuil[50];
        char domicilio[50];
        char localidad[50];
        int telefono;
        char email[50];


	public:

        ///sets

		void setNombre(const char*);
        void setApellido(const char*);
        void setCuil(const char* );
        void setDomicilio(const char*);
        void setLocalidad(const char*);
        void setTelefono(int);
        void setEmail(const char*);


        ///gets

        const char* getNombre();
        const char* getApellido();
		const char*   		getCuil();
        const char* getDomicilio();
        const char* getLocalidad();
        int         getTelefono();
        const char* getEmail();






};

#endif // PERSONA_H
