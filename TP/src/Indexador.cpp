/*
 * Indexador.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./Documento.h"
#include "./Indexador.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

Indexador::Indexador(const std::string &repositorioNombre, const std::string &repositorioRuta)
    : repositorioNombre(repositorioNombre), repositorioRuta(repositorioRuta) {
  std::cout << "Ejecutando Indexador::Indexador()." << std::endl;
}

Indexador::~Indexador() {
  std::cout << "Ejecutando Indexador::~Indexador()." << std::endl;
}

void Indexador::indexar() {
  std::cout << "Ejecutando Indexador::indexar()." << std::endl;
  indexarNombresDeDocumentos();

}

void Indexador::indexarNombresDeDocumentos() {
  std::cout << "Indexador::indexarNombresDeDocumentos():" << std::endl;
  std::list< Documento > listadoArchivosAlfabetico;

  std::cout << "***INICIO DE GENERACIÓN DE LISTADO DE DOCUMENTOS." << std::endl;
  struct dirent **vector;
  // http://linux.die.net/man/3/scandir
  // http://linux.die.net/man/3/alphasort
  const int cantidad = ::scandir(repositorioRuta.c_str(), &vector, &filtro, ::alphasort);
  std::cout << "  Cantidad de archivos a indexar: " << cantidad << std::endl;
  if (cantidad < 0) {
    ::perror("::scandir()");
  } else {
    for (int contador = 0; contador < cantidad; ++contador) {
      struct stat info;
      std::string nombre(vector[contador]->d_name);
      std::string archivoRuta(repositorioRuta + nombre);
      // http://linux.die.net/man/1/stat
      // http://linux.die.net/man/2/stat
      // http://linux.die.net/man/3/stat
      if (::stat(archivoRuta.c_str(), &info) == -1) {
        ::perror("::stat()");
      }
      off_t tamanyo = info.st_size;
      std::cout << "  Archivo indexado: " << nombre << std::endl;
      listadoArchivosAlfabetico.push_back(Documento(nombre, tamanyo, contador));
      ::free(vector[contador]);
    }
    ::free(vector);
  }
  std::cout << "***FÍN DE GENERACIÓN DE LISTADO DE DOCUMENTOS." << std::endl;
}

int Indexador::filtro(const struct dirent *pDirent) {
  return (strcmp(pDirent->d_name, ".") && strcmp(pDirent->d_name, ".."));
}
