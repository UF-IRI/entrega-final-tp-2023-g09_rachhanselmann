#include "funciones.h"

//funciones para Clientes

void resize_cli(sClientes*& lista, int &n){
    n=(n)+1;
    sClientes *aux=new sClientes[n];
    for(int i=0;i<n-1;i++){
        aux[i]=lista[i];}
    delete[] lista;
    lista=aux;
}

bool LeerArchivoClientes(ifstream* archicli,sClientes *list,int &n){
    if (!archicli->is_open())
        return false;

    string header;
    getline(*archicli,header);

    string auxnombre, auxapellido, auxmail;
    unsigned int auxiD, auxnumero_telefono;
    int auxestado; // 0=todo pago, positivo= dinero a favor, negativo=debe dinero
    tm auxfecha_nac;
    char coma=',';
    int i=0;
    while(*archicli>>auxiD>>coma>>auxnombre>>coma>>auxapellido>>coma>>auxmail>>coma>>auxnumero_telefono>>coma>>auxfecha_nac>>>coma>>auxestado){
        resize_cli(list,n);
        (list+i)->iD=auxiD;
        (list+i)->nombre=auxnombre;
        (list+i)->apellido=auxapellido;
        (list+i)->mail=auxmail;
        (list+i)->numero_telefono=auxnumero_telefono;
        (list+i)->fecha_nac=auxfecha_nac;
        (list+i)->estado=auxestado;
        i++;

    }
        return true;

}


bool EscribirArchivoClientes(ofstream* archicli,sClientes* listacli,int N){
    if(!archicli->is_open())
        return false;

    char coma=',';
    string header;

    //getline(archicli, header);

    if(header=="")
        *archicli<<"iDcliente"<<coma<<"nombre"<<coma<<"apellido"<<coma<<"email"<<coma<<"telefono"<<coma<<"fechaNac"<<coma<<"estado"<<endl;


    for(int i=0;i<N;i++){
        *archicli<<listacli[i].iD<<coma<<listacli[i].nombre<<coma<<listacli[i].apellido<<coma<<listacli[i].mail<<coma<<listacli[i].numero_telefono<<coma<<listacli[i].fecha_nac<<coma<<listacli[i].estado<<endl;

    }
    return true;
}

sClientes* ClienteLista(ifstream *archicli,sClientes*lista,int &n ){

    if(!archicli->is_open() || lista==nullptr)
        return nullptr;

    sClientes* nuevalista= new sClientes[n];
    char coma=',';
    int i=0;

    while(*archicli>>nuevalista[i].iD>>coma>>nuevalista[i].nombre>>coma>>nuevalista[i].apellido>>coma>>nuevalista[i].mail>>coma>>nuevalista[i].fecha_nac>>coma>>nuevalista[i].estado){

        resize_cli(lista,n);
        (lista+i)->iD=nuevalista->iD;
        (lista+i)->nombre=nuevalista->nombre;
        (lista+i)->apellido=nuevalista->apellido;
        (lista+i)->mail=nuevalista->mail;
        (lista+i)->numero_telefono=nuevalista->numero_telefono;
        (lista+i)->fecha_nac=nuevalista->fecha_nac;
        (lista+i)->estado=nuevalista->estado;

        i++;
    }
    delete[]lista ;
    return nuevalista;

}

bool AgregarClienteLista(sClientes*lista,int n){







}

//funciones gimnasio

void resize_clase(sClases*& lista, int &n){
    n=(n)+1;
    sClases *aux=new sClases[n];
    for(int i=0;i<n-1;i++){
        aux[i]=lista[i];}
    delete[] lista;
    lista=aux;
}

bool LeerArchivoGym(ifstream* archigym,sClases *list,int &n){
    if (!archigym->is_open())
        return false;

    string header;
    getline(*archigym,header);

    string auxIDclase;
    string auxnombre;
    time_t auxhorario;
    char coma=',';
    int i=0;
    while(*archigym>>auxIDclase>>coma>>auxnombre>>coma>>auxhorario){
        resize_clase(list,n);
        (list+i)->IDclase=auxIDclase;
        (list+i)->nombre=auxnombre;
        (list+i)->horario=auxhorario;
        i++;
        return true;
    }

}//falta terminar, nose como hacer bien el leer

bool escribirasistencia(ofstream* archiasist,sAsistencia* cupo){

    if(!archiasist->is_open())
        return false;


    archiasist->write((char*)cupo,sizeof(sAsistencia));//hay que ver como poner cada uno o si ya asi se pone todo lo que se necesita para la reserva

    return true;
}

bool leerasistencia(ifstream* archiasist,sAsistencia* cupo,int &n){

    if(!archiasist->is_open())
        return false;


    archiasist->read((char*)cupo, sizeof(sAsistencia));

    return true;

}


//funcion time, reservas,
void fechaInscripcion( ){

}
//funciones: bool reservas->parametros (lista archivo binario, lista de clases) recorrer las lista del binario y hacer un if que la lista del binario sea igual que la de la clase usamos un contador++
//
//funcion: pedir datos del cliente y despues llamar a generar reserva
//
//funcion por separado para llamar a las distintas clases por su id y horario (con el cupo =cupo-34->primer turno)
//
//terminar el main, abrir y cerrar archivos, menu,
//pedir id de cliente si esta anotado en un if y directo al menu
// testings
//como sumar los archivos al programa para poder usarlos
//leer y escribir funcion clientes
// fijar si hay que hacer + funciones extras a archivos
// lunes a sabados!!
