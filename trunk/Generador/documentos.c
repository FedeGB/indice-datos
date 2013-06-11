#include <stdlib.h>
#include <string.h>
#include "documentos.h"

// Estructuras para documentos
struct documento {
	char* path;
	char* name;
	int size;
};

// Primitivas

doc_t* crear_documento(char* path, char* name,int size) {
	
	doc_t* doc = malloc(sizeof(struct documento));
	if(!doc)
		return NULL;
	doc->path = malloc(sizeof(char)*(path+1));
	if(!doc->path) {
		free(doc);
		return NULL;
	}
	doc->name = malloc(sizeof(char)*(name+1));
	if(!doc->name) {
		free(doc);
		free(doc->path);
		return NULL;
	}
		
	strncpy(doc->path,path,strlen(path));
	strncpy(doc->name,name,strlen(name));
	
	doc->size = size;
	
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
		return NULL;
	return doc->size;
}

void destruir_documento(doc_t* doc) {
	free(doc->path);
	free(doc->name);
	free(doc);
	return;
}
