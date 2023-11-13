#include "funciones.h"
#include <fstream>
#include  <string>
using namespace std;

//funciones para Clientes

void resize_cli(sClientes*& lista, int &n){
    n=(n)+1;
    sClientes *aux=new sClientes[n];
    for(int i=0;i<n-1;i++){
        aux[i]=lista[i];}
    delete[] lista;
    lista=aux;
}

string LeerArchivoClientes(ifstream* archicli,sClientes *list,int &n){
    if (!archicli->is_open())
        return "";

    string header;
    getline(*archicli,header);

    sClientes *aux= new sClientes[n];

    string auxnombre, auxapellido, auxmail;
    unsigned int auxiD, auxdni, auxnumero_telefono;
    int auxestado; // 0=todo pago, positivo= dinero a favor, negativo=debe dinero
    bool auxmembresia; //musculacion o clases
    tm auxfecha_nac;
    char coma=',';
    int i=0;
    while()
}//falta terminar, nose como hacer bien el leer


string EscribirArchivoClientes(ofstream* archicli,sClientes* listacli,int N){
    if(!archicli->is_open())
        return "Error al abrir el archivo";
    char coma=',';
    string lain;

    getline(archicli, lain);

    if(lain=="")
        archicli<<"iDcliente"<<coma<<"nombre"<<coma<<"apellido"<<coma<<"email"<<coma<<"telefono"<<coma<<"fechaNac"<<coma<<"estado"<<endl;


    for(int i=0;i<N;i++){
        archicli<<listacli[i].iD<<coma<<listacli[i].nombre<<coma<<listacli[i].apellido<<coma<<listacli[i].mail<<coma<<
            listacli[i].numero_telefono<<coma<<listacli[i].fecha_nac<<coma<<listacli[i].estado<<endl;

    }
}


//funciones gimnasio

string LeerArchivoGym(ifstream* archigym,sGimnasio *list,int &n){
    if (!archigym->is_open())
        return "";

    string header;
    getline(*archigym,header);

    sGimnasio *aux= new sGimnasio[n];

    unsigned int IDcurso;
    tm FechaInsc;
    sClientes* misclientes;
    string clase;
    tm horario;
    int cupos_tot_clases;
    int cupos_act_clases;
    char coma=',';
    int i=0;
    while()
}//falta terminar, nose como hacer bien el leer

string reservacupos(ofstream* archiasist,sGimnasio* cupo){

    if(!archiasist->is_open())
        return "Error al abrir el archivo";

    archiasist->write((char*)cupo,sizeof(sGimnasio));//hay que ver como poner cada uno o si ya asi se pone todo lo que se necesita para la reserva

}

string leerasistencia(ifstream* archiasist,sGimnasio* cupo){

    if(!archiasist->is_open())
        return "No se pudeo abrir el archivo";
    while(archiasist){
        archiasist->read((char*)cupo, sizeof(sGimnasio));

    }


}
