/*
 * Indexador.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./Indexador.h"
#include <iostream>

Indexador::Indexador(const std::string &repositorioNombre, const std::string &repositorioRuta)
    : repositorioNombre(repositorioNombre), repositorioRuta(repositorioRuta) {
  std::cout << "Ejecutando Indexador::Indexador()." << std::endl;
}

Indexador::~Indexador() {
  std::cout << "Ejecutando Indexador::~Indexador()." << std::endl;
}

void Indexador::indexar() {
  std::cout << "Ejecutando Indexador::indexar()." << std::endl;
}
