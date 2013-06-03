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
			binary[x] = '1';
		}
	}
	binary[bits] = '\0';
	
	return binary;
}

char* base_code(int number, char* func(int)) {
	int bits = (int)floor(log10(number)/log10(2)); // log(number) en base 2
	int q = 1+bits;
	char* vec[q+bits+1];
	strcpy(vec,func(q));
	
	int bin = number - (int)pow(2,(double)bits);
	char* binary[bits+1];
	strcpy(binary, binary_code(bin,bits));
	int x = 0;
	
	for(int i = q; i < (q+bits+1); i++) {
		vec[i] = binary[x];
		x++;
	}
	vec[q+bits] = '\0';
	
	return vec;
}

char* gamma_code(int number) {
	return base_code(number,unary_code);
}

char* delta_code(int number) {
	return base_code(number,gamma_code);	
}
