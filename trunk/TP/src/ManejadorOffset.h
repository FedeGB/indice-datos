#ifndef MANEJADOROFFSET_H_
#define MANEJADOROFFSET_H_

/*
 * ManejadorOffset.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <string>

class ManejadorOffset {
  public:
    // Ruta al directorio donde se crearán los archivos.
    const std::string archivosSalidaRuta;

    // Nombre del indice, para ponérselo a los archivos que componen al índice.
    const std::string indiceNombre;

    ManejadorOffset(const std::string &archivosSalidaRuta, const std::string &indiceNombre);

    virtual ~ManejadorOffset();

    void close();
};

#endif /* MANEJADOROFFSET_H_ */
