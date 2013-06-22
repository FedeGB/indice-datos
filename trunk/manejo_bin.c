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
	uchar buffer[8];
	memset(buffer, '\0', 8);
	int x = 0;
	int b = 0;
	while(x < (int)size) {
		if((x+1)%8 == 0) {
			buffer[b] = array[x];
			fwrite(&buffer, 1, 1, fd);
			memset(buffer, '\0', 8);
			b = 0;
			x++;
		}
		buffer[b] = array[x];
		x++;
		b++;
	}
	while((x+1)%8 != 0) {
		buffer[b] = 0;
		x++;
		b++;
	}
	buffer[b] = 0;
	fwrite(&buffer, 1, 1, fd);
	
	return RES_OK;
}

int leer_binf(FILE* fd, uchar* buffer, size_t size, long int offset) {
	if(!fd)
		return RES_NULL;
	fseek(fd, offset, SEEK_SET);
	fread(buffer, 1, size, fd);
	return RES_OK;
}

