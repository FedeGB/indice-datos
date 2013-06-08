#include <math.h>
//#include <stdio.h>

void unary_code(int number, char* unary) {
	int x = number - 1;
	int p = 0;
	while(p < x) {
		unary[p] = '1';
		p++;
	}
	unary[x] = '0';
	unary[number] = '\0';
}

void binary_code(int number, int bits, char* binary) {
	int division = number;
	
	for(int x = 0; x < bits; x++) {
		if(division%2 == 0) {
			binary[x] = '0';
		}
		else {
			binary[x] = '1';
		}
	}
	binary[bits] = '\0';
}

void base_code(int number, void func(int,char*), char* vec) {
	int bits = (int)floor(log10(number)/log10(2)); // log(number) en base 2
	int q = 1+bits;
	func(q,vec);
	
	int bin = number - (int)pow(2,(double)bits);
	char binary[bits+1];
	binary_code(bin,bits,binary);
	int x = 0;
	
	for(int i = q; i < (q+bits+1); i++) {
		vec[i] = binary[x];
		x++;
	}
	vec[q+bits] = '\0';
}

void gamma_code(int number, char* gamma) {
	base_code(number,unary_code,gamma);
}

void delta_code(int number, char* delta) {
	base_code(number,gamma_code,delta);	
}
/*
int main() {

	char buff[100] = " ";
	
	unary_code(10,buff);
	
	printf("%s",buff);
	
	return 0;
}*/

