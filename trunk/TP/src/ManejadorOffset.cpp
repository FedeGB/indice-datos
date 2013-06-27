/*
 * ManejadorOffset.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./ManejadorOffset.h"
#include <string>
#include <stdint.h>
#include "./Codigos.h"

#include <iostream>

ManejadorOffset::ManejadorOffset(const std::string &ruta, const std::string &indiceNombre)
    : ruta(ruta), indiceNombre(indiceNombre), manejadorArchivo(ruta + indiceNombre + "DocNomOff.bin") {
  //std::cout << "Ejecutando ManejadorOffset::ManejadorOffset()." << std::endl;
}

ManejadorOffset::~ManejadorOffset() {
  //std::cout << "Ejecutando ManejadorOffset::~ManejadorOffset()." << std::endl;
}

void ManejadorOffset::close() {
  //std::cout << "Ejecutando ManejadorOffset::close()." << std::endl;
  manejadorArchivo.close();
}

void ManejadorOffset::escribirOffsetsNombresDocumento(const uint64_t offsetBytesDiferencias, const unsigned char offsetBitsDiferencias, const uint64_t offsetBytesCaracteres) {
  /*
   CDelta bytesDiferencias(offsetBytesDiferencias);
   CDelta bitsDiferencias(offsetBitsDiferencias);
   CDelta bytesCaracteres(offsetBytesCaracteres);
   */
  const uint64_t bytesDiferencias = offsetBytesDiferencias;
  // TODO (Necesario): Hacer que este sea de 3 bits, no de 8. Y luego hacer que este método use la opción 2 mencionada en la pre-entrega.
  const unsigned char bitsDiferencias = offsetBitsDiferencias;
  const uint64_t bytesCaracteres = offsetBytesCaracteres;
  manejadorArchivo.escribirBinario((const unsigned char *) &bytesDiferencias, sizeof bytesDiferencias);
  manejadorArchivo.escribirBinario((const unsigned char *) &bytesDiferencias, sizeof bitsDiferencias);
  manejadorArchivo.escribirBinario((const unsigned char *) &bytesDiferencias, sizeof bytesCaracteres);
}
