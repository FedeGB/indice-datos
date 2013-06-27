#ifndef DOCUMENTOS_H
#define DOCUMENTOS_H

/*
 * documentos.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <string>

class Documento {
	public:
		std::string path;
		std::string name;
		int size;
		int serial;
		
		Documento(const std::string &path, const std::string &name, int size);
		void setSerial(int num);
		virtual ~Documento();
	
};

#endif
