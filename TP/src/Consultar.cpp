//============================================================================
// Name        : TP.cpp
// Author      : GRUPO 19
// Version     : 1.0
// Copyright   : No copyright
// Description : Generador de índices del TP de Organización de Datos (75.06)
//============================================================================

// La colección de documentos de muestra está en:
// https://docs.google.com/file/d/0B8rBD4QSqWnSdjlEa2V3YXV0WHc/edit?usp=sharing

#include <cstring>
#include <iostream>
#include <string>
#include "./Indexador.h"
#include "./RetornoCodigos.h"

int OTROmain(int argc, char *argv[]) {
  int retornoValor = ERROR;
  if (argc < 5) {
    std::cout << "ERROR EN LA CANTIDAD DE ARGUMENTOS." << std::endl;
    retornoValor = ERROR_ARGC;
    std::cout << "FÍN DE PROGRAMA CONTROLADO, ECHO $? = " << retornoValor << std::endl;
    return retornoValor;
  }
  if (strcmp(argv[1], "-r") != 0) {
    std::cout << "ARGUMENTO INCORRECTO: " << argv[1] << std::endl;
    retornoValor = ERROR_ARGV;
    std::cout << "FÍN DE PROGRAMA CONTROLADO, ECHO $? = " << retornoValor << std::endl;
    return retornoValor;
  }
  if (strcmp(argv[3], "-q") != 0) {
    std::cout << "ARGUMENTO INCORRECTO: " << argv[3] << std::endl;
    retornoValor = ERROR_ARGV;
    std::cout << "FÍN DE PROGRAMA CONTROLADO, ECHO $? = " << retornoValor << std::endl;
    return retornoValor;
  }
  std::cout << "CANTIDAD DE ARGUMENTOS CORRECTA." << std::endl;
  std::string indiceNombre(argv[2]);
  std::cout << "El nombre del repositorio es: " << indiceNombre << std::endl;

  // TODO (): Parsear los argumentos para obtener la consulta.
  std::string consulta("*****************ACÁ VA LA CONSULTA*****************");

  std::cout << "La consulta es por: \"" << consulta << "\"" << std::endl;
  std::string indiceRuta("./");

  //Consultador consultador(indiceNombre, indiceRuta);

  {

    if (/*consultador.abrirIndice() !=*/RESULTADO_OK) {

      std::cout << "INDICE: " << indiceNombre << " NO EXISTE EN UBICACIÓN: " << indiceRuta << std::endl;
      retornoValor = ERROR;
      std::cout << "FÍN DE PROGRAMA CONTROLADO, ECHO $? = " << retornoValor << std::endl;
      return retornoValor;
    }

    //consultador.consultar(consulta);

  }
  retornoValor = RESULTADO_OK;
  std::cout << "FÍN DE PROGRAMA CONTROLADO, ECHO $? = " << retornoValor << std::endl;
  return retornoValor;
}
