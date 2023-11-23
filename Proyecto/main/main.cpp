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
    sClases*listacla1=new sClases[ncla];
    sClases* resul1=LeerArchivoClasesaLista(*archiClase, listacla1, ncla);
    archiClase.close();
    delete[] listacla1;

    ifstream archiCli;
    archiCli.open("iriClientesGYM.csv");
    int ncli=-1;
    sClientes* listacli1=new sClientes[ncli];
    sClientes* resul2=ClienteLista(*archiCli, listacli1, ncli);
    archiCli.close();
    delete[] listacli1;

    ifstream archiAsis;
    archiAsis.open("asistencias_1697673600000.dat");
    int nasi=-1;
    sAsistencia* listaasis1=new sAsistencia[nasi];
    //falta el resize
    sAsistencia* resul3=binariolista(*archiAsis);
    archiAsis.close();
    delete[] listaasis1;

    ofstream Clase;
    Clase.open("iriClasesGYM.csv");
    bool salida1=EscribirArchivoClases(&Clase, resul1, ncla);
    cout<<salida1;
    Clase.close();
    delete[] resul1;

    ofstream Clientes;
    bool salida2=EscribirArchivoClientes(&Clientes, resul2, ncli);
    cout<<salida2;
    Clientes.close();
    delete[] resul2;

    ofstream Asistencia;
    bool salida3=EscribirAsistencia(&Asistencia, resul3);
    cout<<salida3;
    Asistencia.close();
    delete[] resul3;


    int opcion=0;

    int n=-1;
    sAsistencia* listanuevaasis= new sAsistencia[n];
    sClases* listanuevacla=new sClases[n];
    sClientes* listanuevacli=new sClientes[n];
    sCupos* cuponuevo=new sCupos[1];

    sInscripcion* insc=new sInscripcion{11, {23, 4, 323, 20}};
    sAsistencia* nuevocli= new sAsistencia{6, 10, {insc}};
    sInscripcion inscrip={12, {23, 4, 322, 23}};
    sAsistencia asist={7, 11, {inscrip}};





    MenuPrincipal();

    do {
        cout<<"Ingrese la opcion que desea del menu principal:"<<endl;
        cin>>opcion;

        switch(opcion)
        {
        case (1):
        {
            system("cls");
            string IDpersona= InscripcionMusculito(resul2, ncli);
            cout<<"Se ha registrado con exito. Su ID generado es:"<<IDpersona<<endl;
            break;
        }

        case (2):
        {
            system("cls");
//sAsistencia nuevocliente, sAsistencia*listaasis, int &n,sClases*clases,sCupos* cups
            bool res=reserva(asist, listanuevaasis, n, listanuevacla, cuponuevo);
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




    return 0;
}

