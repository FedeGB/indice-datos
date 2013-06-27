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
  //std::cout << "Ejecutando FCP::close()." << std::endl;
  manejadorArchivoCaracteres.close();
  manejadorArchivoDiferencias.close();
}

void FCP::escribirSinCodificar(const std::string &cadenaActual) {
  std::cout << "Ejecutando FCP::escribirSinCodificar()." << std::endl;
  unsigned long int iguales = 0;
  unsigned long int distintos = 0;
  hallarIgualesYDistintos(cadenaActual, iguales, distintos);

  std::cout << "CADENA ANTERIOR" << cadenaAnterior << std::endl;
  cadenaAnterior = cadenaActual;
  std::cout << "CADENA ANTERIOR" << cadenaAnterior << std::endl;

  std::string diferencia(cadenaActual.substr(iguales, std::string::npos));
  manejadorArchivoCaracteres.escribirSinCodificar(diferencia);
  CDelta igualesDelta(iguales + 1);
  CDelta distintosDelta(distintos);

  /*
   CDelta foobar1(1);
   std::cout << 1 << " es en delta dado vuelta: " << (int) (*(foobar1.codigo)) << std::endl;
   CDelta foobar2(2);
   std::cout << 2 << " es en delta dado vuelta: " << (int) (*(foobar2.codigo)) << std::endl;
   CDelta foobar3(3);
   std::cout << 3 << " es en delta dado vuelta: " << (int) (*(foobar3.codigo)) << std::endl;
   CDelta foobar4(4);
   std::cout << 4 << " es en delta dado vuelta: " << (int) (*(foobar4.codigo)) << std::endl;
   CDelta foobar5(5);
   std::cout << 5 << " es en delta dado vuelta: " << (int) (*(foobar5.codigo)) << std::endl;
   CDelta foobar6(6);
   std::cout << 6 << " es en delta dado vuelta: " << (int) (*(foobar6.codigo)) << std::endl;
   CDelta foobar7(7);
   std::cout << 7 << " es en delta dado vuelta: " << (int) (*(foobar7.codigo)) << std::endl;
   CDelta foobar8(8);
   std::cout << 8 << " es en delta dado vuelta: " << (int) (*(foobar8.codigo)) << std::endl;
   CDelta foobar9(9);
   std::cout << 9 << " es en delta dado vuelta: " << (int) (*(foobar9.codigo)) << std::endl;
   CDelta foobar10(10);
   std::cout << 10 << " es en delta dado vuelta: " << (int) (*(foobar10.codigo)) << std::endl;
   CDelta foobar11(11);
   std::cout << 11 << " es en delta dado vuelta: " << (int) (*(foobar11.codigo)) << std::endl;
   CDelta foobar12(12);
   std::cout << 12 << " es en delta dado vuelta: " << (int) (*(foobar12.codigo)) << std::endl;
   CDelta foobar13(13);
   std::cout << 13 << " es en delta dado vuelta: " << (int) (*(foobar13.codigo)) << std::endl;
   CDelta foobar14(14);
   std::cout << 14 << " es en delta dado vuelta: " << (int) (*(foobar14.codigo)) << std::endl;
   CDelta foobar15(15);
   std::cout << 15 << " es en delta dado vuelta: " << (int) (*(foobar15.codigo)) << std::endl;
   CDelta foobar16(16);
   std::cout << 16 << " es en delta dado vuelta: " << (int) (*(foobar16.codigo)) << std::endl;
   */

  /*
   manejadorArchivoDiferencias.escribirBinario(foobar10.codigo, foobar10.bits);
   manejadorArchivoDiferencias.escribirBinario(foobar1.codigo, foobar1.bits);
   manejadorArchivoDiferencias.escribirBinario(foobar10.codigo, foobar10.bits);
   manejadorArchivoDiferencias.escribirBinario(foobar10.codigo, foobar10.bits);

   manejadorArchivoDiferencias.escribirBinario(foobar10.codigo, foobar10.bits);
   manejadorArchivoDiferencias.escribirBinario(foobar1.codigo, foobar1.bits);
   manejadorArchivoDiferencias.escribirBinario(foobar10.codigo, foobar10.bits);
   manejadorArchivoDiferencias.escribirBinario(foobar10.codigo, foobar10.bits);

   manejadorArchivoDiferencias.escribirBinario(foobar1.codigo, foobar1.bits);
   */

  manejadorArchivoDiferencias.escribirBinario(igualesDelta.codigo, igualesDelta.bits);
  manejadorArchivoDiferencias.escribirBinario(distintosDelta.codigo, distintosDelta.bits);
  agregarOffsets(igualesDelta.bits + distintosDelta.bits, distintos * 8);
}

void FCP::hallarIgualesYDistintos(const std::string &cadenaActual, unsigned long int &iguales, unsigned long int &distintos) {
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
  std::cout << "Cadena anterior: \"" << cadenaAnterior << "\", Cadena actual: \"" << cadenaActual << "\", Iguales: " << iguales << ", Distintos: " << distintos << std::endl;
}

void FCP::agregarOffsets(const unsigned int diferenciasBits, const unsigned int caracteresBits) {
  unsigned int diferenciasBytes = diferenciasBits / 8;
  unsigned int caracteresBytes = caracteresBits / 8;
  offsetBytesDiferencias += diferenciasBytes;
  offsetBitsDiferencias += (diferenciasBits % 8);
  offsetBytesCaracteres += caracteresBytes;
  offsetBitsCaracteres += (diferenciasBits % 8);
}

void FCP::escribirBloqueTamanyo(const unsigned int bloqueTamanyo, bool soloHayUnBloque) {
  unsigned int tamanyoCodigo;
  if (soloHayUnBloque == true) {
    tamanyoCodigo = 1;
  } else {
    tamanyoCodigo = bloqueTamanyo - 98;
  }
  CDelta tamanyoDelta(tamanyoCodigo);
  manejadorArchivoDiferencias.escribirBinario(tamanyoDelta.codigo, tamanyoDelta.bits);
}
