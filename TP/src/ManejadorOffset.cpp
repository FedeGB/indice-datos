/*
 * ManejadorOffset.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./ManejadorOffset.h"
#include <string>

#include <iostream>

ManejadorOffset::ManejadorOffset(const std::string &ruta, const std::string &indiceNombre)
    : ruta(ruta), indiceNombre(indiceNombre), manejadorArchivo(ruta + indiceNombre + "DocNomOff.bin") {
  std::cout << "Ejecutando ManejadorOffset::ManejadorOffset()." << std::endl;
}

ManejadorOffset::~ManejadorOffset() {
  std::cout << "Ejecutando ManejadorOffset::~ManejadorOffset()." << std::endl;
}

void ManejadorOffset::close() {
  std::cout << "Ejecutando ManejadorOffset::~close()." << std::endl;
  // TODO
}

void ManejadorOffset::escribirOffsetsNombresDocumento(const unsigned int offsetBytesDiferencias, const unsigned int offsetBitsDiferencias, const unsigned int offsetBytesCaracteres) {
  // TODO
}
