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


//funciones gimnasio

void resize_clase(sClases*& lista, int &n){
    n=(n)+1;
    sClases *aux=new sClases[n];
    for(int i=0;i<n-1;i++){
        aux[i]=lista[i];}
    delete[] lista;
    lista=aux;
}


sClases* LeerArchivoClasesaLista(ifstream* archivo,sClases *lista,int &n)
{
    if(!archivo->is_open() || lista==nullptr)
        return nullptr;

    sClases* nuevalista= new sClases[n];
    char coma=',';
    int i=0;

    while(*archivo>>nuevalista[i].IDclase>>coma>>nuevalista[i].nombre>>coma>>nuevalista[i].horario){

        resize_cli(lista,n);

        (lista+i)->iDclase=nuevalista->iDclase;
        (lista+i)->nombre=nuevalista->nombre;
        (lista+i)->horario=nuevalista->horario;
        i++;
    }
    delete[]lista ;
    return nuevalista;
}

bool EscribirArchivoClases(ofstream* archivo,sClases* lista,int N)
{
    if(!archivo->is_open())
        return false;

    char coma=',';
    string header;

    //getline(archivo, header);

    if(header=="")
        *archivo<<"iDclase"<<coma<<"nombre"<<coma<<"horario"<<endl;


    for(int i=0;i<N;i++){
        *archivo<<lista[i].IDclase<<coma<<lista[i].nombre<<coma<<lista[i].horario<<endl;

    }
    return true;
}


bool leerasistencia(ifstream* archiasist,sAsistencia* cupo){
    if(!archiasist->is_open())
        return false;


    archiasist->read((char*)cupo, sizeof(sAsistencia));

    return true;

}

bool binariolista(ifstream archi) {
    if (!archi->is_open())
        return false;

    int cantLineas = 0;
    string linea;

    while (getline(archi, linea)) {
        cantLineas++;
    }

    sAsistencia lineasArray = new sAsistencia[cantLineas];

    for (int i = 0; i < cantLineas; ++i) {
        getline(*archi, lineasArray[i]);
    }

    return true;
}//el delete se hace en el main despues de dejar de usar la variable;


bool escribirasistencia(ofstream* archiasist,sAsistencia* cupo){

    if(!archiasist->is_open())
        return false;


    archiasist->write((char*)cupo,sizeof(sAsistencia));
    return true;
}


//funcion para musculito
time_t fechaInscripcion(){

    srand(time(0));

    time_t fechaInscripcion;
    tm *ltm;

    do{
        time_t now = time(0);
        tm *ltm = localtime(&now);



        // Generar una hora aleatoria entre 8:00 AM y 8:00 PM
        ltm->tm_hour = rand() % 12 + 8;  // Hora entre 8 y 19
        ltm->tm_min = rand() % 60;       // Minuto entre 0 y 59
        ltm->tm_sec = rand() % 60;       // Segundo entre 0 y 59

        // Convertir la estructura tm a time_t
        time_t fechaInscripcion = mktime(ltm);

    }while (ltm->tm_wday < 1 || ltm->tm_wday > 5);

    return fechaInscripcion;
}



void InscripcionMusculito()
{
    //bool para chequear en el main si es que la persona tiene un id generado o no
    cout<<"Ingrese su nombre:"<<endl;
    cin>>sClientes.nombre;
    cout<<"Ingrese su apellido:"<<endl;
    cin>>sClientes.apellido;
    cout<<"Ingrese su mail:"<<endl;
    cin>>sClientes.mail;
   cout<<"Ingrese su telefono:"<<endl;
   cin>>sClientes.numero_telefono;
   cout<<"Ingrese su año de nacimiento:"<<endl;
    cin>>sClientes.fecha_nac.anio;
   cout<<"Ingrese su mes de nacimiento:"<<endl;
   cin>>sClientes.fecha_nac.mes;
   cout<<"Ingrese su dia de nacimiento:"<<endl;
   cin>>sClientes.fecha_nac.dia;
  //Habria que generarle el ID al cliente y el estado del pago deberiamos de encargarnos nosotros tambien, osea agregarlo a una lista asi el id del cliente sigue el orden y devolver esos datos
}

void reserva(string id_clase, sAsistencia*listaasis){
  int cupmax=0;

    if(id_clase>=1 && id_clase<=5){
        cupmax=45;
        verificar_cupos(listaasis, cupmax, id_clase);
    }

    else if(id_clase>5 && id_clase<12){
         cupmax=25;
         verificar_cupos(listaasis, cupmax, id_clase);

    }

    else if(id_clase>11 && id_clase<18){
        cupmax=15;
        verificar_cupos(listaasis, cupmax, id_clase);

    }

    else if(id_clase>17 && id_clase<24){
         cupmax=40;
         verificar_cupos(listaasis, cupmax, id_clase);

    }

    else if(id_clase>23 && id_clase<30){
         cupmax=50;
         verificar_cupos(listaasis, cupmax, id_clase);

    }

    else if(id_clase>29 && id_clase<34){
       cupmax=30;
       verificar_cupos(listaasis, cupmax, id_clase);

    }

    else if(id_clase>33 && id_clase<61){
        cupmax=30;
        verificar_cupos(listaasis, cupmax, id_clase);
    }

}

void verificar_cupos(sAsistencia* list, string cupos_tot, string id){

    int j=0;

    for(int i=0; i<sizeof(list); i++){

        list->CursosInscriptos->iDCurso[i]=id;
        j=i;
    }



    if(list->cantInscriptos[j]<cupos_tot){
        (list->cantInscriptos[j])+=1;
        return true;
    }
    else if(){
            return false;

        }
}




//terminar el main, abrir y cerrar archivos, menu,
// testings
//como sumar los archivos al programa para poder usarlos
// fijar si hay que hacer + funciones extras a archivos
// lunes a sabados!!
