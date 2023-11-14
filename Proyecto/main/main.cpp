#include <iostream>
#include <string>
#include <fstream>

//#include "gimnasio.h"
#include "clientes.h"
#include "funciones.h"

using namespace std;


int main() {

    ifstream archiClase;

    archiClase.open("iriClasesGYM.csv");

    int n=-1;

    sClientes*lista1=new sClientes[n];

    bool resul=LeerArchivoClientes(archiClase, lista1, n);

    archiClase.close();

    delete[] lista1;
    cout<<resul;

    ifstream archiCli;
    ifstream archiAsis;
    ofstream Clase;
    ofstream Clientes;
    ofstream Asistencia;




    return 0;
}
