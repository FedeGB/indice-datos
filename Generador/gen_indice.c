#include "gen_coleccion.c"
#include "codigos_retorno.c"

#define ARGC 3

int main(int argc, char** argv) {
	if(argc != ARGC) {
		printf("Faltan o hay parametros demás\n");
		return RES_ERROR;
	}
	
	order_list_t* alfa_list = crear_lista_ordenada(cmp_alfa);
	order_list_t* biggersize_list = crear_lista_ordenada(cmp_bsize);
	if(leerColeccionPath(argv[2], alfa_list, biggersize_list) != RES_OK) {
		printf("Error al leer la colección\n");
		destruir_lista_ordenada(alfa_list, NULL);
		destruir_lista_ordenada(biggersize_list,(void(*)(void*))destruir_documento);
		return RES_NULL;
	}
	if(pasada_Documentos(alfa_list) != RES_OK) {
		printf("Error al leer o escribir archivos\n");
		destruir_lista_ordenada(alfa_list, NULL);
		destruir_lista_ordenada(biggersize_list,(void(*)(void*))destruir_documento);
		return RES_NULL;
	}
	
	destruir_lista_ordenada(alfa_list, NULL);
	destruir_lista_ordenada(biggersize_list,(void(*)(void*))destruir_documento);
	
	
	return 0;
}
