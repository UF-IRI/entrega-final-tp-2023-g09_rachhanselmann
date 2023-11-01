#ifndef CLIENTES_H
#define CLIENTES_H
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

struct Cliente{

    string nombre, apellido,mail;
    unsigned int iD, dni, numero_telefono;
    int estado; // 0=todo pago, positivo= dinero a favor, negativo=debe dinero
    bool membresia; //musculacion o clases
    tm fecha_nac;
};
typedef struct Cliente sClientes;

void guardarcliente(fstream &Archivo,sClientes cli);

#endif // CLIENTES_H
