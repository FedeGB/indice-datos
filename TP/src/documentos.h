#ifndef DOCUMENTOS_H
#define DOCUMENTOS_H
#include <string>

Class Documentos {
	public:
		char* path;
		char* name;
		int size;
		static int serial;
		
		Documentos(char* path, char* name, int size);
		virtual ~Documentos();
	
}

#endif
