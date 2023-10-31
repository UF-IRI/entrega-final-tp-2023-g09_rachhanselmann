#include "gimnasio.h"

void reserva(sClientes cli, unsigned int IDclase)
{

}
void guardararchivo(fstream& archivo, sClientes cli)
{
    string aux;
    if (archivo.is_open())
    {
        getline(archivo, aux);

        if (aux == "\0") //si en la primer linea no hay nada,tengo que poner el encabezad
        {
            archivo << "Dni" << ',' << "Nombre" << ',' << "Apellido" << ',' << "Sexo" << ',' << "Natalicio" << ',' << "Estado" << ',' << "id" << endl;
        }
        else
        {
            archivo << pac.nombre << ',' << pac.apellido << ',' << pac.sexo << ',' << pac.nacimiento.fecha.tm_mday << '/' << pac.nacimiento.fecha.tm_mon << '/' << pac.nacimiento.fecha.tm_year << '/' << pac.estado << ',' << pac.dni << endl; //todo preguntar
        }

    }


    void guardararchivo(fstream &Archivo,sClientes cli)
    {
        string aux;
        char coma = ',';
        if (Archivo.is_open())
        {
            getline(Archivo, aux);

            if (aux == "\0") //si en la primer linea no hay nada,tengo que poner el encabezad
            {
                Archivo << "Dni" << coma << "telefono" << coma << "celular" << coma << "direccion" << coma << "mail" << endl;
            }
            else
            {
                Archivo << Contacto.dni_pac << coma << Contacto.telefono << coma << Contacto.celular << coma << Contacto.direccion << coma << Contacto.email << endl; //todo preguntar
            }
        }

    }


