#ifndef FCP_H_
#define FCP_H_

/*
 * FCP.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <string>

class FCP {
  public:
    // Ruta al directorio donde se crearán los archivos.
    const std::string archivosSalidaRuta;

    // Nombre del indice, para ponérselo a los archivos que componen al índice.
    const std::string indiceNombre;

    FCP(const std::string &archivosSalidaRuta, const std::string &indiceNombre);

    virtual ~FCP();

    void close();
};

#endif /* FCP_H_ */
