#include <catch2/catch.hpp>
#include "funciones.h"
#include "gimnasio.h"
#include "clientes.h"


TEST_CASE("Resize de lista de clientes") {
    int n = 5;
    sClientes* lista = new sClientes[n];

    SECTION("Verificar tamaño después del resize") {
    resize_cli(lista, n);

    // Verificar que el tamaño de la lista ha aumentado a 6
    REQUIRE(n == 6);

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


//TEST_CASE("Eliminar repetidos de la lista de asistencia") {

//    sInscripcion curso1 = {1, {23, 5, 323, 20}};
//    sInscripcion curso2 = {2, {21, 9, 321, 40}};
//    sInscripcion curso3 = {3, {4, 1, 320, 37}};

//    sAsistencia listaAsistencia[0] = {123 1, &curso1};
//    sAsistencia listaAsistencia[1]= {456, 2, &curso2};
//    sAsistencia listaAsistencia[2]= {789, 3, &curso3};
//    sAsistencia listaAsistencia[3]= {123, 1, &curso1};  // Repetido

//    int n = 4;

//    sAsistencia* listaSinRepetidos = eliminarrepetidos(listaAsistencia, n);

//    SECTION("Verifica que los repetidos fueron eliminados") {

//    REQUIRE(n == 3);


//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            REQUIRE((listaSinRepetidos[i].iDCliente != listaSinRepetidos[j].iDCliente) || (listaSinRepetidos[i].CursosInscriptos->iDCurso != listaSinRepetidos[j].CursosInscriptos->iDCurso));
//        }
//    }
//    }
//}
