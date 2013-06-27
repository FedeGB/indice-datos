/*
 * ManejadorArchivo.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./ManejadorArchivo.h"
#include <iostream>

ManejadorArchivo::ManejadorArchivo(const std::string &archivoRuta) {
  std::cout << "Ejecutando ManejadorArchivo::ManejadorArchivo()." << std::endl;
}

ManejadorArchivo::~ManejadorArchivo() {
  std::cout << "Ejecutando ManejadorArchivo::~ManejadorArchivo()." << std::endl;
}

void escribir(const char * const datos, const int cantidadBits) {
  std::cout << "Ejecutando ManejadorArchivo::escribir()." << std::endl;
}
