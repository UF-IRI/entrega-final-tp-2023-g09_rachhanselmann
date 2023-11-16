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

    while(*archicli>>nuevalista[i].iD>>coma>>nuevalista[i].nombre>>coma>>nuevalista[i].apellido>>coma>>nuevalista[i].mail>>coma>>nuevalista[i].fecha_nac.dia>>nuevalista[i].fecha_nac.mes>>nuevalista[i].fecha_nac.anio>>coma>>nuevalista[i].estado){

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
        *archicli<<listacli[i].iD<<coma<<listacli[i].nombre<<coma<<listacli[i].apellido<<coma<<listacli[i].mail<<coma<<listacli[i].numero_telefono<<coma<<listacli[i].fecha_nac.dia<<listacli[i].fecha_nac.mes<<listacli[i].fecha_nac.anio<<coma<<listacli[i].estado<<endl;

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


sClases* LeerArchivoClasesaLista(ifstream* archivo,sClases *&lista,int &n)
{
    if(!archivo->is_open() || lista==nullptr)
        return nullptr;

    sClases* nuevalista= new sClases[n];
    char coma=',';
    int i=0;

    while(*archivo>>nuevalista[i].IDclase>>coma>>nuevalista[i].nombre>>coma>>nuevalista[i].horario){

        resize_clase(lista,n);

        (lista+i)->IDclase=nuevalista->IDclase;
        (lista+i)->nombre=nuevalista->nombre;
        (lista+i)->horario=nuevalista->horario;
        i++;
    }
    delete[]lista;
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

void resize_asis(sAsistencia*& lista, int &n){
    n=(n)+1;
    sAsistencia *aux=new sAsistencia[n];
    for(int i=0;i<n-1;i++){
        aux[i]=lista[i];}
    delete[] lista;
    lista=aux;
}

bool LeerAsistencia(ifstream* archiasist,sAsistencia* cupo){
    if(!archiasist->is_open())
        return false;


    archiasist->read((char*)cupo, sizeof(sAsistencia));

    return true;

}

sAsistencia* binariolista(ifstream*archi) {
    if (!archi->is_open())
        return nullptr;

    int cantLineas = 0;
    string linea;

    while (getline(*archi, linea)) {
        cantLineas=linea[i];
    }

    sAsistencia lineasArray = new sAsistencia[cantLineas];

    for (int i = 0; i < cantLineas; ++i) {
        getline(*archi, lineasArray[i]);
    }

    return lineasArray;
}//el delete se hace en el main despues de dejar de usar la variable;


bool EscribirAsistencia(ofstream* archiasist,sAsistencia* cupo){

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

    }while (ltm->tm_wday >= 0 && ltm->tm_wday <= 5);

    return fechaInscripcion;
}



string InscripcionMusculito(sClientes*lista, int&n)
{
    sClientes nuevoCliente;

    //bool para chequear en el main si es que la persona tiene un id generado o no
    cout<<"Ingrese su nombre:"<<endl;
    cin>>nuevoCliente.nombre;
    cout<<"Ingrese su apellido:"<<endl;
    cin>>nuevoCliente.apellido;
    cout<<"Ingrese su mail:"<<endl;
    cin>>nuevoCliente.mail;
    cout<<"Ingrese su telefono:"<<endl;
    cin>>nuevoCliente.numero_telefono;
    cout<<"Ingrese su año de nacimiento:"<<endl;
    cin>>nuevoCliente.fecha_nac.anio;
    cout<<"Ingrese su mes de nacimiento:"<<endl;
    cin>>nuevoCliente.fecha_nac.mes;
    cout<<"Ingrese su dia de nacimiento:"<<endl;
    cin>>nuevoCliente.fecha_nac.dia;

    sClientes lineaActual;
    sClientes ultimaLinea;

    while (getline(lista, lineaActual)) {
        ultimaLinea = lineaActual;
    }

    string posCliente=ultimaLinea.iD;
    posCliente+=1;
    nuevoCliente.iD=posCliente;
    nuevoCliente.estado=0; //lo igualamos a cero porque en cuanto te inscribis pagas tu primer mes

    resize_cli(lista, n);//agrandamos el array para incluir al nuevo cliente
    lista[n]=nuevoCliente;

    return posCliente;

}

bool reserva(sAsistencia nuevocliente, sAsistencia*listaasis, int &n){
    unsigned int cupmax=0;
    bool resul=false;

    if(nuevocliente.CursosInscriptos->iDCurso>=1 && nuevocliente.CursosInscriptos->iDCurso<=5){
        cupmax=45;
        resul=verificar_cupos(listaasis, cupmax, nuevocliente.CursosInscriptos->iDCurso);
    }

    else if(nuevocliente.CursosInscriptos->iDCurso>5 && nuevocliente.CursosInscriptos->iDCurso<12){
         cupmax=25;
         resul=verificar_cupos(listaasis, cupmax, nuevocliente.CursosInscriptos->iDCurso);

    }

    else if(nuevocliente.CursosInscriptos->iDCurso>11 && nuevocliente.CursosInscriptos->iDCurso<18){
        cupmax=15;
        resul=verificar_cupos(listaasis, cupmax, nuevocliente.CursosInscriptos->iDCurso);

    }

    else if(nuevocliente.CursosInscriptos->iDCurso>17 && nuevocliente.CursosInscriptos->iDCurso<24){
         cupmax=40;
         resul=verificar_cupos(listaasis, cupmax, nuevocliente.CursosInscriptos->iDCurso);

    }

    else if(nuevocliente.CursosInscriptos->iDCurso>23 && nuevocliente.CursosInscriptos->iDCurso<30){
         cupmax=50;
         resul=verificar_cupos(listaasis, cupmax, nuevocliente.CursosInscriptos->iDCurso);

    }

    else if(nuevocliente.CursosInscriptos->iDCurso>29 && nuevocliente.CursosInscriptos->iDCurso<34){
       cupmax=30;
       resul=verificar_cupos(listaasis, cupmax, nuevocliente.CursosInscriptos->iDCurso);

    }

    else if(nuevocliente.CursosInscriptos->iDCurso>33 && nuevocliente.CursosInscriptos->iDCurso<61){
        cupmax=30;
        resul=verificar_cupos(listaasis, cupmax, nuevocliente.CursosInscriptos->iDCurso);
    }



    if(resul==true)
    {
        resize_asis(listaasis, n);
        listaasis[n]=nuevocliente;
        return true;
    }


        return false;

}

bool verificar_cupos(sAsistencia* list, unsigned int cupos_tot, sAsistencia asis){

    int j=0;
    //sAsistencia nuevoInscripto;

    for(int i=0; i<sizeof(list); i++){

        list[i].CursosInscriptos->iDCurso=asis.iDCliente;
        j=i;
    }

    if(list[j].cantInscriptos<cupos_tot){
       // (*list->cantInscriptos[j])+=1;

        return true;
    }

    return false;
}

void MenuPrincipal()
{
    cout << "\n\n\t\t\tMENU PRINCIPAL" << endl;
    cout << "\t\t\t--------------" << endl;
    cout << "\t1. Inscribirme en Musculito" << endl;
    cout << "\t2. Reserva cupo clase" << endl;
    cout << "\t0. Salir"<<endl;
}

sAsistencia* eliminarrepetidos(sAsistencia* lista, int& n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j && lista[i].iDCliente == lista[j].iDCliente && lista[i].CursosInscriptos->iDCurso == lista[j].CursosInscriptos->iDCurso) {
                for (int k = i; k < n - 1; k++) {
                    lista[k] = lista[k + 1];
                }
                n--;
            }
        }
    }
    return lista;
}


