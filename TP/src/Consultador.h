#ifndef CONSULTADOR_H
#define CONSULTADOR_H

class Consultador {
	public:
		std::string indiceNombre;
		std::string repositorioRuta;
		
		Consultador(const std::string &indiceNombre, const std::string &repositorioRuta);
		
		int abrirIndice();
		
		int consultar( std::list< std::string > listaTerminos);
	
};


#endif
