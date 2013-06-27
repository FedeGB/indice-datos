/*
 * Documento.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./Documento.h"

#include <iostream>

Documento::Documento(const std::string &nombre, const unsigned int tamanyo, const int serial)
    : nombre(nombre), tamanyo(tamanyo), serial(serial) {
  std::cout << "Ejecutando Documento::Documento()." << std::endl;
}

Documento::~Documento() {
  std::cout << "Ejecutando Documento::~Documento()." << std::endl;
}

bool Documento::ordenadorDeDocumentosPorTamanyo(const Documento &primero, const Documento &segundo) {
  std::cout << "Ejecutando Documento::ordenadorDeDocumentosPorTamanyo()." << std::endl;
  // Devuelve true si el primero va antes que el segundo.
  // Si los dos tienen el mismo tamanyo, los ordena alfabeticamente.
  return ((primero.tamanyo < segundo.tamanyo) || ((primero.tamanyo == segundo.tamanyo) && (primero.nombre.compare(segundo.nombre) <= 0)));
}
