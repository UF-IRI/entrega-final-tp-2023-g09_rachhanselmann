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


void ClienteLista(ifstream *&archicli,sClientes*lista,int &n ){

    if(!archicli->is_open() || lista==nullptr)
        return;

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
    //delete[]lista ;

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


void LeerArchivoClasesaLista(ifstream* archivo,sClases *lista,int &n)
{
    if(!archivo->is_open() || lista==nullptr)
        return;

    sClases* nuevalista= new sClases[n];
    char coma=',';
    int i=0;
//no crar nueva lista, llenar esa que pasaron y que se edite dentro de la funcion, funcion void.
    while(*archivo>>nuevalista[i].IDclase>>coma>>nuevalista[i].nombre>>coma>>nuevalista[i].horario){

        resize_clase(lista,n);

        (lista+i)->IDclase=nuevalista->IDclase;
        (lista+i)->nombre=nuevalista->nombre;
        (lista+i)->horario=nuevalista->horario;
        i++;
    }
    delete[]nuevalista;

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

void LeerAsistencia(ifstream* archiasist,sAsistencia* lista,int &n){
    if(!archiasist->is_open())
        return ;
    resize_asis(lista, n);

    for (int i=0;i<n;i++){

    archiasist->read((char*)&lista[i], sizeof(sAsistencia));

    }
    return;

}

//void binariolista(ifstream*archi,sAsistencia*lista) {
//    if (!archi->is_open())
//        return;

//    int cantLineas = 0;
//    string linea;
//    int i=0;
//    while (getline(*archi, linea)) {
//        //cantLineas=linea[i];

//        cantLineas++;
//        i++;
//    }

//    sAsistencia* lineasArray = new sAsistencia[cantLineas];
//    string coma=",";
//    for (int i = 0; i < cantLineas; ++i) {

//        getline(*archi, &lineasArray[i]);
//        lista[i]=lineasArray[i];



//    }

//}//el delete se hace en el main despues de dejar de usar la variable;


bool EscribirAsistencia(ofstream* archiasist,sAsistencia* cupo){

    if(!archiasist->is_open())
        return false;


    archiasist->write((char*)cupo,sizeof(sAsistencia));
    return true;
}

bool EscribirAsismañana(ofstream* archi, sAsistencia* asis)
{
    //ofstream archi("archivo_nuevo.dat");

    if(!archi->is_open())
        return false;


     for (int i=0; i<asis->cantInscriptos; i++) {//DECIA CANTASISTENCIAS no sabemos a que se refiere a cant del array o cantinscriptos por curso

        archi->write((char*)&asis[i].iDCliente, sizeof(int));
        archi->write((char*)&asis[i].cantInscriptos, sizeof(int));


              for(unsigned int j = 0; j < asis[i].cantInscriptos; j++)
              {
                archi->write((char*)&asis[i].CursosInscriptos[j],sizeof(sInscripcion));
              }
     }

    archi->close();
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





    sClientes ultimaLinea=lista[n];
    int ultlin=stoi(ultimaLinea.iD);
    ultlin+=1;
    int posCliente=ultlin;

    string PosCli=to_string(posCliente);
    nuevoCliente.iD=PosCli;
    resize_cli(lista, n);//agrandamos la lista para que entre el nuevo cliente
    lista[n]=nuevoCliente;

    return PosCli;

}
bool verificar_cupos(sAsistencia* list,sClases* clases, sCupos*cupotot){//, sAsistencia asis

    unsigned int j=0;
    //sAsistencia nuevoInscripto;

    for(unsigned int i=0; i<sizeof(list); i++){

       if(list[i].CursosInscriptos->iDCurso ==clases->IDclase)
        {
           j=i;
        }

    }

    if(list[j].cantInscriptos < cupotot->cupos_tot){

       // (*list->cantInscriptos[j])+=1;

        return true;
    }

    return false;
}

bool reserva(sAsistencia nuevocliente, sAsistencia*listaasis, int &n, sClases*clases, sCupos* cups){

    bool resul=false;

    if(nuevocliente.CursosInscriptos->iDCurso>=1 && nuevocliente.CursosInscriptos->iDCurso<=5){
        cups->cupos_tot=45;
        resul=verificar_cupos(listaasis,clases,cups);
    }

    else if(nuevocliente.CursosInscriptos->iDCurso>5 && nuevocliente.CursosInscriptos->iDCurso<12){
         cups->cupos_tot=25;
        resul=verificar_cupos(listaasis,clases,cups);
    }

    else if(nuevocliente.CursosInscriptos->iDCurso>11 && nuevocliente.CursosInscriptos->iDCurso<18){
        cups->cupos_tot=15;
        resul=verificar_cupos(listaasis,clases,cups);

    }

    else if(nuevocliente.CursosInscriptos->iDCurso>17 && nuevocliente.CursosInscriptos->iDCurso<24){
        cups->cupos_tot=40;
         resul=verificar_cupos(listaasis,clases,cups);

    }

    else if(nuevocliente.CursosInscriptos->iDCurso>23 && nuevocliente.CursosInscriptos->iDCurso<30){
         cups->cupos_tot=50;
         resul=verificar_cupos(listaasis,clases,cups);

    }

    else if(nuevocliente.CursosInscriptos->iDCurso>29 && nuevocliente.CursosInscriptos->iDCurso<34){
       cups->cupos_tot=30;
       resul=verificar_cupos(listaasis,clases,cups);

    }

    else if(nuevocliente.CursosInscriptos->iDCurso>33 && nuevocliente.CursosInscriptos->iDCurso<61){
        cups->cupos_tot=30;
        resul=verificar_cupos(listaasis,clases,cups);
    }



    if(resul==true)
    {
        resize_asis(listaasis, n);
        listaasis[n]=nuevocliente;
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


