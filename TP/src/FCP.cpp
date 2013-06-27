/*
 * FCP.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./FCP.h"
#include <string>
#include "./Codigos.h"

#include <iostream>

FCP::FCP(const std::string &archivosSalidaRuta, const std::string &indiceNombre, const unsigned int bloqueTamanyo)
    : archivosSalidaRuta(archivosSalidaRuta), indiceNombre(indiceNombre), bloqueTamanyo(bloqueTamanyo), manejadorArchivoCaracteres(archivosSalidaRuta + indiceNombre + "DocNom.txt"), manejadorArchivoDiferencias(archivosSalidaRuta + indiceNombre + "DocNomDif.bin"), offsetBytesDiferencias(0), offsetBitsDiferencias(0), offsetBytesCaracteres(0), offsetBitsCaracteres(0) {
  std::cout << "Ejecutando FCP::FCP()." << std::endl;
}

FCP::~FCP() {
  std::cout << "Ejecutando FCP::~FCP()." << std::endl;
}

void FCP::close() {
  std::cout << "Ejecutando FCP::close()." << std::endl;
  manejadorArchivoCaracteres.close();
  manejadorArchivoDiferencias.close();
}

void FCP::escribirSinCodificar(const std::string &cadenaActual) {
  std::cout << "Ejecutando FCP::indexar()." << std::endl;
  unsigned int iguales = 0;
  unsigned int distintos = 0;
  hallarIgualesYDistintos(cadenaActual, iguales, distintos);
  cadenaAnterior = cadenaActual;
  std::string diferencia(cadenaActual.substr(iguales, std::string::npos));
  manejadorArchivoCaracteres.escribirSinCodificar(diferencia);
  CDelta igualesDelta(iguales);
  CDelta distintosDelta(distintos);
  manejadorArchivoDiferencias.escribirBinario(igualesDelta.codigo, igualesDelta.bits);
  manejadorArchivoDiferencias.escribirBinario(distintosDelta.codigo, distintosDelta.bits);
  agregarOffsets(igualesDelta.bits + distintosDelta.bits, distintos * 8);
}

void FCP::hallarIgualesYDistintos(const std::string &cadenaActual, unsigned int &iguales, unsigned int &distintos) {
  std::cout << "Ejecutando FCP::hallarIgualesYDistintos()." << std::endl;
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
  std::cout << "Cadena anterior: " << cadenaAnterior << ", Cadena actual: " << cadenaActual << ", Iguales: " << iguales << ", Distintos: " << distintos << std::endl;
}

void FCP::agregarOffsets(const unsigned int diferenciasBits, const unsigned int caracteresBits) {
  unsigned int diferenciasBytes = diferenciasBits / 8;
  unsigned int caracteresBytes = caracteresBits / 8;
  offsetBytesDiferencias += diferenciasBytes;
  offsetBitsDiferencias += (diferenciasBits % 8);
  offsetBytesCaracteres += caracteresBytes;
  offsetBitsCaracteres += (diferenciasBits % 8);
}
