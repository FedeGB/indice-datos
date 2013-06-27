/*
 * documentos.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./documentos.h"

Documento::Documento(const std::string &path, const std::string &name, int size): 
					path(path), name(name), size(size) { }

void Documento::setSerial(int num) {
	this->serial = num;
}

