/*
 * IndexadorNombresDocumento.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./IndexadorNombresDocumento.h"
#include <iostream>
#include "./Documento.h"

IndexadorNombresDocumento::IndexadorNombresDocumento(const std::string &archivosSalidaRuta, const unsigned int tamanyoBloque)
    : archivosSalidaRuta(archivosSalidaRuta), tamanyoBloque(tamanyoBloque), archivoHandler(archivosSalidaRuta.c_str(), std::ofstream::out){
  std::cout << "Ejecutando IndexadorNombresDocumento::IndexadorNombresDocumento()." << std::endl;
}

IndexadorNombresDocumento::~IndexadorNombresDocumento() {
  std::cout << "Ejecutando IndexadorNombresDocumento::~IndexadorNombresDocumento()." << std::endl;
}

void IndexadorNombresDocumento::indexar(const Documento &documento) {
  // TODO (Iván)
}

void IndexadorNombresDocumento::close() {
  archivoHandler.close();
}
