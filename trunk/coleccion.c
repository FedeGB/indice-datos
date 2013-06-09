#include <dirent.h>
#include <string.h>
#include "codigos_retorno.h"

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

	strncpy(antes, path, strlen(path));	//Carpeta base

	while(1) {
		file = readdir(directorio);
		if(!file) break;
		if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0)
			continue;
		snprintf(aux, strlen(antes)+strlen(file->d_name)+2, "%s/%s", antes, file->d_name);
		strcpy(path,aux);
		if(leerColeccionPath(path) != RES_OK){ //Si no es un directorio continuamos a procesar el archivo
			// Procesar archivo de la coleccion
		}		

	}
	closedir(directorio);
	return RES_OK;
}
