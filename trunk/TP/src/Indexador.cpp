/*
 * Indexador.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./Documento.h"
#include "./Indexador.h"
#include "./IndexadorNombresDocumento.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <set>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

Indexador::Indexador(const std::string &indiceNombre, const std::string &repositorioRuta)
    : indiceNombre(indiceNombre), repositorioRuta(repositorioRuta) {
  std::cout << "Ejecutando Indexador::Indexador()." << std::endl;
}

Indexador::~Indexador() {
  std::cout << "Ejecutando Indexador::~Indexador()." << std::endl;
}

// Este es el método principal.
void Indexador::indexar(const std::string &archivosSalidaRuta) {
  std::cout << "Ejecutando Indexador::indexar()." << std::endl;
  std::list< Documento > listadoDocumentosAlfabetico;
  generarListadoAlfabeticoDeNombresDeDocumentos(listadoDocumentosAlfabetico);
  std::set< Documento, bool (*)(const Documento &primero, const Documento &segundo) > setDocumentosPorTamanyo(Documento::ordenadorDeDocumentosPorTamanyo);
  indexarNombresDeDocumentosYOrdenarPorTamanyo(setDocumentosPorTamanyo, listadoDocumentosAlfabetico, archivosSalidaRuta);
  indexarTerminos(setDocumentosPorTamanyo, archivosSalidaRuta);
}

void Indexador::generarListadoAlfabeticoDeNombresDeDocumentos(std::list< Documento > &listadoDocumentosAlfabetico) {
  std::cout << "Ejecutando Indexador::generarListadoAlfabeticoDeNombresDeDocumentos()." << std::endl;
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
      listadoDocumentosAlfabetico.push_back(Documento(nombre, tamanyo, contador));
      ::free(vector[contador]);
    }
    ::free(vector);
  }
  std::cout << "***FÍN DE GENERACIÓN DE LISTADO DE DOCUMENTOS." << std::endl;
}

int Indexador::filtro(const struct dirent *pDirent) {
  return (strcmp(pDirent->d_name, ".") && strcmp(pDirent->d_name, ".."));
}

void Indexador::indexarNombresDeDocumentosYOrdenarPorTamanyo(std::set< Documento, bool (*)(const Documento &primero, const Documento &segundo) > &setDocumentosPorTamanyo, std::list< Documento > &listadoDocumentosAlfabetico, const std::string &archivosSalidaRuta) {
  std::cout << "Ejecutando Indexador::indexarNombresDeDocumentosYOrdenarPorTamanyo()." << std::endl;
  unsigned int cantidadDocumentos = listadoDocumentosAlfabetico.size();
  std::cout << "  La cantidad de documentos es: " << cantidadDocumentos << std::endl;
  unsigned int bloqueTamanyo;
  if (cantidadDocumentos <= 1000) {
    bloqueTamanyo = 100;
  } else {
    double auxiliar = ::log10(cantidadDocumentos);
    auxiliar /= 3;
    auxiliar -= 1;
    auxiliar *= 900;
    auxiliar += 100;
    bloqueTamanyo = ::floor(auxiliar);
  }
  std::cout << "  El tamaño de bloque es: " << bloqueTamanyo << std::endl;
  bool soloHayUnBloque = false;
  if (cantidadDocumentos <= 100) {
    soloHayUnBloque = true;
    std::cout << "  Solo hay un bloque." << std::endl;
  }
  std::list< Documento >::iterator iterador = listadoDocumentosAlfabetico.begin();
  IndexadorNombresDocumento indexadorNombresDocumento(archivosSalidaRuta, indiceNombre, bloqueTamanyo, soloHayUnBloque);
  while (iterador != listadoDocumentosAlfabetico.end()) {
    setDocumentosPorTamanyo.insert(*iterador);
    indexadorNombresDocumento.indexar(*iterador);
    listadoDocumentosAlfabetico.erase(iterador++);
  }
  indexadorNombresDocumento.close();
}

void Indexador::indexarTerminos(std::set< Documento, bool (*)(const Documento &primero, const Documento &segundo) > &setDocumentosPorTamanyo, const std::string &archivosSalidaRuta) {
  std::cout << "Ejecutando Indexador::indexarTerminos()." << std::endl;
  // TODO (Imprescindible): El más importante.
}
