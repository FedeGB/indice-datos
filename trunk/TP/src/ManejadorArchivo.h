/*
 * ManejadorArchivo.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#ifndef MANEJADORARCHIVO_H_
#define MANEJADORARCHIVO_H_

#include <fstream>
#include <string>

class ManejadorArchivo {
public:
	std::fstream archivoHandler;
	char buffer[1];
	char bitsEnBuffer;

	ManejadorArchivo(const std::string &archivoRuta);
	virtual ~ManejadorArchivo();

	void escribir(const char * const datos, const int cantidadBits);
};

#endif /* MANEJADORARCHIVO_H_ */
