#include "lista_enlazada.h"
#include <stdlib.h>

/* ***********************************
 * 				Estructuras
 * ***********************************/


struct _nodo {
	void* dato;
	struct _nodo* siguiente;
};

struct _lista {
	size_t tam;
	struct _nodo* primer;
	struct _nodo* ultimo;
}; // lista_t

struct _iter_lista {
	struct _nodo* actual;
	struct _nodo* anterior;
}; // iter_lista_t

struct _lista_ordenada {
	struct _lista* lista;
	cmp_func_t cmp;
}; // order_list_t


/* ***********************************
 * 			Primitivas lista
 * ***********************************/

// Crea una lista y devuelve un puntero
lista_t* crear_lista() {
	lista_t* list = malloc(sizeof(struct _lista));
	if (list == NULL)
		return NULL;
	list->tam = 0;
	list->primer = NULL;
	list->ultimo = NULL;
	
	return list;
}

// Devuelve el largo de la lista
size_t lista_len(const lista_t* list) {
	return list->tam;
}

// Devuelve true si la lista esta vacia o false si tiene elementos
// Pre: La lista fue creada
// Post: Devuelve true en caso de estar vacia, false en caso contrario
bool lista_vacia(const lista_t* list) {
	return (bool)(list->tam == 0);
}

// Agrega un dato al final de la lista.
// Pre: la lista fue creada y el dato es un puntero a void.
// Post: Devuelve true en caso satisfactorio
bool lista_agregar_final(lista_t* list, void* dato) {
	if(!list)
		return false;
	
	struct _nodo* nodo = malloc(sizeof(struct _nodo));
	
	if(!nodo)
		return false;
	
	nodo->dato = dato;
	nodo->siguiente = NULL;
		
	if(!list->primer) {
		list->primer = nodo;
	}
	if(list->ultimo) {
		list->ultimo->siguiente = nodo;
	}
	list->ultimo = nodo;
	list->tam++;
	
	return true;
}

// Agrega un elemento al inicio de la lista
// Pre: la lista fue creada y el dato es un puntero a void.
// Post: Devuelve true en caso satisfactorio
bool lista_agregar_inicio(lista_t* list, void* dato) {
	if(!list)
		return false;
	
	struct _nodo* nodo = malloc(sizeof(struct _nodo));
	
	if(!nodo)
		return false;
	
	nodo->dato = dato;
	nodo->siguiente = list->primer;
		
	if(!list->primer) {
		list->ultimo = nodo;
	}
	list->primer= nodo;
	list->tam++;
	
	return true;
}

// Quita el primer elemento de la lista
// Pre: La lista fue creada y tiene elementos
// Post: Devuelve el elemento en caso satisfactorio, NULL en otro caso
void* lista_borrar_primer(lista_t* list) {
	if(!list)
		return NULL;
	if(lista_vacia(list))
		return NULL;
		
	struct _nodo* nodo_aux = list->primer;
	list->primer = nodo_aux->siguiente;
	if(!list->primer)
		list->ultimo = NULL;
	list->tam--;
	void* dato_aux = nodo_aux->dato;
	free(nodo_aux);
	
	return dato_aux;
}

// Destuye la lista. En caso de necesitar destruir los datos, la funcion
// destruir dato debe proveerse.
void lista_destruir(lista_t* list, void destruir_dato(void*)) {
	if(!list)
		return;
	while(!lista_vacia(list)) {
		void* dato = lista_borrar_primer(list);
		
		if(destruir_dato)
			destruir_dato(dato);
	}
	free(list);
	return;
}


/* ***********************************
 * 			Primitivas iterador
 * ***********************************/
 
// Crea un iterador y devuelve un puntero al mismo en caso satisfactorio
iter_lista_t* crear_iterador_lista(const lista_t* list) {	
	if(!list)
		return NULL;
		
	if(lista_vacia(list)) // Si la lista esta vacia
		return NULL;	// No hay nada que iterar
	
	iter_lista_t* iter = malloc(sizeof(struct _iter_lista));
	
	if(!iter)
		return NULL;
	iter->actual = list->primer;
	iter->anterior = NULL;
	
	return iter;	
}

// Devuelve true si el iterador se encuentra al final de la lista
// false en caso contrario
bool iter_lista_final(iter_lista_t* iter) {
	return (bool)(iter->actual == NULL);
}

// Avanza una posicion en la iteracion
// Devuelve true en caso satisfactorio, false en caso contrario
bool iter_lista_avanzar(iter_lista_t* iter) {
	if(!iter)
		return false;
	if(iter->actual == NULL)
		return false;
		
	iter->anterior = iter->actual;
	iter->actual = iter->actual->siguiente;
	
	return true;
}

// Devuelve el elemento de la posicion en la cual se encuentra el iterador
void* iter_lista_ver_actual(iter_lista_t* iter) {
	if(!iter)
		return NULL;
	if(iter->actual != NULL)
		return iter->actual->dato;
	return NULL;
}

// Destruye el iterador
void iter_lista_destruir(iter_lista_t* iter) {
	if(!iter)
		return;
	free(iter);
	return;
}


/* ***********************************
 * 		Primitivas ordenamiento
 * ***********************************/

order_list_t* crear_lista_ordenada(cmp_func_t cmp) {
	if(!cmp)
		return NULL;
	
	order_list_t* lista_ordenada = malloc(sizeof(struct _lista_ordenada));
	
	if(!lista_ordenada)
		return NULL;
	
	lista_t* lista = crear_lista();
	
	if(!lista) {
		free(lista_ordenada);
		return NULL;
	}
	lista_ordenada->lista = lista;
	lista_ordenada->cmp = cmp;
	
	return lista_ordenada;
}

bool lista_agregar_ordenado(order_list_t* list, void* dato) {
	
	if(!list)
		return false;
	
	if(lista_vacia(list->lista)) {
		return lista_agregar_final(list->lista,dato);
	}
	
	struct _nodo *actual, *anterior;
	struct _nodo* nuevo = malloc(sizeof(struct _nodo));
	if(!nuevo)
		return false;
	nuevo->dato = dato;
	
	actual = list->lista->primer;
	anterior = NULL;
	
	if(list->cmp(dato,actual->dato) >= 0) {
		if(actual == list->lista->primer) {
			nuevo->siguiente = list->lista->primer;
			list->lista->primer = nuevo;
			return true;
		}
	}

	while(actual != NULL) {
		if(list->cmp(dato,actual->dato) >= 0) {
			nuevo->siguiente = actual;
			anterior->siguiente = nuevo;
			list->lista->tam++;
			return true;
		}
		anterior = actual;
		actual = actual->siguiente;
	}
	
	nuevo->siguiente = NULL;
	anterior->siguiente = nuevo;
	list->lista->ultimo = nuevo;
	
	return true;			
}

const lista_t* obtener_lista(order_list_t* list) {
	return list->lista;
}

void destruir_lista_ordenada(order_list_t* list, void destruir_dato(void*)) {
	if(!list)
		return;
	lista_destruir(list->lista,destruir_dato);
	return;
}
