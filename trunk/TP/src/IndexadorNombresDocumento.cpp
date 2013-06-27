/*
 * IndexadorNombresDocumento.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./IndexadorNombresDocumento.h"
#include "./Documento.h"
#include "./FCP.h"
#include "./ManejadorOffset.h"

#include <iostream>

IndexadorNombresDocumento::IndexadorNombresDocumento(const std::string &archivosSalidaRuta, const std::string &indiceNombre, const unsigned int bloqueTamanyo, const bool soloHayUnBloque)
    : archivosSalidaRuta(archivosSalidaRuta), indiceNombre(indiceNombre), bloqueTamanyo(bloqueTamanyo), contadorIndexados(0), fcp(archivosSalidaRuta, indiceNombre, bloqueTamanyo), offsetManejador(archivosSalidaRuta, indiceNombre), soloHayUnBloque(soloHayUnBloque) {
  std::cout << "Ejecutando IndexadorNombresDocumento::IndexadorNombresDocumento()." << std::endl;
  fcp.escribirBloqueTamanyo(bloqueTamanyo, soloHayUnBloque);
}

IndexadorNombresDocumento::~IndexadorNombresDocumento() {
  std::cout << "Ejecutando IndexadorNombresDocumento::~IndexadorNombresDocumento()." << std::endl;
}

void IndexadorNombresDocumento::indexar(const Documento &documento) {
  std::cout << "Ejecutando IndexadorNombresDocumento::indexar()." << std::endl;
  if (contadorIndexados >= bloqueTamanyo) {
    // Si llegué al tamaño máximo del bloque...
    // Escribir los offsets del próximo bloque en el archivo de offsets de bloques.
    offsetManejador.escribirOffsetsNombresDocumento(fcp.offsetBytesDiferencias, fcp.offsetBitsDiferencias, fcp.offsetBytesCaracteres);
    // Reinicializo los offset del fcp.
    fcp.offsetBytesDiferencias = fcp.offsetBitsDiferencias = 0;
    fcp.offsetBytesCaracteres = fcp.offsetBitsCaracteres = 0;
    // Fuerzo un "caracteres iguales = 0" para la proxima cadena a escribir.
    fcp.cadenaAnterior = "";
    contadorIndexados = 0;
  }
  fcp.escribirSinCodificar(documento.nombre);
  ++contadorIndexados;
}

void IndexadorNombresDocumento::close() {
  std::cout << "Ejecutando IndexadorNombresDocumento::close()." << std::endl;
  fcp.close();
  offsetManejador.close();
}
