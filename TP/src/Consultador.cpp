#include "Consultador.h"
#include "RetornoCodigos.h"

#include <list>
#include <string>

Consultador::Consultador(const std::string &indiceNombre, const std::string &repositorioRuta)
    : indiceNombre(indiceNombre), repositorioRuta(repositorioRuta) {
  std::cout << "Ejecutando Consutlador::Consultador()." << std::endl;
}

Consultador::~Consultador() { }

int Consultador::abrirIndice() {
  std::cout << "Ejecutando Consultador::abrirIndice()." << std::endl;
  return RESULTADO_OK;
}

int Consultador::consultar(std::list< std::string > listaTerminos) {
  std::cout << "Ejecutando Consultador::consultar()." << std::endl;
  return RESULTADO_OK;
}
