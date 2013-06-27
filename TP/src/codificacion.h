#ifndef CODIFICACION_H
#define CODIFICACION_H

typedef unsigned char uchar;

class CDelta {
	private:
		uchar *codigo;
		int bits;
		int bytes;
		
		// Escribe un numero en unario
		// recibe un buffer en donde depositara el codigo unario
		int unary_code(long int number, uchar* unary);
		
		// Escribe un numero en binario con la cantidad de bits pedida
		// Recibe un buffer en donde depositara el codigo binario
		// Pre: el numero debe poder representarse con la cantidad de bits indicada
		// Post: El codigo binario devuelto se lee de izquierda a derecha
		int binary_code(long int number, int bits, uchar* binary);
		
		// Funcion que genera un codigo con una primera parte en codigo especificado (func)
		// y la segunda parte en codigo binario
		int base_code(long int number, int func(long int,uchar*), uchar* vec);
		
		// Escribe un numero en codigo gamma
		// Recibe un buffer en el cual se depositara el codigo gamma
		int gamma_code(long int number, uchar* gamma);
		
		// Escribe un codigo a una tira de bytes
		void escribirBinario(uchar* bytes, uchar* code, size_t size);
		
	public:
		
		// Constructor de la clase
		CDelta(unsigned long int numero);
		
		virtual ~CDelta();


#endif
