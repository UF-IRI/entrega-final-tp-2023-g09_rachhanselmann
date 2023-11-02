#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
    ofstream arch_clase;
    ifstream arch_clientes;
    ofstream arch_asistencias;

    //idClase,nombre,horario (archivo clases)
    //idCliente,cantInscriptos,{Inscripción(idCurso, fechaInscripción)}   (archivo clientes) {} significa que es un array


   arch_clase.open("iriClasesGYM");
   arch_clientes.open("iriClientesGYM");
   arch_asistencias.open("asistencias_1697673600000");



   if (arch_clase.is_open()) {
       arch_clase << "Datos de clases" << endl;

   } else {
       cerr << "No se pudo abrir el archivo de clases." << endl;
   }

  //lectura del archivo

   if (arch_clientes.is_open()) {
      string linea;

       while( getline(arch_clientes&linea)){
           cout << linea << endl; // Muestra cada línea del archivo
       }

   } else {
       cerr << "No se pudo abrir el archivo de clientes." << endl;
   }

   ofstream archibinwr("asistencias_1697673600000.dat", ios::binary);

   if (archibinwr.is_open()) {
       archibinwr.write((char*)&Asistencias[i].idCliente, sizeof(uint));
       archibinwr.write((char*)&Asistencias[i].cantInscriptos, sizeof(uint));
       archibinwr.write((char*)&Asistencias[i].cantInscriptos, sizeof(uint));
       for(uint j = 0; j < Asistencias[i].cantInscriptos; j++) {
           archibinwr.write((char*)&Asistencias[i].CursosInscriptos[j],

        sizeof(Inscripcion));
       }
   }
}
archibinwr.close();



    
    return 0;
}
