#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "clientes.h"
#include "gimnasio.h"


//funciones para las clases
void reserva(sClientes cli, unsigned int IDclase);
//void cancelacion(sClientes cli, Class claseelegida);
//void cambiosenreserva(sClientes cli, Class clasevieja, Class clasenueva);
void guardarClase(fstream& archivo, sGimnasio gym);
bool CrearlistaClases(ifstream* archi, sClases* cla);

//clientes
void guardarcliente(fstream &Archivo,sClientes cli);
void resize_cli(sClientes*& lista, int &n);

string LeerArchivoClientes(ifstream* archivo,sClientes *lista,int &n);
string EscribirArchivoClientes(ofstream* archi,sClientes* listacli,int N);

//Gimnasio
string LeerArchivoGym(ifstream* archigym,sGimnasio *list,int &n);
string reservacupos(ofstream* archiasist,sGimnasio* cupo);//binario
string leerasistencia(ifstream* archiasist,sGimnasio* cupo);






































#endif // FUNCIONES_H
