#include <dirent.h>
#include <string.h>
#include "../indice-datos/codigos_retorno.h"
#include "documentos.h"

#define BUFF_SIZE 500

// Funcion que lee la coleccion de documentos.
// Soporta tener subdirectorios (no tiene resolucion de bucle por accesos directos)
// Devuelve RES_NULL en caso de que la ruta es un archivo y no un directorio
int leerColeccionPath(char* ruta){

	if(!path) return RES_ERROR;
	
	char path[BUFF_SIZE];
	
	strncpy(path, ruta, strlen(ruta));

	DIR* directorio = opendir(path);
	if(!directorio) {
		return RES_NULL;
	}

	struct dirent* file;
	char aux[BUFF_SIZE];
	char antes[BUFF_SIZE];
	FILE* arch;
	doc_t* doc_ac = NULL;
	int size = 0;
	
	strncpy(antes, path, strlen(path));	//Carpeta base

	while(1) {
		file = readdir(directorio);
		if(!file) return RES_ERROR;
		if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0)
			continue;
		snprintf(aux, strlen(antes)+strlen(file->d_name)+2, "%s/%s", antes, file->d_name);
		strcpy(path,aux);
		if(leerColeccionPath(path) != RES_OK){ //Si no es un directorio continuamos a procesar el archivo
			arch = fopen(path,"r");
			if(!arch)
				return RES_NULL;
			
			size = fsize(arch);
			doc_ac = crear_documento(path,file->d_name,size);
			// Metemos documento en una lista de forma que se ordene por "size" de mayor a menor
			// Y metemos en otra que lo ordene en orden alfabetico
			
			
		}		

	}
	closedir(directorio);
	return RES_OK;
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
