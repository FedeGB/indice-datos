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

void FCP::escribir(const std::string &cadenaActual) {
  std::cout << "Ejecutando FCP::indexar()." << std::endl;
  unsigned int iguales = 0;
  unsigned int distintos = 0;
  unsigned int posicion = 0;
  unsigned int actualLargo = cadenaActual.length();
  unsigned int anteriorLargo = cadenaAnterior.length();
  const char *pActual = cadenaActual.c_str();
  const char *pAnterior = cadenaAnterior.c_str();
  while ((posicion < actualLargo) && (posicion < anteriorLargo) && (pActual[posicion] == pAnterior[posicion])) {
    ++posicion;
  }
  iguales = posicion;
  distintos = actualLargo - iguales;
  cadenaAnterior = cadenaActual;
  //std::string()
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
