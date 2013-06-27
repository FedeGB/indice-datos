/*
 * Codigos.cpp
 *
 *  Created on: 27 Jun 2013
 *      Author: GRUPO 19
 */

#include "./Codigos.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#define MAX 50

// Clase CDelta

CDelta::CDelta(unsigned long int numero) {
  uchar delta[MAX];
  bits = base_code(numero, gamma_code, delta);
  bytes = (bits / 8);
  if (bits % 8 != 0) bytes += 1;
  codigo = new uchar[bytes];
  escribirBinario(codigo, delta, bits);
}

CDelta::~CDelta() {
  delete[] codigo;
}

void CDelta::escribirBinario(uchar* binario, uchar* code, size_t bits) {
  uchar buffer = 0;
  int bit_actual = 0;
  int posArray = 0;
  int nByte = 0;
  while (posArray < (int) bits) {
    if ((posArray + 1) % 8 == 0) {
      if (code[posArray] & 1) buffer |= (1 << bit_actual);
      binario[nByte] = buffer;
      nByte++;
      buffer &= 0;
      bit_actual = 0;
      posArray++;
      continue;
    }
    if (code[posArray] & 1) buffer |= (1 << bit_actual);
    posArray++;
    bit_actual++;
  }
  int flag = 0;
  while (posArray % 8 != 0) {
    buffer |= (1 << bit_actual);
    posArray++;
    bit_actual++;
    flag = 1;
  }
  if (posArray % 8 == 0 && flag == 1) {
    binario[nByte] = buffer;
  }
  return;
}


DDelta::DDelta() { }

DDelta::~DDelta() { }

void DDelta::leerBinario(uchar* bytes, size_t nBytes, uchar* buffer) {
	uchar char_buff = 0;
	int bit_actual = 0;
	for(int x = 0; x<(int)nBytes; x++) {
		char_buff = bytes[x];
		while(bit_actual < 8) {	
			if((char_buff & (1<<bit_actual))) {
				buffer[bit_actual+(8*x)] |= '1';
			}
			else {
				buffer[bit_actual+(8*x)] |= '0';
			}
			bit_actual++;
		}
		bit_actual = 0;
		char_buff = 0;
	}
	return;
}

int DDelta::decodificar(uchar* bytes, size_t nBytes, long int* numero) {
	uchar buffer[(8*nBytes)+1];
	memset(buffer, '\0', 8*nBytes);
	leerBinario(bytes, nBytes, buffer);
	buffer[8*nBytes] = '\0';
	int x = 0;
	*numero = delta_decode(buffer, &x);
	return x;	
}

/****************************
 * Funciones codificacion
 *****************************/

int unary_code(long int number, uchar* unary) {
  int x = number - 1;
  int p = 0;
  while (p < x) {
    unary[p] = '1';
    p++;
  }
  unary[x] = '0';
  unary[number] = '\0';
  return (int) number;
}

int binary_code(long int number, int bits, uchar* binary) {
  int division = number;

  for (int x = 0; x < bits; x++) {
    if (division % 2 == 0) {
      binary[x] = '0';
    } else {
      binary[x] = '1';
    }
    division = division / 2;
  }
  binary[bits] = '\0';
  return bits;
}

int base_code(long int number, int func(long int, uchar*), uchar* vec) {
  int bits = (int) floor(log10(number) / log10(2));  // log(number) en base 2
  int q = 1 + bits;
  func(q, vec);

  int bin = number - (int) pow(2, (double) bits);
  uchar binary[bits + 1];
  binary_code(bin, bits, binary);
  int x, i, pre;
  x = i = pre = 0;

  while (!vec[i] == '\0')
    i++;
  pre = i;
  for (int z = i; z < (q + bits + 1); z++) {
    vec[z] = binary[x];
    x++;
  }
  vec[pre + bits] = '\0';
  return (pre + bits);
}

int gamma_code(long int number, uchar* gamma) {
  return base_code(number, unary_code, gamma);
}

/****************************
 * Funciones decodificacion
 *****************************/

long int unary_decode(uchar* unary) {
  int i = 0;
  while (unary[i] != 0)
    i++;
  return i;
}

long int binary_decode(uchar* binary) {
  int x = 0;
  int number = 0;

  while (binary[x] != '\0') {
    if (binary[x] == '1') number += (int) pow(2, (double) x);
    x++;
  }
  return number;
}

long int gamma_decode(uchar* gamma, int* usados) {
  int len_max = strlen((char*) gamma);
  uchar pre[len_max];  // No conozco el maximo a priori pero no es mayor al gamma recibido
  memset(pre, ' ', len_max);
  int x = 0;
  while (gamma[x] != '0') {
    pre[x] = gamma[x];
    x++;
  }
  pre[x] = '0';
  x++;
  pre[x] = '\0';
  int q = unary_decode(pre);
  q = q - 1;
  uchar post[q + 1];
  memset(post, ' ', q + 1);
  int y = x + q;
  int i = 0;
  for (int t = x; t < y; t++) {
    post[i] = gamma[t];
    i++;
  }
  post[i++] = '\0';
  *usados = y;
  return (int) pow(2, (double) q) + binary_decode(post);
}

long int delta_decode(uchar* delta, int* usados) {
  int w = 0;
  int q = gamma_decode(delta, &w);
  q = q - 1;
  uchar post[q + 1];
  memset(post, ' ', q + 1);

  int y = 0;
  int t;
  for (t = w; t < w + q - 1; t++) {
    post[y] = delta[t];
    y++;
  }
  post[y++] = '\0';
  *usados = t++;
  return (int) pow(2, (double) q) + binary_decode(post);
}
