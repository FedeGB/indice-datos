/*
 * Documento.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./Documento.h"

Documento::Documento(const std::string &nombre, const unsigned int tamanyo, const int serial)
    : nombre(nombre), tamanyo(tamanyo), serial(serial) {
}

Documento::~Documento() {
}
