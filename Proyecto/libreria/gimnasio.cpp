#include "gimnasio.h"
#include <fstream>

void reserva(sClientes cli, unsigned int IDclase)
{

}

bool CrearlistaClases(ifstream* archi, sClases* cla)
{

    if(!(archi->is_open()))//chequeo que el archivo este abierto
        return false;

    if(archi==nullptr)//chequeo que el archivo no este vacio
        return false;

    string encabezado;

    getline(*archi, encabezado);

    string auxID;
    string auxnombre;
    time_t auxhorario;
    char coma;
   // stringstream ss; solo para string por eso es una fiaca para cuando tenemos distintos tipos de datos



    while(*archi)
    {
        //clases>>dummy>>coma>>dummy>>coma>>dummy>>coma>>endl;
    }

    return true;

}

void guardarClase(fstream& archivo, sGimnasio gym)
{
    string aux;
    if (archivo.is_open())
    {
        getline(archivo, aux);

        if (aux == "\0") //si en la primer linea no hay nada,tengo que poner el encabezad
        {
            archivo <<"idClase"<<","<<"nombre"<<","<<"horario"<< endl;
        }
        else
        {
            archivo << gym.IDcurso << ',' << gym.clase << ',' << gym.horario <<endl; //todo preguntar
        }

    }
}



