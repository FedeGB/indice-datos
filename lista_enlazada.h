#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <stddef.h>
#include <stdbool.h>

/* ***********************************
 * 		Definicion Estructuras
 * ***********************************/
 
typedef struct _lista lista_t;
typedef struct _iter_lista iter_lista_t;
typedef struct _lista_ordenada order_list_t;

/* Prototipo de función de comparación que se le pasa como parámetro a la
 * lista enlazada
 * Debe recibir dos punteros del tipo de dato utilizado en la lista, y
 * debe devolver:
 *   menor a 0  si  a < b
 *       0      si  a == b
 *   mayor a 0  si  a > b
 */
typedef int (*cmp_func_t) (const void *a, const void *b);


/* ***********************************
 * 			Primitivas lista
 * ***********************************/
 
// Crea una lista y devuelve un puntero
lista_t* crear_lista();

// Devuelve el largo de la lista
size_t lista_len(const lista_t* list);

// Devuelve true si la lista esta vacia o false si tiene elementos
// Pre: La lista fue creada
// Post: Devuelve true en caso de estar vacia, false en caso contrario
bool lista_vacia(const lista_t* list);

// Agrega un dato al final de la lista.
// Pre: la lista fue creada y el dato es un puntero a void.
// Post: Devuelve true en caso satisfactorio
bool lista_agregar_final(lista_t* list, void* dato);
 
// Agrega un elemento al inicio de la lista
// Pre: la lista fue creada y el dato es un puntero a void.
// Post: Devuelve true en caso satisfactorio
bool lista_agregar_inicio(lista_t* list, void* dato);
 
// Quita el primer elemento de la lista
// Pre: La lista fue creada y tiene elementos
// Post: Devuelve el elemento en caso satisfactorio, NULL en otro caso
void* lista_borrar_primer(lista_t* list);
 
// Destuye la lista. En caso de necesitar destruir los datos, la funcion
// destruir dato debe proveerse.
void lista_destruir(lista_t* list, void destruir_dato(void*));
 
 
/* ***********************************
 * 			Primitivas iterador
 * ***********************************/
 
// Crea un iterador y devuelve un puntero al mismo en caso satisfactorio
iter_lista_t* crear_iterador_lista(const lista_t* list);
 
// Devuelve true si el iterador se encuentra al final de la lista
// false en caso contrario
bool iter_lista_final(iter_lista_t* iter);
 
// Avanza una posicion en la iteracion
// Devuelve true en caso satisfactorio, false en caso contrario
bool iter_lista_avanzar(iter_lista_t* iter);

// Devuelve el elemento de la posicion en la cual se encuentra el iterador
void* iter_lista_ver_actual(iter_lista_t* iter);
 
// Destruye el iterador
void iter_lista_destruir(iter_lista_t* iter);


/* ***********************************
 * 		Primitivas ordenamiento
 * ***********************************/
 
// Crea una lista ordenada segun la funcion de comparacion que se le pase
// La lista ordenaria de menor a mayor
// Para que sea de mayor a menor hay que pasar una funcion de comparacion invertida 
order_list_t* crear_lista_ordenada(cmp_func_t cmp);

// Inserta un elemento en la lista de forma ordenada
bool lista_agregar_ordenado(order_list_t* list, void* dato);

// Devuelve la lista_t ordenada (para poder iterar y demas
const lista_t* obtener_lista(order_list_t* list);

// Destruye la lista ordenada. Si se le pasa una funcion
// destuir_dato, tambien los datos son destruidos (se libera memoria y demas)
void destruir_lista_ordenada(order_list_t* list, void destruir_dato(void*));
 
#endif
