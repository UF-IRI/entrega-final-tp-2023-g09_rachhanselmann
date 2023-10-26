#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <string>
#include <iostream>
using namespace std;


enum tipo{Spinning, Yoga, Pilates, Stretching, Zumba,  Boxeo};
typedef enum tipo Class;
struct Clase{
    Class tipo;
    string salas;
    int horarioComienzo;//se puede usar c time
    int cupos_tot;
    int cupos_act;



};

typedef struct Clase sClase;

//#define cupos_total 30;

struct Musculacion{
    float horarioComienzo;//se puede usar c time
    int cupos_total;
    int cupos_act;


};

//#define cupos_total 30;

#endif // GIMNASIO_H
