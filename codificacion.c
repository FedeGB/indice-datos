#include <math.h>


char* unary_code(int number) {
	int x = number - 1;
	char unary[number+1];
	int p = 0;
	
	while(p < x) {
		unary[p] = '1';
		p++;
	}
	unary[x] = '0';
	unary[number] = '\0';
	
	return unary;
}

char* binary_code(int number, int bits) {
	char* binary[bits+1];
	int division = number;
	
	for(int x = 0; x < bits; x++) {
		if(division%2 == 0) {
			binary[x] = '0';
		}
		else {
			biney[x] = '1';
		}
	}
	binary[bits] = '\0';
	
	return binary;
}

char* gamma_code(int number) {
	int bits = (int)floor(log10(number)/log10(2)); // log(number) en base 2
	int q = 1+bits;
	char* gamma[q+bits+1];
	strcpy(gamma,unary_code(q));
	
	int bin = number - (int)pow(2,(double)bits);
	char* binary[bits+1];
	strcpy(binary, binary_code(bin,bits));
	int x = 0;
	
	for(int i = q; i < (q+bits+1); i++) {
		gamma[i] = binary[x];
		x++;
	}
	gamma[q+bits] = '\0';
	
	return gamma;
}
