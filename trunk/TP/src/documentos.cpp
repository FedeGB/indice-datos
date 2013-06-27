#include "documentos.h"

Documento::Documento(char* path, char* name, int size) {
	this->path = new char[strlen(path)+1];
	strcpy(this->path,path);
	this->name = new char[strlen(name)+1];
	strcpy(this->name,name);
	this->size = size;	
}

Documento::~Documento() {
	delete this->path[];
	delete this->name[];
}
