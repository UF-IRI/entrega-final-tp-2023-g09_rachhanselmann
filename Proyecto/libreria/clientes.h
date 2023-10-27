#ifndef CLIENTES_H
#define CLIENTES_H
#include <string>
#include <iostream>


using namespace std;

struct Cliente{

    string nombre, apellido;
    unsigned int iD, dni, numero_telefono;
    int estado; // 0=todo pago, positivo= dinero a favor, negativo=debe dinero
    bool membresia; //musculacion o clases

};
typedef struct Cliente sClientes;



#endif // CLIENTES_H
