#ifndef DOCUMENTOS_H_
#define DOCUMENTOS_H_

/*
 * Documento.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include <string>

class Documento {
  public:
    std::string nombre;
    unsigned int tamanyo;
    int serial;

    Documento(const std::string &nombre, const unsigned int tamanyo, const int serial);

    virtual ~Documento();

    static bool ordenadorDeDocumentosPorTamanyo(const Documento &primero, const Documento &segundo);
};

#endif /* DOCUMENTOS_H_ */
