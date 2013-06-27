/*
 * documentos.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./documentos.h"
#include <cstring>

Documentos::Documentos(char* path, char* name, int size) {
  this->path = new char[strlen(path) + 1];
  strcpy(this->path, path);
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
  this->size = size;
}

Documentos::~Documentos() {
  delete[] path;
  delete[] name;
}
