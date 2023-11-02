#include "gimnasio.h"
#include <fstream>

void reserva(sClientes cli, unsigned int IDclase)
{

}

bool CrearlistaClases(fstream*& clases, n)
{
    //fstream archi;
    //archi.open(name, ios::in);

    if(!(clases.is_open()))//chequeo que el archivo este abierto
        return false;

    if(clases==nullptr)//chequeo que el archivo no este vacio
        return false;

    fstream* nuevo=new clases[n];//creando una lista dinamica

    fstream aux;
    char coma;
    string dummy;

    clases>>dummy>>coma>>dummy>>coma>>dummy>>coma>>endl;

    while(clases)
    {
        //clases>>aux.
        //funcion de añadir
    }


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




