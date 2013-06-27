#ifndef TERMINO_H
#define TERMINO_H
#include <string>
#include <set>

bool ordenarNumericamente(const int primer, const int segundo);

class Localizacion {
	public:
		std::set< int, bool (*)(const int primer, const int segundo) > posiciones(ordenarNumericamente);
		int numeroDoc;
		int frecuenciaLocal;
		
		Localizacion(int numeroDoc);
		void agregarPosicion(int pos);
		void aumentarFrecuencia();
		bool ordenarPorNumeroDoc(const Localizacion &primer, const Localizacion &segundo);
		void unirLocalizacion(Localizacion &local);
		
		virtual ~Localizacion();
	
};

class Termino {
	public:
		std::string termino;
		unsigned long int frecuenciaGlobal;
		std::set< Localizacion, bool (*)(const Localizacion &primer, const Localizacion &segundo) > localizaciones(ordenarPorNumeroDoc);
		
		Termino(const std::string &str);
		
		void aumentarFrecuencia();
		
		bool ordenarTerminoAlfabeticamente(const Termino &primer, const Termino &segundo);
		
		void agregarLocalizacion(Localizacion &local);
		
		virtual ~Termino();
};

#endif
