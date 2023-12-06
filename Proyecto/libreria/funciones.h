#ifndef FUNCIONES_H
#define FUNCIONES_H


#include "gimnasio.h"
#include "clientes.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

//todas las funciones

//clientes
void resize_cli(sClientes*& lista, int &n);
void ClienteLista(ifstream *archicli,sClientes*lista,int &n);
bool EscribirArchivoClientes(ofstream* archicli,sClientes* listacli,int N);

//clases
void resize_clase(sClases*& lista, int &n);
void LeerArchivoClasesaLista(ifstream* archivo,sClases *lista,int &n);
bool EscribirArchivoClases(ofstream* archivo,sClases* lista,int N);


//Gimnasio
void LeerAsistencia(ifstream* archiasist,sAsistencia* cupo);//binario
bool EscribirAsistencia(ofstream* archiasist,sAsistencia* cupo);
bool EscribirAsismañana(ofstream* archi, sAsistencia* asis);
void resize_asis(sAsistencia*& lista, int &n);

//Funciones extra
time_t fechaInscripcion();
string InscripcionMusculito(sClientes*lista, int&n);
bool verificar_cupos(sAsistencia* list,sClases* clases, sCupos cupotot);
bool reserva(sAsistencia nuevocliente, sAsistencia*listaasis, int &n, sClases*clases, sCupos* cups);
void MenuPrincipal();
sAsistencia* eliminarrepetidos(sAsistencia* lista, int& n);




































#endif // FUNCIONES_H
