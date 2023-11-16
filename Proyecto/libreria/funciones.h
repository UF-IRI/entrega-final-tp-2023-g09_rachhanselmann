#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "clientes.h"
#include "gimnasio.h"

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;



//todas las funciones

//clientes
void resize_cli(sClientes*& lista, int &n);
sClientes* ClienteLista(ifstream *archicli,sClientes*lista,int &n );
bool EscribirArchivoClientes(ofstream* archicli,sClientes* listacli,int N);

//clases
void resize_clase(sClases*& lista, int &n);
sClases* LeerArchivoClasesaLista(ifstream* archivo,sClases *lista,int &n);
bool EscribirArchivoClases(ofstream* archivo,sClases* lista,int N);


//Gimnasio
bool LeerAsistencia(ifstream* archiasist,sAsistencia* cupo);//binario
sAsistencia* binariolista(ifstream archi);
bool EscribirAsistencia(ofstream* archiasist,sAsistencia* cupo);

//Funciones extra
time_t fechaInscripcion();
int InscripcionMusculito(sClientes*lista, int&n);
bool reserva(string id_clase, sAsistencia*listaasis);
bool verificar_cupos(sAsistencia* list, string cupos_tot, string id);
void MenuPrincipal();





































#endif // FUNCIONES_H
