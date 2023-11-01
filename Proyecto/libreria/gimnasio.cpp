#include "gimnasio.h"
#include <fstream>
void reserva(sClientes cli, unsigned int IDclase)
{

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




