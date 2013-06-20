#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include "codigos_retorno.c"
#include "documentos.h"
#include "lista_enlazada.h"
#include "codificacion.c"
#include "front_coding.c"

#define BUFF_SIZE 500
#define BUFF_LINEA 100

int leerColeccionPath(char* ruta, order_list_t* alfa_list, order_list_t* biggersize_list);
int doc_merge(char** inputs, int cant_i, char* output);
int fsize(FILE *fp);
int cmp_alfa(const void* doc1,const void* doc2);
int cmp_bsize(const void* doc1, const void* doc2);
void removerSalto(char* str);


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

// Funcion de merge para varios archivos
// Devuelve el codigo de retorno correspondiente.
// Pre: Recibe un array de strings con los nombres de los documentos de entrada
// (incluyendo extension), la cantidad y el nombre del documento de salida (con extension)
// Post: RES_OK (merge satisfactorio), 
// RES_NULL (No se puedo o abrir algun archivo de entrada o crear el archivo de salida)
int doc_merge(char** inputs, int cant_i, char* output) {
	FILE* input_vec[cant_i];
	FILE* fo = fopen(output,"w");
	if(!fo)
		return RES_NULL;
	int i;
	for(i = 0; i < cant_i; i++) {
		input_vec[i] = fopen(inputs[i],"r");
		if(!input_vec[i]) {
			for(int x = 0; x < i; x++)
				fclose(input_vec[x]);
			fclose(fo);
			return RES_NULL;
		}
	}
	
	char lineas[cant_i][BUFF_LINEA];
	char* status;
	for(i = 0; i < cant_i; i++) {
		status = fgets(lineas[i], BUFF_LINEA, input_vec[i]);
	}
	int eof = 0;
	int n_menor = 0;
	while(1) {
		for(i = 0; i < cant_i; i++) {
			if(feof(input_vec[i]))
				eof++;
		}
		if(eof == cant_i) {
			break;
		}
		else {
			eof = 0;
		}		
		for(i = 0; i < cant_i; i++) {
			if((!feof(input_vec[i])) && (i != n_menor)) {
				if(strcmp(lineas[i],lineas[n_menor]) < 0) {
					n_menor = i;
				}
			}
			// En caso de ser iguales para los terminos seria sumarle uno a la frecuencia del mismo
			// lo cual quizas podriamos solucionar pasando o no una funcion o algo a parte
		}
		fprintf(fo,"%s",lineas[n_menor]);
		status = fgets(lineas[n_menor],BUFF_LINEA,input_vec[n_menor]);
		if(feof(input_vec[n_menor])) {
			for(i = 0; i < cant_i; i++) {
				if(!feof(input_vec[i])) {
					n_menor = i;
					break;
				}
			}
		}
	}
	for(i = 0; i < cant_i; i++)
		fclose(input_vec[i]);
	fclose(fo);
	
	return RES_OK;
}

int pasada_Documentos(order_list_t* alfa_list) {
	if(!alfa_list)
		return RES_ERROR;
	FILE* predoc = fopen("predoc.ax", "w");
	if(!predoc)
		return RES_NULL;
	iter_lista_t* iter = crear_iterador_lista(obtener_lista(alfa_list));
	doc_t* actual = NULL;
	int n_act = 1;
	
	while(!iter_lista_final(iter)) {
		actual = (doc_t*)iter_lista_ver_actual(iter);
		set_numero_documento(actual, n_act);
		fprintf(predoc, "%s\n", (char*)nombre_documento(actual));
		n_act++;
		iter_lista_avanzar(iter);
	}
	iter_lista_destruir(iter);
	fclose(predoc);
	predoc = fopen("predoc.ax", "r");
	if(!predoc)
		return RES_NULL;
	int sts = FCP_docs(predoc, "doc.char", "doc.dif", "doc.off", (int)lista_len(obtener_lista(alfa_list)));
	if(sts != RES_OK) {
		fclose(predoc);
		return sts;
	}
	// Borrar documento predoc.ax
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

// Remueve los '\n' de la cadena que se le pase por parametro.
void removerSalto(char* str){
	
	str[strcspn ( str, "\n" )] = '\0';
}
