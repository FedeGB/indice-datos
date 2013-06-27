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
    std::fstream archivoHandler;
    unsigned char pBuffer[1];
    unsigned char bitsEnBuffer;
    unsigned long int bufferLectura;

    ManejadorArchivo(const std::string &rutaConNombre);
    virtual ~ManejadorArchivo();

    void escribirBinario(const void * const pDatos, const int cantidadBits);

    void escribirSinCodificar(const std::string &cadena);

    void leerSinCodificar(std::string &cadena, const unsigned int largo);

    void posicionarse(const unsigned long int offsetBytes, const unsigned long int offsetBits);

    bool leerBinario(unsigned long int * const numeroLeido);

    void close();
};

#endif /* MANEJADORARCHIVO_H_ */
