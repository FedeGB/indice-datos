#ifndef INDEXADORNOMBRESDOCUMENTO_H_
#define INDEXADORNOMBRESDOCUMENTO_H_

/*
 * IndexadorNombresDocumento.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <fstream>
#include <string>
#include "./Documento.h"

class IndexadorNombresDocumento {
  public:
    const std::string archivosSalidaRuta;
    const unsigned int tamanyoBloque;
    std::fstream archivoHandler;

    IndexadorNombresDocumento(const std::string &archivosSalidaRuta, const unsigned int tamanyoBloque);
    virtual ~IndexadorNombresDocumento();

    void indexar(const Documento &documento);
    void close();
};

#endif /* INDEXADORNOMBRESDOCUMENTO_H_ */
