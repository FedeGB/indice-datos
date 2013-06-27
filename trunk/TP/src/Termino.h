#ifndef TERMINO_H
#define TERMINO_H
#include <string>
#include <set>
#include <iostream>

class Localizacion;
class Termino;

class Ordenamiento {
	private:
		Ordenamiento();
	public:
	virtual ~Ordenamiento();
	static bool ordenarTerminoAlfabeticamente(const Termino &primer, const Termino &segundo);
	static bool ordenarPorNumeroDoc(const Localizacion &primer, const Localizacion &segundo);
	static bool ordenarNumericamente(const int primer, const int segundo);
	
};

class Termino {
	public:
		std::string termino;
		unsigned long int frecuenciaGlobal;
		std::set< Localizacion, bool (*)(const Localizacion &primer, const Localizacion &segundo) > localizaciones;
		
		Termino(const std::string &str);
		
		void aumentarFrecuencia();
		
		
		void agregarLocalizacion(Localizacion &local);
		
		virtual ~Termino();
};

class Localizacion {
	public:
		std::set< int, bool (*)(const int primer, const int segundo) > posiciones;
		int numeroDoc;
		int frecuenciaLocal;
		
		Localizacion(int numeroDoc);
		void agregarPosicion(int pos);
		void aumentarFrecuencia();
		void unirLocalizacion(Localizacion &local);
		
		
		virtual ~Localizacion();
	
};

#endif
