//============================================================================
// Name        : TP.cpp
// Author      : GRUPO 19
// Version     : 1.0
// Copyright   : No copyright
// Description : Generador de índices del TP de Organización de Datos (75.06)
//============================================================================

// La colección de documentos de muestra está en:
// https://docs.google.com/file/d/0B8rBD4QSqWnSdjlEa2V3YXV0WHc/edit?usp=sharing

#include <iostream>
#include <string>
#include "./Indexador.h"
#include "./RetornoCodigos.h"

int main(/*int argc, char *argv[]*/) {
  int retornoValor = ERROR;
  /*if (argc != 3) {
   std::cout << "ERROR EN LA CANTIDAD DE ARGUMENTOS." << std::endl;
   retornoValor = ERROR_ARGC;
   std::cout << "FÍN DE PROGRAMA CONTROLADO, ECHO $? = " << retornoValor << std::endl;
   return retornoValor;
   } else {
   std::cout << "CANTIDAD DE ARGUMENTOS CORRECTA." << std::endl;
   }*/
  {
    char *argv[3];
    argv[0] = "PRUEBA";
    argv[1] = "FOOBAR";
    argv[2] = "/home/kubuntu/Documents/0Indice/test/";

    std::string indiceNombre(argv[1]);
    std::cout << "El nombre del repositorio es: " << indiceNombre << std::endl;
    std::string repositorioRuta(argv[2]);
    std::cout << "La ruta del repositorio es: " << repositorioRuta << std::endl;
    Indexador indexador(indiceNombre, repositorioRuta);
    std::string indiceRuta("./");
    indexador.indexar(indiceRuta);
  }
  retornoValor = RESULTADO_OK;
  std::cout << "FÍN DE PROGRAMA CONTROLADO, ECHO $? = " << retornoValor << std::endl;
  return retornoValor;
}
