#ifndef DOCUMENTOS_H
#define DOCUMENTOS_H

// Redefinicion de estructura
typedef struct documento doc_t;

// Primitivas

// Crea un documento con path, name y su peso
// Devuelve NULL en caso de error
doc_t* crear_documento(char* path, char* name,int size);

// Devuelve el nombre del documento
// Devuelve NULL en caso de error
char* nombre_documento(doc_t* doc);

// Devuelve el path al documento
// Devuelve NULL en caso de error
char* path_documento(doc_t* doc);

// Devuelve el peso del documento
// Devuelve NULL en caso de error
int size_documento(doc_t* doc);

// Destruye y libera la memoria allocada
void destruir_documento(doc_t* doc);

#endif
