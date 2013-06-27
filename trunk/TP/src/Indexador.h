#ifndef INDEXADOR_H_
#define INDEXADOR_H_

/*
 * Indexador.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <list>
#include <string>
#include "./Documento.h"

class Indexador {
  public:
    std::string repositorioNombre;
    std::string repositorioRuta;

    Indexador(const std::string &repositorioNombre, const std::string &repositorioRuta);
    virtual ~Indexador();

    void indexar();
    void generarListadoAlfabeticoDeNombresDeDocumentos(std::list< Documento > &listadoArchivosAlfabetico);
    static int filtro(const struct dirent *pDirent);
};

#endif /* INDEXADOR_H_ */
