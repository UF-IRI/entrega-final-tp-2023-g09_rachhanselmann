#include <catch2/catch.hpp>
#include "funciones.h"

#include <sstream>

TEST_CASE("Resize de lista de clientes") {
    int n = 5;
    sClientes* lista = new sClientes[n];

    SECTION("Verificar tamaño después del resize") {
    resize_cli(lista, n);

    // Verificar que el tamaño de la lista ha aumentado a 6
    REQUIRE(n == 6);
    delete[] lista;
}
}

TEST_CASE("Resize de lista de clases") {
int n = 6;
sClases* lista = new sClases[n];

SECTION("Verificar tamaño después del resize") {
resize_clase(lista, n);

// Verificar que el tamaño de la lista ha aumentado a 6
REQUIRE(n == 7);
}
}

TEST_CASE("Resize de lista de asistencias") {
int n = 5;
sAsistencia* lista = new sAsistencia[n];

SECTION("Verificar tamaño después del resize") {
resize_asis(lista, n);

// Verificar que el tamaño de la lista ha aumentado a 6
REQUIRE(n == 6);
    }
}

TEST_CASE("Verificar cupos de asistencia") {
    // Crear datos de prueba
    sCupos *cupotot = new sCupos{45};  // Ajusta el número de cupos según tus necesidades
    sClases *clases = new sClases{1,"Zumba","12"};   // Ajusta el ID de clase según tus necesidades
    sInscripcion*insc=new sInscripcion{1,{12,3,2008,10}};
    sAsistencia* list = new sAsistencia{1,8,{insc}};  // Ajusta el tamaño del array según tus necesidades

    SECTION("Verificar cupos") {
bool result = verificar_cupos(list, clases, *cupotot);
REQUIRE(clases->IDclase==list->CursosInscriptos->iDCurso);
// Verificar que el resultado es verdadero ya que hay espacio disponible
REQUIRE(result==true);
    }
    delete cupotot;
    delete clases;
    delete insc;
    delete list;
}



TEST_CASE("Reservar cupos") {

    sInscripcion*insc=new sInscripcion[2];
    insc[0]={2, {23,4,2023,45}};
    insc[1]={5, {18,11,2023,51}};
    insc[2]={8, {3,9,2023,30}};

    sAsistencia*asis=new sAsistencia[2];
    asis[0]={1, 8, {insc}};  // Inicializa tu lista de asistencias
    asis[1]={2, 4, {insc}};
    asis[2]={3, 15, {insc}};

    int n = 3;   // Inicializa la cantidad de elementos en la lista

    sClases*clases=new sClases{2, "Spinning", "10:00"};  // Inicializa tus clases
    sCupos*cups=new sCupos{45};  // Inicializa tus cupos

    sInscripcion in={7, {26,5,2022,34}};
    sAsistencia NuevoCli={4, 23, {in}};

  REQUIRE(reserva(NuevoCli, asis, n, &clases, &cups)==true);

    delete insc;
    delete asis;
    delete clases;
    delete cups;

}

TEST_CASE("Escribir archivo de clientes") {
    // Crear datos de prueba

    sClientes*listaClientes = new sClientes[3];
    FechaNac*fechita=new FechaNac[3];
    fechita[0]={1,2,1990};
    fechita[1]={15,8,1985};
    fechita[3]={10,12,2003};

    listaClientes[0]= {93, "Juan", "Perez", "juan@gmail.com", "123456789", fechita[0].dia,fechita[0].mes,fechita[2].anio, 1};
    listaClientes[1]= {25, "Maria", "Lopez", "maria@gmail.com", "987654321", {15, 8, 1985}, 0};
    listaClientes[2]= {36, "Carlos", "Gonzalez", "carlos@gmail.com", "555555555", {10, 12, 2000}, 1};

    int N = 3;

    ofstream archi;
    archi.open("");
    stringstream ss;

    // Llamar a la función EscribirArchivoClientes
    bool resultado = EscribirArchivoClientes(&archi, listaClientes, N);

    SECTION("Verificar que la escritura fue exitosa") {
REQUIRE(resultado == true);
    }
//    SECTION("Verificar que la primer linea es el encabezado"){
//        REQUIRE();

//    }
//    SECTION("Verificar datos ingresados correctos"){
//        REQUIRE();

//    }
}

