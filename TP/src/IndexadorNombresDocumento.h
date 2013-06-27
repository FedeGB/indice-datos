#ifndef INDEXADORNOMBRESDOCUMENTO_H_
#define INDEXADORNOMBRESDOCUMENTO_H_

/*
 * IndexadorNombresDocumento.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <string>
#include "./Documento.h"
#include "./FCP.h"
#include "./ManejadorOffset.h"

class IndexadorNombresDocumento {
  public:
    // Ruta al directorio donde se crearán los archivos.
    const std::string archivosSalidaRuta;

    // Nombre del índice, para ponérselo a los archivos que componen al índice.
    const std::string indiceNombre;
    const unsigned int bloqueTamanyo;
    unsigned int contadorIndexados;
    FCP fcp;
    ManejadorOffset offsetManejador;
    const bool soloHayUnBloque;

    IndexadorNombresDocumento(const std::string &archivosSalidaRuta, const std::string &indiceNombre, const unsigned int bloqueTamanyo, const bool soloHayUnBloque);

    virtual ~IndexadorNombresDocumento();

    void indexar(const Documento &documento);

    void close();
};

#endif /* INDEXADORNOMBRESDOCUMENTO_H_ */
