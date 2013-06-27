/*
 * ManejadorOffset.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./ManejadorOffset.h"
#include <string>

ManejadorOffset::ManejadorOffset(const std::string &ruta, const std::string &indiceNombre)
    : ruta(ruta), indiceNombre(indiceNombre), manejadorArchivo(ruta + indiceNombre + "DocNomOff.bin") {
  // TODO Auto-generated constructor stub
}

ManejadorOffset::~ManejadorOffset() {
}

void ManejadorOffset::close() {
  // TODO
}
