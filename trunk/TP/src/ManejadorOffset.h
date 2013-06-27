#ifndef MANEJADOROFFSET_H_
#define MANEJADOROFFSET_H_

/*
 * ManejadorOffset.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <string>
#include <stdint.h>
#include "./ManejadorArchivo.h"

class ManejadorOffset {
  public:
    // Ruta al directorio donde se crearán los archivos.
    const std::string ruta;

    // Nombre del indice, para ponérselo a los archivos que componen al índice.
    const std::string indiceNombre;

    ManejadorArchivo manejadorArchivo;

    ManejadorOffset(const std::string &ruta, const std::string &indiceNombre);

    virtual ~ManejadorOffset();

    void close();

    void escribirOffsetsNombresDocumento(const uint64_t offsetBytesDiferencias, const unsigned char offsetBitsDiferencias, const uint64_t offsetBytesCaracteres);
};

#endif /* MANEJADOROFFSET_H_ */
