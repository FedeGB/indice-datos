/*
 * ManejadorArchivo.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./ManejadorArchivo.h"
#include <fstream>
#include <iostream>

ManejadorArchivo::ManejadorArchivo(const std::string &rutaConNombre)
    : rutaConNombre(rutaConNombre), archivoHandler(rutaConNombre.c_str(), std::ofstream::out), buffer(), bitsEnBuffer(0) {
  std::cout << "Ejecutando ManejadorArchivo::ManejadorArchivo()." << std::endl;
}

ManejadorArchivo::~ManejadorArchivo() {
  std::cout << "Ejecutando ManejadorArchivo::~ManejadorArchivo()." << std::endl;
}

void escribir(const char * const datos, const int cantidadBits) {
  std::cout << "Ejecutando ManejadorArchivo::escribir()." << std::endl;
  // TODO (): Método importante.
}
