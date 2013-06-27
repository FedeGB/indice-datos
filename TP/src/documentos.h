#ifndef DOCUMENTOS_H
#define DOCUMENTOS_H

/*
 * documentos.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <string>

class Documentos {
	public:
		char* path;
		char* name;
		int size;
		static int serial;
		
		Documentos(char* path, char* name, int size);
		virtual ~Documentos();
	
};

#endif
