#include <catch2/catch.hpp>
#include "funciones.h"
#include "gimnasio.h"
#include "clientes.h"

//TEST_CASE("Resize de lista de clientes") {
//    int n = 5;
//    sClientes* lista = new sClientes[n];

//    SECTION("Verificar tamaño después del resize") {
//    resize_cli(lista, n);

//    REQUIRE(n == 6);
//    }
//}//deberia hacerse lo mismo con todos los resize




////TEST_CASE("Abrir archivo en modo lectura"){

////    sClases*lista=new sClases[1];
////    lista[0]={"6","spinning","8"};

////    ifstream inputFile("iriClasesGYM.csv");
////    int n=1;
////    sClases*cla=LeerArchivoClasesaLista(*inputFile, lista, n);

////    REQUIRE(LeerArchivoClasesaLista(cla[0], lista[0], n)=={"6","spinning","8"});
////}




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
