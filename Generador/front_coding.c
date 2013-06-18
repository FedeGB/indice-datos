#include "lista_enlazada.h"

void removerSalto(char* str);

int FCP(FILE* input, char* ar_chars, char* ar_i_d, char* ar_off, int total) {
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
	

int FC(const lista_t* list, FILE* chars, FILE* igual_dif, FILE* offsets, int tam_bloq) {
	
	
	return RES_OK;
}

// Remueve los '\n' de la cadena que se le pase por parametro.
void removerSalto(char* str){
	
	str[strcspn ( str, "\n" )] = '\0';
}
