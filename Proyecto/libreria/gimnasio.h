#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <string>
#include <iostream>
#include <ctime>
#include "clientes.h"
using namespace std;

#define cupos_total_gym 30;



struct gym{
    unsigned int IDcurso;
    time_t FechaInsc;
    sClientes* misclientes;
    string clase;
    time_t horario;
    int cupos_tot_clases;
    int cupos_act_clases;

};

typedef struct gym sGimnasio;






//funciones para las clases
void reserva(sClientes cli, unsigned int IDclase);
void cancelacion(sClientes cli, Class claseelegida);
void cambiosenreserva(sClientes cli, Class clasevieja, Class clasenueva);




#endif // GIMNASIO_H
