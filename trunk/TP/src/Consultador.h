#ifndef CONSULTADOR_H
#define CONSULTADOR_H

#include <iostream>
#include <list>

class Consultador {
	public:
		std::string indiceNombre;
		std::string repositorioRuta;
		
		Consultador(const std::string &indiceNombre, const std::string &indiceRuta);
		
		int abrirIndice();
		
		int consultar( std::list< std::string > listaTerminos);
		
		virtual ~Consultador();
	
};


#endif
