#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include "codigos_retorno.c"
#include "documentos.h"
#include "lista_enlazada.h"
#include "codificacion.c"

#define BUFF_SIZE 500

int leerColeccionPath(char* ruta, order_list_t* alfa_list, order_list_t* biggersize_list);
int fsize(FILE *fp);
int cmp_alfa(const void* doc1,const void* doc2);
int cmp_bsize(const void* doc1, const void* doc2);



// Funcion que lee la coleccion de documentos.
// Soporta tener subdirectorios (no tiene resolucion de bucle por accesos directos)
// Devuelve RES_NULL en caso de que la ruta es un archivo y no un directorio
int leerColeccionPath(char* ruta, order_list_t* alfa_list, order_list_t* biggersize_list){

	if(!ruta) return RES_ERROR;
	
	char path[BUFF_SIZE];
	memset(path, ' ',BUFF_SIZE);
	strcpy(path, ruta);

	DIR* directorio = opendir(path);
	if(!directorio) {
		return RES_NULL;
	}

	struct dirent* file;
	char aux[BUFF_SIZE];
	char antes[BUFF_SIZE];
	memset(aux, '\0', BUFF_SIZE);
	memset(antes, '\0', BUFF_SIZE);
	FILE* arch = NULL;
	doc_t* doc_ac = NULL;
	int size = 0;
		
	strncpy(antes, path, strlen(path));	//Carpeta base
	
	// Cargamos y ordenamos documentos con datos que nos interesan.
	while(1) {
		file = readdir(directorio);
		if(!file) break;
		if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0)
			continue;
		snprintf(aux, strlen(antes)+strlen(file->d_name)+2, "%s/%s", antes, file->d_name);
		memset(path, '\0', BUFF_SIZE);
		strcpy(path,aux);
		if(leerColeccionPath(path) != RES_OK){ //Si no es un directorio continuamos a procesar el archivo
			arch = fopen(path,"r");
			if(!arch)
				return RES_NULL;
			size = fsize(arch);
			doc_ac = crear_documento(path,file->d_name,size);
			lista_agregar_ordenado(alfa_list, doc_ac);
			lista_agregar_ordenado(biggersize_list, doc_ac);
			doc_ac = NULL;
			fclose(arch);
			arch = NULL;
		}
	}
	closedir(directorio);
	return RES_OK;
}

int tamanyo_bloque_FCP(int cantidad) {
	if(cantidad <= 1000) {
		return 100;
	}
	else {
		return (int)(floor((((log10((double)cantidad)/3)-1)*900)+100));
	}
}

// Retorna el peso del archivo
int fsize(FILE* fp) {
	
	if(!fp)
		return RES_NULL;
		
	int size = 0;
	fseek(fp,0,SEEK_END);
	size = ftell(fp);
	fseek(fp,0,SEEK_SET);
	
	return size;
}

// Funcion de comparacion para orden alfabetico
int cmp_alfa(const void* doc1, const void* doc2) {
    return strcmp(nombre_documento((doc_t*)doc1), nombre_documento((doc_t*)doc2));
}

// Funcion de comparacion por tamaño del documento
// Devuelve invertido a lo que se supone que deben devolver las funciones cmp
// Pues la lista ordena de menor a mayor, por ende para ordenarlo de mayor a menor
// unicamente invertimos las devoluciones de las funciones cmp
int cmp_bsize(const void* doc1, const void* doc2) {
	if(size_documento((doc_t*)doc1) < size_documento((doc_t*)doc2)) {
		return 1;
	}
	if(size_documento((doc_t*)doc1) > size_documento((doc_t*)doc2)) {
		return -1;
	}
	else {
		return 0;
	}
}
