#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "clientes.h"
#include "gimnasio.h"
#include <fstream>
#include  <string>
#include<iostream>

using namespace std;



//funciones para las clases
void reserva(sClientes cli, unsigned int IDclase);
//void cancelacion(sClientes cli, Class claseelegida);
//void cambiosenreserva(sClientes cli, Class clasevieja, Class clasenueva);
void guardarClase(fstream& archivo, sGimnasio gym);
bool CrearlistaClases(ifstream* archi, sClases* cla);

//clientes
void guardarcliente(fstream &Archivo,sClientes cli);
void resize_cli(sClientes*& lista, int &n);
sClientes* ClienteLista(ifstream *archicli,sClientes*lista,int &n );
bool LeerArchivoClientes(ifstream* archivo,sClientes *lista,int &n);
bool EscribirArchivoClientes(ofstream* archicli,sClientes* listacli,int N);

//Gimnasio
bool LeerArchivoGym(ifstream* archigym,sGimnasio *list,int &n);
bool escribirasistencia(ofstream* archiasist,sGimnasio* cupo);//binario
bool leerasistencia(ifstream* archiasist,sGimnasio* cupo);

void InscripcionMusculito(bool resul);
//




































#endif // FUNCIONES_H
