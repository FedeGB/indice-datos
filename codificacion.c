#include <math.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char uchar;

// Escribe un numero en unario
// recibe un buffer en donde depositara el codigo unario
void unary_code(int number, uchar* unary) {
	int x = number - 1;
	int p = 0;
	while(p < x) {
		unary[p] = '1';
		p++;
	}
	unary[x] = '0';
	unary[number] = '\0';
}

// Decodifica un codigo unario
int unary_decode(uchar* unary) {
	int i = 0;
	while(unary[i] != 0)
		i++;
	return i;
}

// Escribe un numero en binario con la cantidad de bits pedida
// Recibe un buffer en donde depositara el codigo binario
// Pre: el numero debe poder representarse con la cantidad de bits indicada
// Post: El codigo binario devuelto se lee de izquierda a derecha
void binary_code(int number, int bits, uchar* binary) {
	int division = number;
	
	for(int x = 0; x < bits; x++) {
		if(division%2 == 0) {
			binary[x] = '0';
		}
		else {
			binary[x] = '1';
		}
		division = division/2;
	}
	binary[bits] = '\0';
}

// Decodifica un codigo binario
int binary_decode(uchar* binary) {
	int x = 0;
	int number = 0;
	
	while(binary[x] != '\0') {
		if(binary[x] == '1')
			number += (int)pow(2,(double)x);
		x++;
	}
	return number;
}

// Funcion que genera un codigo con una primera parte en codigo especificado (func)
// y la segunda parte en codigo binario
void base_code(int number, void func(int,uchar*), uchar* vec) {
	int bits = (int)floor(log10(number)/log10(2)); // log(number) en base 2
	int q = 1+bits;
	func(q,vec);
	
	int bin = number - (int)pow(2,(double)bits);
	uchar binary[bits+1];
	binary_code(bin,bits,binary);
	int x, i, pre;
	x = i = pre = 0;
	
	while(!vec[i] == '\0')
		i++;
	pre = i;
	for(i; i < (q+bits+1); i++) {
		vec[i] = binary[x];
		x++;
	}
	vec[pre+bits] = '\0';
}

// Escribe un numero en codigo gamma
// Recibe un buffer en el cual se depositara el codigo gamma
void gamma_code(int number, uchar* gamma) {
	base_code(number,unary_code,gamma);
}

// Decodifica un codigo gamma
int gamma_decode(uchar* gamma) {
	int len_max = strlen((char*)gamma);
	uchar pre[len_max]; // No conozco el maximo a priori pero no es mayor al gamma recibido
	memset(pre,' ',len_max);
	int x = 0;
	while(gamma[x] != '0') {
		pre[x] = gamma[x];
		x++;
	}
	pre[x] = '0';
	x++;
	pre[x] = '\0';
	int q = unary_decode(pre);
	q = q-1;
	uchar post[q+1];
	memset(post,' ',q+1);
	int y = x+q;
	int i = 0;
	for(x; x < y; x++) {
		post[i] = gamma[x];
		i++;
	}
	post[i++] = '\0';
	return (int)pow(2,(double)q) + binary_decode(post);
}

// Escribe un numero en codigo delta
// Recibe un buffer en el cual se dpositara el codigo delta
void delta_code(int number, uchar* delta) {
	base_code(number,gamma_code,delta);	
}

// Decodifica un codigo delta
int delta_decode(uchar* delta) {
	int len_max = strlen((char*)delta);
	int q = gamma_decode(delta);
	q = q-1;
	uchar post[q+1];
	memset(post,' ',q+1);
	int x = len_max-q;
	int y = 0;
	for(x; x < len_max; x++) {
		post[y] = delta[x];
		y++;
	}
	post[y++] = '\0';
	return (int)pow(2,(double)q) + binary_decode(post);
}


