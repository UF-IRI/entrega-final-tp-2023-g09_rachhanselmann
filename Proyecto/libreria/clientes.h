#ifndef CLIENTES_H
#define CLIENTES_H
#include <string>
#include <iostream>
#include "gimnasio.h"

using namespace std;

struct Cliente{

    string nombre, apellido, reservas;
    int dni, numero_telefono;
    bool pago; //si está activa
    bool membersia; //musculacion o clases

};

//funciones para las clases
void reservaClase();
void cancelarClase();
void cambiarClase();


//funciones para la musuclacion
void resevaMuscu();
void cancelarMuscu();
void cambiarMuscu();


#endif // CLIENTES_H
