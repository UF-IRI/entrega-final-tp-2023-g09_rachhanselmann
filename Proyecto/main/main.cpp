#include <iostream>
#include <string>
#include <fstream>

#include "gimnasio.h"
#include "clientes.h"
#include "funciones.h"

using namespace std;


int main() {

    ifstream archiClase;
    archiClase.open("iriClasesGYM.csv");
    int ncla=-1;
    sClases* listacla1=new sClases[ncla];
    LeerArchivoClasesaLista(&archiClase, listacla1, ncla);
    archiClase.close();
    delete[] listacla1;

    ifstream archiCli;
    archiCli.open("iriClientesGYM.csv");
    int ncli=-1;
    sClientes* listacli1=new sClientes[ncli];
    ClienteLista(&archiCli, listacli1, ncli);
    archiCli.close();
    delete[] listacli1;

    ifstream archiAsis;
    archiAsis.open("asistencias_1697673600000.dat");
    int nasi=-1;
    sAsistencia* listaasis1=new sAsistencia[nasi];
    //falta resize
    binariolista(&archiAsis);
    archiAsis.close();
    delete[] listaasis1;

    int n=-1;
    sCupos* cuponuevo=new sCupos[n];// N WHAT?

    ofstream Asistencia;
    bool resul=EscribirAsistencia(&Asistencia,cuponuevo);
    cout<<resul;
    Asistencia.close();
    delete[] listaasis1;



    int opcion=0;


    sAsistencia* listanuevaasis= new sAsistencia[n]; //N WHAT??


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


    listanuevaasis=eliminarrepetidos(listanuevaasis, n);

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

