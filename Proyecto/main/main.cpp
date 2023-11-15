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
    sClientes*listacli1=new sClientes[ncla];
    sClientes* resul1=LeerArchivoClientes(archiClase, listacli1, ncla);
    archiClase.close();
    delete[] listacli1;
    cout<<resul1;

    ifstream archiCli;

    ifstream archiAsis;
    archiAsis.open("asistencias_1697673600000.dat");
    int nasi=-1;
    sAsistencias*listaasis1=new sAsistencias[nasi];
    //falta el resize
    bool resul3=leerasistencia(&archiAsis, listaasis1, nasi);
    archiAsis.close();
    delete[] listaasis1;
    cout<<resul3;

    ofstream Clase;
    Clase.open("iriClasesGYM.csv");
    //hay que pasarle la lista final que cerramos en el dia de hoy para sobreescribirla en el archivo de hoy
    //bool resul4=EscribirArchivoClientes(Clase, listausada, n);
    Clase.close();
    //delete donde sea necesario para la lista usada


    ofstream Clientes;
    ofstream Asistencia;




    return 0;
}
