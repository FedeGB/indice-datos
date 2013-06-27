#ifndef INDEXADOR_H_
#define INDEXADOR_H_

/*
 * Indexador.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <list>
#include <set>
#include <string>
#include "./Documento.h"

class Indexador {
  public:
    std::string indiceNombre;
    std::string repositorioRuta;

    Indexador(const std::string &indiceNombre, const std::string &repositorioRuta);

    virtual ~Indexador();

    void indexar(const std::string &archivosSalidaRuta);

    void generarListadoAlfabeticoDeNombresDeDocumentos(std::list< Documento > &listadoDocumentosAlfabetico);

    static int filtro(const struct dirent *pDirent);

    void indexarNombresDeDocumentosYOrdenarPorTamanyo(std::set< Documento, bool (*)(const Documento &primero, const Documento &segundo) > &setDocumentosPorTamanyo, std::list< Documento > &listadoDocumentosAlfabetico, const std::string &archivosSalidaRuta);

    void indexarTerminos(std::set< Documento, bool (*)(const Documento &primero, const Documento &segundo) > &setDocumentosPorTamanyo, const std::string &archivosSalidaRuta);
};

#endif /* INDEXADOR_H_ */
