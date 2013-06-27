/*
 * IndexadorNombresDocumento.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./IndexadorNombresDocumento.h"
#include "./Documento.h"
#include "./FCP.h"
#include "./ManejadorOffset.h"

#include <iostream>

IndexadorNombresDocumento::IndexadorNombresDocumento(const std::string &archivosSalidaRuta, const std::string &indiceNombre, const unsigned int bloqueTamanyo)
    : archivosSalidaRuta(archivosSalidaRuta), indiceNombre(indiceNombre), bloqueTamanyo(bloqueTamanyo), contadorIndexados(0), fcp(archivosSalidaRuta, indiceNombre, bloqueTamanyo), offsetManejador(archivosSalidaRuta, indiceNombre) {
  std::cout << "Ejecutando IndexadorNombresDocumento::IndexadorNombresDocumento()." << std::endl;
}

IndexadorNombresDocumento::~IndexadorNombresDocumento() {
  std::cout << "Ejecutando IndexadorNombresDocumento::~IndexadorNombresDocumento()." << std::endl;
}

void IndexadorNombresDocumento::indexar(const Documento &documento) {
  std::cout << "Ejecutando IndexadorNombresDocumento::indexar()." << std::endl;
  if (contadorIndexados >= bloqueTamanyo) {
    // Terminar un bloque.
  }
  fcp.indexar(documento);
  ++contadorIndexados;
}

void IndexadorNombresDocumento::close() {
  std::cout << "Ejecutando IndexadorNombresDocumento::close()." << std::endl;
  fcp.close();
  offsetManejador.close();
}
