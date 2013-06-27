#ifndef FCP_H_
#define FCP_H_

/*
 * FCP.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <string>
#include "./Documento.h"
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
    unsigned int offsetBytesCaracteres;
    unsigned int offsetBitsCaracteres;
    unsigned int offsetBytesDiferencias;
    unsigned int offsetBitsDiferencias;

    FCP(const std::string &archivosSalidaRuta, const std::string &indiceNombre, const unsigned int bloqueTamanyo);

    virtual ~FCP();

    void close();

    void indexar(const Documento &documento);

    unsigned int getOffsetBytesCaracteres();
    unsigned int getOffsetBitsCaracteres();
    unsigned int getOffsetBytesDiferencias();
    unsigned int getOffsetBitsDiferencias();
};

#endif /* FCP_H_ */
