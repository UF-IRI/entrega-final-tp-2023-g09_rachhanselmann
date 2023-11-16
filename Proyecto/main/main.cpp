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
    sClases* resul1=LeerArchivoClasesaLista(archiClase, listacla1, ncla);
    archiClase.close();
    delete[] listacla1;
    cout<<resul1;

    ifstream archiCli;
    archiCli.open("iriClientesGYM.csv");
    int ncli=-1;
    sClientes* listacli1=new sClientes[ncli];
    sClientes*resul2=ClienteLista(archiCli, listacli1, ncli);
    archiCli.close();
    //delete[] listacli1;
    //cout<<resul2;


    ifstream archiAsis;
    archiAsis.open("asistencias_1697673600000.dat");
    int nasi=-1;
    sAsistencias*listaasis1=new sAsistencias[nasi];
    //falta el resize
    bool resul3=leerasistencia(&archiAsis, listaasis1, nasi);
    archiAsis.close();
    delete[] listaasis1;
    cout<<resul3;


    //bool verificar_cupos(sAsistencia* list, string cupos_tot, string id)


    int opcion=0;
    int id_cli=0;
    MenuPrincipal();

    do{
        cout<<"Ingrese la opcion que desea del menu principal:"<<endl;
        cin>>opcion;

        switch(opcion)
        {
        case (1):
            system("cls");
            int IDpersona= InscripcionMusculito(listacli1, ncli);
            cout<<"Se ha registrado con exito. Su ID generado es:"<<IDpersona<<endl;
            break;

        case (2):
            system("cls");
            cout<<"Ingrese su Id:"<<endl;
            cin>>id_cli;
            bool res=reserva(id_cli, listaasis1);
            if(res==true)
            {
                cout<<"La reserva se ha realizado con exito."<<endl;
            }
            else if()
            {
                cout<<"Hubo un error. Es posible que no haya cupos."<<endl;
            }
            break;

        }
    }while(opcion!=0);




    ofstream Clase;
    Clase.open("iriClasesGYM.csv");
    //sClases* listaclases=EscribirArchivoClases();
    //hay que pasarle la lista final que cerramos en el dia de hoy para sobreescribirla en el archivo de hoy
    //bool resul4=EscribirArchivoClientes(Clase, listausada, n);
    Clase.close();
    //delete donde sea necesario para la lista usada


    ofstream Clientes;

    ofstream Asistencia;



    return 0;
}
