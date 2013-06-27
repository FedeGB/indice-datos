/*
 * IndexadorNombresDocumento.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./IndexadorNombresDocumento.h"
#include <iostream>
#include "./Documento.h"
#include "./FCP.h"
#include "./ManejadorOffset.h"

IndexadorNombresDocumento::IndexadorNombresDocumento(const std::string &archivosSalidaRuta, const std::string &indiceNombre, const unsigned int tamanyoBloque)
    : archivosSalidaRuta(archivosSalidaRuta), indiceNombre(indiceNombre), tamanyoBloque(tamanyoBloque), fcp(archivosSalidaRuta, indiceNombre), offsetManejador(archivosSalidaRuta, indiceNombre) {
  std::cout << "Ejecutando IndexadorNombresDocumento::IndexadorNombresDocumento()." << std::endl;
}

IndexadorNombresDocumento::~IndexadorNombresDocumento() {
  std::cout << "Ejecutando IndexadorNombresDocumento::~IndexadorNombresDocumento()." << std::endl;
}

void IndexadorNombresDocumento::indexar(const Documento &documento) {
  std::cout << "Ejecutando IndexadorNombresDocumento::indexar()." << std::endl;
  // TODO (Iván)
}

void IndexadorNombresDocumento::close() {
  std::cout << "Ejecutando IndexadorNombresDocumento::close()." << std::endl;
  fcp.close();
  offsetManejador.close();
}
