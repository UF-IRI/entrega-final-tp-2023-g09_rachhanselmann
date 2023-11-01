#include "clientes.h"
#include <fstream>

const sClientes ClienteVacio={" "," ","",0,0,0,0,true,0};

void guardarcli(fstream &Archivo,sClientes cli)
{
    string aux;

    if (Archivo.is_open())
    {
        getline(Archivo, aux);

        if (aux == "\0") //si en la primer linea no hay nada,tengo que poner el encabezad
        {
            Archivo <<"iD"<<","<<"nombre"<<","<<"apellido"<<","<<"email"<<","<<"numero de telefono"<<","<<"fecha nacimiento"<<","<<"estado"<< endl;
        }
        else
        {
            Archivo <<cli.iD<<","<<cli.nombre<<","<<cli.apellido<<","<<cli.mail<<","<<cli.numero_telefono<<","<<cli.fecha_nac<<","<<cli.membresia<< endl; //todo preguntar
        }
    }

}
