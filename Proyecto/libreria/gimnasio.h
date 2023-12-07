#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <string>
#include <iostream>
#include <ctime>

#include <fstream>
using namespace std;

#define cupos_total_gym 30;





struct Clases{

    unsigned int IDclase;
    string nombre;
    string horario;

}; typedef struct Clases sClases;

//structs para archivos binarios
struct fecha{
    tm dia;
    tm mes;
    tm anio;
    tm min;
};typedef struct fecha sFecha;

struct inscripcion{
    unsigned int iDCurso;
    sFecha fecha_insc;

};typedef struct inscripcion sInscripcion;


struct asistencia{
    unsigned int iDCliente, cantInscriptos;
    sInscripcion*CursosInscriptos;

};typedef asistencia sAsistencia;


struct cupos{
  unsigned int cupos_tot;
};typedef struct cupos sCupos;


#endif // GIMNASIO_H
