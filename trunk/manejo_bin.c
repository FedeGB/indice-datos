#include <stddef.h>
#include "codigos_retorno.c"

//typedef unsigned char uchar;

int escribir_binf(FILE* fd, uchar* array, size_t size) {
	if(!fd)
		return RES_NULL;
	/*if(size%8 == 0) {
		fwrite(array, 1, size, fd); 
		return RES_OK;
	}*/
	uchar buffer = 0;
	int bit_actual = 0;
	int x = 0;
	while(x < (int)size) {
		if((x+1)%8 == 0) {
			if(array[x]) {
				buffer |= (1<<bit_actual);
			fwrite(&buffer, 1, 1, fd);
			bit_actual = 0;
			x++;
		}
		if(array[x]) {
				buffer |= (1<<bit_actual);
		x++;
		bit_actual++;
	}
	while(x%8 != 0) {
		buffer |= (1<<bit_actual);
		x++;
		bit_actual++;
	}
	fwrite(&buffer, 1, 1, fd);
	
	return RES_OK;
}

int leer_binf(FILE* fd, uchar* buffer, size_t size, long int offset) {
	if(!fd)
		return RES_NULL;
	uchar char_buff[size];
	memset(char_buff, '\0', size);
	fseek(fd, offset, SEEK_SET);
	fread(buffer, 1, size, fd);
	int bit_actual = 0;
	for(int x = 0; x<(int)size; x++) {
		while(bit_actual < 8) {	
			if(char_buff[x] & (1<<bit_actual) != 0) {
				buffer[bit_actual+(8*x)] = 1;
			}
			else {
				buffer[bit_actual+(8*x)] = 0;
			}
			bit_actual++;
		}
		bit_actual = 0;
	}
	
	return RES_OK;
}
