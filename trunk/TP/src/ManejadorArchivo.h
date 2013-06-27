#ifndef MANEJADORARCHIVO_H_
#define MANEJADORARCHIVO_H_

/*
 * ManejadorArchivo.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <fstream>
#include <string>

class ManejadorArchivo {
  public:
    const std::string rutaConNombre;
    std::ofstream archivoHandler;
    unsigned char buffer[1];
    unsigned char bitsEnBuffer;

    ManejadorArchivo(const std::string &rutaConNombre);
    virtual ~ManejadorArchivo();

    void escribirBinario(const unsigned char * const datos, const int cantidadBits);

    void escribirSinCodificar(const std::string &cadena);

    void close();
};

#endif /* MANEJADORARCHIVO_H_ */
