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

int main(int argc, char *argv[]) {
  int retornoValor = ERROR;
  if (argc != 3) {
    std::cout << "ERROR EN LA CANTIDAD DE ARGUMENTOS." << std::endl;
    retornoValor = ERROR_ARGC;
    std::cout << "FÍN DE PROGRAMA CONTROLADO, ECHO $? = " << retornoValor << std::endl;
    return retornoValor;
  } else {
    std::cout << "CANTIDAD DE ARGUMENTOS CORRECTA." << std::endl;
  }
  std::string repositorioNombre(argv[1]);
  std::cout << "El nombre del repositorio es: " << repositorioNombre << std::endl;
  std::string repositorioRuta(argv[2]);
  std::cout << "La ruta del repositorio es: " << repositorioRuta << std::endl;
  Indexador indexador(repositorioNombre, repositorioRuta);
  {
    indexador.indexar(std::string("./"));
  }
  retornoValor = RESULTADO_OK;
  std::cout << "FÍN DE PROGRAMA CONTROLADO, ECHO $? = " << retornoValor << std::endl;
  return retornoValor;
}
