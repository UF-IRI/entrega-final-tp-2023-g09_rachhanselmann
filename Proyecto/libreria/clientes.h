#ifndef CLIENTES_H
#define CLIENTES_H
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

struct FechaNac{
    int dia;
    int mes;
    int anio;
};typedef struct FechaNac fecha_nac;

struct Cliente{
    string iD, nombre, apellido, mail;
    unsigned int numero_telefono;
    FechaNac fecha_nac;
    int estado; // 0=todo pago, positivo= dinero a favor, negativo=debe dinero
};
typedef struct Cliente sClientes;

//void guardarcliente(fstream &Archivo,sClientes cli);

#endif // CLIENTES_H
