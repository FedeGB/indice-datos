#include "Termino.h"
#include <set>


Termino::Termino(const std::string &str): termino(str) {
	frecuenciaGlobal = 1;
	
}

Termino::~Termino() { }

void Termino::aumentarFrecuencia() {
	frecuenciaGlobal++;
}

void Termino::agregarLocalizacion(Localizacion &local) {
	std::pair< std::set< Localizacion >::iterator, bool > retorno;
	retorno = localizaciones.insert(local);
	if(!retorno.second) {
		(*retorno.first).unirLocalizacion(local);
	}
}
	

void Localizacion::unirLocalizacion(Localizacion &local) {
	std::set< int >::iterator iter = local.posiciones.begin();
	while(iter != local.posiciones.end()) {
		posiciones.insertar(*iter);
		aumentarFrecuencia();
		iter++;		
	}
}


Localizacion::Localizacion(int numeroDoc): numeroDoc(numeroDoc) {
	frecuenciaLocal = 1;
}

void Localizacion::aumentarFrecuencia() {
	frecuenciaLocal++;
}

Localizacion::~Localizacion() { }

int Localizacion::agregarPosicion(int pos) {
	posiciones.insert(pos);
}

bool Ordenamiento::ordenarPorNumeroDoc(const Localizacion &primer, const Localizacion &segundo) {
	if(primer.numeroDoc <= segundo.numeroDoc) 
		return true;
	return false;
}

bool Ordenamiento::ordenarNumericamente(const int primer, const int segundo) {
	if(primer <= segundo)
		return true;
	return false;
}

bool Ordenamiento::ordenarTerminoAlfabeticamente(const Termino &primer, const Termino &segundo) {
	if(primer.termino.compare(segundo.termino) <= 0)
		return true;
	return false;
}
