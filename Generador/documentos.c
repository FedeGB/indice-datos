#include <stdlib.h>
#include <string.h>
#include "documentos.h"

// Estructuras para documentos
struct documento {
	char* path;
	char* name;
	int size;
	int num;
};

// Primitivas

doc_t* crear_documento(char* path, char* name,int size) {
	
	doc_t* doc = malloc(sizeof(struct documento));
	if(!doc)
		return NULL;
	doc->path = malloc(sizeof(char)*(strlen(path)+1));
	if(!doc->path) {
		free(doc);
		return NULL;
	}
	strcpy(doc->path,path);
	doc->name = malloc(sizeof(char)*(strlen(name)+1));
	if(!doc->name) {
		free(doc);
		free(doc->path);
		return NULL;
	}
	strcpy(doc->name,name);
	
	doc->size = size;
	doc->num = -1;
	
	return doc;
}

char* nombre_documento(doc_t* doc) {
	if(!doc)
		return NULL;
	return doc->name;
}

char* path_documento(doc_t* doc) {
	if(!doc)
		return NULL;
	return doc->path;
}

int size_documento(doc_t* doc) {
	if(!doc)
		return -1;
	return doc->size;
}

void set_numero_documento(doc_t* doc, int numero) {
	if(!doc)
		return;
	doc->num = numero;
	return;
}

int numero_documento(doc_t* doc) {
	if(!doc)
		return RES_NULL;
	return doc->num;
}

void destruir_documento(doc_t* doc) {
	doc_t* docu = (doc_t*)doc;
	free(docu->path);
	free(docu->name);
	free(docu);
	return;
}
