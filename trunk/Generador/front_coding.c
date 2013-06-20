#include "lista_enlazada.h"
#include "codificacion.c"
#define BUFF_LINEA 100

int FCP(FILE* input, char* ar_chars, char* ar_i_d, char* ar_off, int total);
int FC(const lista_t* list, FILE* chars, FILE* igual_dif, FILE* offsets, int tam_bloq);
int tamanyo_bloque_FCP(int cantidad);
void removerSalto(char* str);

int FCP_docs(FILE* input, char* ar_chars, char* ar_i_d, char* ar_off, int total) {
	int tam = tamanyo_bloque_FCP(total);
	char linea[BUFF_SIZE];
	char* str;
	memset(linea, '\0', BUFF_SIZE);
	int cont, status;
	status = 0;
	FILE *chars, *i_d, *off;
	
	chars = fopen(ar_chars, "a");
	if(!chars)
		return RES_NULL;
	i_d = fopen(ar_i_d, "a");
	if(!i_d) {
		fclose(chars);
		return RES_ERROR;
	}
	off = fopen(ar_off, "ab");
	if(!off) {
		fclose(chars);
		fclose(i_d);
		return RES_ERROR;
	}
	
	lista_t* parcial = crear_lista();
	while(!feof(input)) {
		if(cont >= tam) {
			FC(parcial, chars, i_d, off, tam);
			cont = 0;
			lista_destruir(parcial, NULL);
			parcial = crear_lista();
			continue;
		}
		status = fgets(linea, BUFF_SIZE, input);
		removerSalto(linea);
		str = malloc(sizeof(char)*(strlen(linea)+1));
		strcpy(str, linea);
		lista_agregar_final(parcial, str);
		cont++;
	}
	
	if(parcial) {
		if(!lista_vacia(parcial))
			FC(parcial, chars, i_d, off, tam);
		lista_destruir(parcial, NULL);
	}

	return RES_OK;
}
	

int FC_docs(const lista_t* list, FILE* chars, FILE* igual_dif, FILE* offsets, int tam_bloq) {
	iter_lista_t* iter = crear_iterador_lista(list);
	uchar cod_chars[BUFF_LINEA];
	uchar cod_id[BUFF_LINEA];
	char actual[BUFF_LINEA];
	char anterior[BUFF_LINEA];
	memset(actual, '\0', BUFF_LINEA);
	memset(anterior, '\0', BUFF_LINEA);
	strcpy(actual, (char*)iter_lista_ver_actual(iter));
	int* dif = NULL;
	long int offset_chars = ftell(chars);
	long int offset_id = ftell(igual_dif);
	fprintf(chars, "%s", actual); // Primero del bloque es el de 0 char == forzado
	dif = diferencias(anterior, actual);
	delta_code(offset_chars, cod_chars);
	delta_code(offset_id, cod_id); // Este es para el de iguales, hay q hacerlo de nuevo para el de distintos
	// Escribir los codigos al archivo offsets e igual_dif
	
	iter_lista_avanzar(iter);
	while(!iter_lista_final(iter)) {
		strcpy(actual, (char*)iter_lista_ver_actual(iter));
		dif = diferencias(anterior, actual);
		offset_chars = ftell(chars);
		offset_id = ftell(igual_dif);
		delta_code(offset_chars, cod_chars);
		delta_code(offset_id, cod_id);
		// Escribir substring a chars, codigos a offsets y igual_dif
		
		strcpy(anterior, actual);
		iter_lista_avanzar(iter);
	}
	iter_lista_destruir(iter);
	
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

int* diferencias(char* str1, char* str2) {
	int dif[2] = {0, 0}; // igual,distinto
	int x = 0;
	while(str1[x] != '\0' || str2[x] != '\0') {
		if(str1[x] == str2[x]) {
			dif[0]++;
		}
		else {
			dif[1] = strlen(str2) - dif[0];
			break;
		}
		x++;
	}
	return dif;
}

// Remueve los '\n' de la cadena que se le pase por parametro.
void removerSalto(char* str){
	
	str[strcspn ( str, "\n" )] = '\0';
}