TEST_CASE("Pasar de cliente a lista") {


    stringstream ss;

    ss <<"44123456,Martina,Gomez,martugomez1@gmail.com, 1143456776, 11,5,2003,-2000"<<endl;
    ss << "45678901,Bautista,Gonzalez,bauti123@hotmail.com, 1156745678, 22,8,2004,0"<<endl;
    ss << "45876543,Delfina,Sanchez,delfi_sanchez@gmail.com,1123344556, 5,10,2004,3500"<<endl;

    ifstream archicli_stream(ss.str());
    // Creamos una lista vacía de clientes
    sClientes* lista = nullptr;
    int n = 0;

    ClienteLista(&archicli_stream, lista, n);

    // Verificamos el tamaño de la lista
    REQUIRE(n == 3);

    // Verificamos elementos de la lista
    SECTION("Elemento 1:"){

REQUIRE(lista[0].iD == "44123456");
REQUIRE(lista[0].nombre == "Martina");
REQUIRE(lista[0].apellido == "Gomez");
REQUIRE(lista[0].mail == "martugomez1@gmail.com");
REQUIRE(lista[0].numero_telefono==1143456776);
REQUIRE(lista[0].fecha_nac->dia == 11);
REQUIRE(lista[0].fecha_nac->mes==5);
REQUIRE(lista[0].fecha_nac->anio==2003);
REQUIRE(lista[0].estado == -2000);

    }

    SECTION("Elemento 2:"){

REQUIRE(lista[1].iD == "45678901");
REQUIRE(lista[1].nombre == "Bautista");
REQUIRE(lista[1].apellido == "Gonzalez");
REQUIRE(lista[1].mail == "bauti123@hotmail.com");
REQUIRE(lista[1].numero_telefono==1156745678);
REQUIRE(lista[1].fecha_nac->dia == 22);
REQUIRE(lista[1].fecha_nac->mes==8);
REQUIRE(lista[1].fecha_nac->anio==2004);
REQUIRE(lista[1].estado == 0);
    }

    SECTION("Elemento 3:"){

REQUIRE(lista[2].iD == "45876543");
REQUIRE(lista[2].nombre == "Delfina");
REQUIRE(lista[2].apellido == "Sanchez");
REQUIRE(lista[2].mail == "delfi_sanchez@gmail.com");
REQUIRE(lista[2].numero_telefono==1123344556);
REQUIRE(lista[2].fecha_nac->dia == 5);
REQUIRE(lista[2].fecha_nac->mes==10);
REQUIRE(lista[2].fecha_nac->anio==2004);
REQUIRE(lista[2].estado == 3500);


    }


    delete[] lista;
}

















//TEST_CASE("Abrir archivo en modo lectura"){

//    sClases*lista=new sClases[1];
//    lista[0]={"6","spinning","8"};

//    ifstream inputFile("iriClasesGYM.csv");
//    int n=1;
//    sClases*cla=LeerArchivoClasesaLista(*inputFile, lista, n);

//    REQUIRE(LeerArchivoClasesaLista(cla[0], lista[0], n)=={"6","spinning","8"});
//}




//TEST_CASE("Verificar cupos de asistencia") {

//    unsigned int cuposTotales = 30;
//    sAsistencia listaAsis[14];

//    sAsistencia asisActual;
//    asisActual.iDCliente = 123;
//    asisActual.cantInscriptos = 14;

//    SECTION("Cupos disponibles") {

//    REQUIRE(verificar_cupos(listaAsis, cuposTotales, asisActual) == true);
//    }

//    SECTION("Cupos llenos") {

//    for (int i = 0; i < sizeof(listaAsis)/sizeof(listaAsis[0]); i++) {
//        listaAsis[i].cantInscriptos = cuposTotales;
//    }

//    REQUIRE(verificar_cupos(listaAsis, cuposTotales, asisActual) == false);
//    }
//}


TEST_CASE("Eliminar repetidos de la lista de asistencia") {

    sInscripcion* curso0 =new sInscripcion {1, {23, 5, 323, 20}};
    sInscripcion* curso1 =new sInscripcion {2, {21, 9, 321, 40}};
    sInscripcion* curso2 =new sInscripcion {3, {4, 1, 320, 37}};

    sAsistencia*listaAsistencia=new sAsistencia[4];
    listaAsistencia[0]={123,1, {curso0}};
    listaAsistencia[1]= {456, 2, {curso1}};
    listaAsistencia[2]= {789, 3, {curso2}};
    listaAsistencia[3]={123, 1, {curso0}};  // Repetido

    int n = 4;

    sAsistencia* listaSinRepetidos = eliminarrepetidos(listaAsistencia, n);

    SECTION("Verifica que los repetidos fueron eliminados") {

    REQUIRE(n==3);
    }
}

