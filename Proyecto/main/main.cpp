#include <iostream>
#include <string>
#include <fstream>

//#include "gimnasio.h"
//#include "clientes.h"
#include "funciones.h"

using namespace std;


int main() {

    ifstream archiClase;
    archiClase.open("iriClasesGYM.csv", ios::in);
    int ncla=0;
    sClases* listacla1=new sClases[ncla];
    LeerArchivoClasesaLista(&archiClase, listacla1, ncla);
    archiClase.close();
    //delete[] listacla1;

    ifstream archiCli;
    archiCli.open("iriClientesGYM.csv", ios::in);
    int ncli=0;
    sClientes* listacli1=new sClientes[ncli];

    if(!archiCli.is_open())
        return -1;
    string encabezado;
    getline(archiCli,encabezado);
    char coma=',';
    string linea;



    while(getline(archiCli,linea)){
        ncli=(ncli)+1;
        sClientes*aux=new sClientes[ncli];
        for (int i=0;i<ncli-1;i++){
            aux[i]=listacli1[i];
        }
        delete[]listacli1;
        listacli1=aux;

        sClientes nuevoCliente;
        stringstream ss(linea);
        string auxnom, auxape, auxem, auxtel;
        ss>>nuevoCliente.iD>>coma;
        getline(ss,auxnom,coma);
        getline(ss,auxape,coma);
        getline(ss,auxem,coma);
        getline(ss,auxtel,coma);
        string fechnac;
        getline(ss,fechnac,coma);
//        unsigned int auxfech=stoul(fechnac);
//        nuevoCliente.fecha_nac=auxfech;
        ss>>nuevoCliente.estado>>coma;
        nuevoCliente.nombre=auxnom;
        nuevoCliente.apellido=auxape;
        nuevoCliente.mail=auxem;
        unsigned int tel= stoul(auxtel);
        nuevoCliente.numero_telefono=tel;
        listacli1[ncli-1]=nuevoCliente;

    }

//    ClienteLista(&archiCli, listacli1, ncli);
    archiCli.close();
    //delete[] listacli1;

    ifstream archiAsis;
    archiAsis.open("asistencias_1697673600000.dat", ios::binary);
    int nasi=0;
    sAsistencia* listaasis1=new sAsistencia[nasi];
    if(!archiAsis.is_open())
        return-1;
    nasi=(nasi)+1;
    sAsistencia*aux1=new sAsistencia[nasi];
    for(int i=0;i<nasi-1;i++){
        aux1[i]=listaasis1[i];
    }
    delete[]listaasis1;
    listaasis1=aux1;

    for(int i=0;i<nasi;i++){
        archiAsis.read((char*)&listaasis1[i],sizeof(sAsistencia));

    }

//    LeerAsistencia(&archiAsis, listaasis1);
    archiAsis.close();


    ofstream Asistencia;
    if(!Asistencia.is_open())
        return false;
    Asistencia.write((char*)listaasis1,sizeof(sAsistencia));

//    bool resul=EscribirAsistencia(&Asistencia, listaasis1);
    //cout<<resul;
    Asistencia.close();
    delete[] listaasis1;



    int opcion=0;
    int n=-1;
    sCupos* cuponuevo=new sCupos[n];
    sAsistencia* listanuevaasis= new sAsistencia[n];
    resize_asis(listanuevaasis, n);

    sInscripcion*inscrip=new sInscripcion{12, {23, 4, 322, 23}};
    sAsistencia*asist=new sAsistencia{7, 11, {inscrip}};

    //sInscripcion* insc=new sInscripcion{11, {23, 4, 323, 20}};
    //sAsistencia* nuevocli= new sAsistencia{6, 10, {insc}};


    MenuPrincipal();

    do {
        cout<<"Ingrese la opcion que desea del menu principal:"<<endl;
        cin>>opcion;

        switch(opcion)
        {
        case (1):
        {
            system("cls");
            string IDpersona= InscripcionMusculito(listacli1, ncli);
            cout<<"Se ha registrado con exito. Su ID generado es:"<<IDpersona<<endl;
            break;
        }

        case (2):
        {
            system("cls");

            bool res=reserva(*asist, listanuevaasis, n, listacla1, cuponuevo);
            if(res==true)
            {
                cout<<"La reserva se ha realizado con exito."<<endl;
            }
            else
            {
                cout<<"Hubo un error. Es posible que no haya cupos."<<endl;
            }
            break;
        }
        }
    }while(opcion!=0);


    eliminarrepetidos(listanuevaasis, n);

    ofstream archivoes("archivo_nuevo.dat", ios::binary);
    bool ult=EscribirAsismañana(&archivoes, listanuevaasis);
    cout<<ult;
    delete[]listanuevaasis;

    ofstream Clase;
    Clase.open("iriClasesGYM.csv");
    bool salida1=EscribirArchivoClases(&Clase, listacla1, ncla);
    cout<<salida1;
    Clase.close();
    delete[] listacla1;

    ofstream Clientes;
    bool salida2=EscribirArchivoClientes(&Clientes, listacli1, ncli);
    cout<<salida2;
    Clientes.close();
    delete[] listacli1;




    return 0;
}

