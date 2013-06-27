/*
 * FCP.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./FCP.h"
#include <string>

#include <iostream>

FCP::FCP(const std::string &archivosSalidaRuta, const std::string &indiceNombre, const unsigned int bloqueTamanyo)
    : archivosSalidaRuta(archivosSalidaRuta), indiceNombre(indiceNombre), bloqueTamanyo(bloqueTamanyo), manejadorArchivoCaracteres(archivosSalidaRuta + indiceNombre + "DocNom.txt"), manejadorArchivoDiferencias(archivosSalidaRuta + indiceNombre + "DocNomDif.bin"), offsetBytesCaracteres(0), offsetBitsCaracteres(0), offsetBytesDiferencias(0), offsetBitsDiferencias(0) {
  std::cout << "Ejecutando FCP::FCP()." << std::endl;
}

FCP::~FCP() {
  std::cout << "Ejecutando FCP::~FCP()." << std::endl;
}

void FCP::close() {
  std::cout << "Ejecutando FCP::close()." << std::endl;
  // TODO
}

void FCP::indexar(const Documento &documento) {
  std::cout << "Ejecutando FCP::indexar()." << std::endl;
  // TODO
}

unsigned int FCP::getOffsetBytesCaracteres() {
  return offsetBytesCaracteres;
}

unsigned int FCP::getOffsetBitsCaracteres() {
  return offsetBitsCaracteres;
}

unsigned int FCP::getOffsetBytesDiferencias() {
  return offsetBytesDiferencias;
}

unsigned int FCP::getOffsetBitsDiferencias() {
  return offsetBitsDiferencias;
}
