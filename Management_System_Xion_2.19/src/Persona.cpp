#include<clocale>
#include<cstdlib>
#include <cstdio>
#include<cstring>
using namespace std;
#include "Persona.h"

///sets


        void Persona::setNombre(const char *cadena){strcpy(nombre,cadena);  }
        void Persona::setApellido(const char* cadena){strcpy(apellido,cadena);}
        void Persona::setCuil(const char* nro){strcpy(cuil,nro);}
        void Persona::setDomicilio(const char* cadena){strcpy(domicilio,cadena);}
        void Persona::setLocalidad(const char* cadena){strcpy(localidad,cadena);}
        void Persona::setTelefono(int n){telefono=n;}
        void Persona::setEmail(const char* cadena){strcpy(email,cadena);}

///gets

        const char* Persona::getNombre(){return nombre;}
        const char* Persona::getApellido(){return apellido;}
        const char*	Persona::getCuil(){return cuil;}
        const char* Persona::getDomicilio(){return domicilio;}
        const char* Persona::getLocalidad(){return localidad;}
        int         Persona::getTelefono(){return telefono;}
        const char* Persona::getEmail(){return email;}


