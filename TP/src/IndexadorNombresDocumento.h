#ifndef INDEXADORNOMBRESDOCUMENTO_H_
#define INDEXADORNOMBRESDOCUMENTO_H_

/*
 * IndexadorNombresDocumento.h
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./Documento.h"

class IndexadorNombresDocumento {
  public:
    IndexadorNombresDocumento();
    virtual ~IndexadorNombresDocumento();

    void indexar(const Documento &documento);
};

#endif /* INDEXADORNOMBRESDOCUMENTO_H_ */
