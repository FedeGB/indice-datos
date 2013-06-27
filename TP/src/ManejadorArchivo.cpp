/*
 * ManejadorArchivo.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./ManejadorArchivo.h"
#include <cstring>
#include <fstream>

#include <iostream>

ManejadorArchivo::ManejadorArchivo(const std::string &rutaConNombre)
    : rutaConNombre(rutaConNombre), archivoHandler(rutaConNombre.c_str(), std::fstream::out | std::fstream::in), buffer(), bitsEnBuffer(0) {
  //std::cout << "Ejecutando ManejadorArchivo::ManejadorArchivo()." << std::endl;
  std::cout << "Creado el archivo: " << rutaConNombre << std::endl;
}

ManejadorArchivo::~ManejadorArchivo() {
  //std::cout << "Ejecutando ManejadorArchivo::~ManejadorArchivo()." << std::endl;
}

void ManejadorArchivo::escribirBinario(const unsigned char * const datos, const int cantidadBits) {
  //std::cout << "Ejecutando ManejadorArchivo::escribir()." << std::endl;
  //std::cout << "Escribir binario: \"" << (int) *datos << "\" de largo: " << cantidadBits << std::endl;
  if (cantidadBits == 0) {
    throw 666;
  }
  const unsigned char *pDatos = datos;
  int cantidadBitsPorRecibir = cantidadBits;
  if (bitsEnBuffer == 0) {
    // Si el buffer está vacío.
    while (cantidadBitsPorRecibir >= 8) {
      archivoHandler << (*pDatos);

      //std::cout << (int) (*pDatos) << "------1-------" << (int) (*buffer) << std::endl;

      ++pDatos;
      cantidadBitsPorRecibir -= 8;
    }
  } else {
    // Si el buffer no está vacío.
    while (cantidadBitsPorRecibir >= 8) {
      unsigned char auxiliar = (*pDatos);
      auxiliar <<= bitsEnBuffer;
      // Una máscara 10000000.
      unsigned char mascara = 0x80;
      for (int contador = (8 - bitsEnBuffer - 1); contador > 0; --contador) {
        mascara |= (mascara >> 1);
      }
      (*buffer) |= (mascara & auxiliar);
      archivoHandler << (*buffer);
      auxiliar = (*pDatos);
      auxiliar >>= (8 - bitsEnBuffer);
      mascara = ~mascara;
      (*buffer) = (mascara & auxiliar);

      //std::cout << (int) (*pDatos) << "------2-------" << (int) (*buffer) << std::endl;

      ++pDatos;
      cantidadBitsPorRecibir -= 8;
    }
  }
  int cantidadBitsPorEscribir = cantidadBitsPorRecibir + bitsEnBuffer;
  if (cantidadBitsPorEscribir >= 8) {
    // Escribo 8 bits más y termino de acomodar (obviamente el buffer no está vacío).
    unsigned char auxiliar = (*pDatos);
    auxiliar <<= bitsEnBuffer;
    // Una máscara 10000000.
    unsigned char mascara = 0x80;
    for (int contador = (8 - bitsEnBuffer - 1); contador > 0; --contador) {
      mascara |= (mascara >> 1);
    }
    (*buffer) |= (mascara & auxiliar);

    //std::cout << (int) (*pDatos) << "------3-------" << (int) (*buffer) << std::endl;

    archivoHandler << (*buffer);
    cantidadBitsPorEscribir -= 8;
    if (cantidadBitsPorEscribir > 0) {
      // Termino de acomodar.
      // Moverlos de pDatos al punto del buffer donde termina lo que ya tengo, y actualizar bitsEnBuffer.
      unsigned char auxiliar = (*pDatos);
      auxiliar >>= (8 - bitsEnBuffer);
      // Una máscara 00000001.
      unsigned char mascara = 0x01;
      for (int contador = (cantidadBitsPorEscribir - 1); contador > 0; --contador) {
        mascara |= (mascara << 1);
      }
      (*buffer) = (mascara & auxiliar);

      //std::cout << (int) (*pDatos) << "------4-------" << (int) (*buffer) << std::endl;

      bitsEnBuffer = cantidadBitsPorEscribir;
    } else {
      *buffer = 0x00;

      //std::cout << (int) (*pDatos) << "------5-------" << (int) (*buffer) << std::endl;

      bitsEnBuffer = 0;
    }
  } else {
    // Ya no puedo escribir más, tengo que ordenar los bits que me sobraron.
    if (cantidadBitsPorRecibir > 0) {
      // Me quedan en la entrada, los termino de acomodar.
      if (bitsEnBuffer == 0) {
        // Si el buffer está vacío.
        // Una máscara 00000001.
        unsigned char mascara = 0x01;
        for (int contador = (cantidadBitsPorRecibir - 1); contador > 0; --contador) {
          mascara |= (mascara << 1);
        }
        (*buffer) = (mascara & (*pDatos));

        //std::cout << (int) (*pDatos) << "------6-------" << (int) (*buffer) << std::endl;

      } else {
        // Si el buffer no está vacío.
        // Moverlos de pDatos al punto del buffer donde termina lo que ya tengo, y actualizar bitsEnBuffer.
        unsigned char auxiliar = (*pDatos);
        auxiliar <<= bitsEnBuffer;
        // Una máscara 00000001.
        unsigned char mascara = 0x01;
        mascara <<= bitsEnBuffer;
        for (int contador = (cantidadBitsPorRecibir - 1); contador > 0; --contador) {
          mascara |= (mascara << 1);
        }
        (*buffer) |= (mascara & auxiliar);

        //std::cout << (int) (*pDatos) << "------7-------" << (int) (*buffer) << std::endl;

      }
      bitsEnBuffer = cantidadBitsPorEscribir;
    }
  }
}

void ManejadorArchivo::escribirSinCodificar(const std::string &cadena) {
  //std::cout << "Ejecutando ManejadorArchivo::escribirSinCodificar()." << std::endl;
  if (bitsEnBuffer != 0) {
    throw 666;
  }
  std::cout << "  Escribo: " << cadena << std::endl;
  archivoHandler << cadena;
}

void ManejadorArchivo::close() {
  //std::cout << "Ejecutando ManejadorArchivo::close()." << std::endl;
  if (bitsEnBuffer != 0) {
    // Si me quedan bits en el buffer para grabar...
    // Completo con unos y los grabo.
    // Una máscara 80000000.
    unsigned char mascara = 0x80;
    int rellenar = 8 - bitsEnBuffer;
    while (rellenar > 0) {
      (*buffer) |= mascara;
      mascara >>= 1;
      --rellenar;
    }
    archivoHandler << (*buffer);
    bitsEnBuffer = 0;
  }
  archivoHandler.close();
}
