#ifndef FCP_H_
#define FCP_H_

/*
 * FCP.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <string>
#include <stdint.h>
#include "./ManejadorArchivo.h"

class FCP {
  public:
    // Ruta al directorio donde se crearán los archivos.
    const std::string archivosSalidaRuta;

    // Nombre del índice, para ponérselo a los archivos que componen al índice.
    const std::string indiceNombre;

    const unsigned int bloqueTamanyo;
    ManejadorArchivo manejadorArchivoCaracteres;
    ManejadorArchivo manejadorArchivoDiferencias;

    std::string cadenaAnterior;
    uint64_t offsetBytesDiferencias;
    unsigned char offsetBitsDiferencias;
    uint64_t offsetBytesCaracteres;
    unsigned char offsetBitsCaracteres;

    FCP(const std::string &archivosSalidaRuta, const std::string &indiceNombre, const unsigned int bloqueTamanyo);

    virtual ~FCP();

    void close();

    void escribirSinCodificar(const std::string &cadenaActual);

    void hallarIgualesYDistintos(const std::string &cadenaActual, unsigned long int &iguales, unsigned long int &distintos);

    void agregarOffsets(const unsigned int diferenciasBits, const unsigned int caracteresBits);
};

#endif /* FCP_H_ */
