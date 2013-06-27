#include "parser.h"
#include <string>
#include <cstring>
#include <cctype>

Parser::Parser(const std::string &path) {
	file.open(path.c_str(), std::ifstream::in);
	finish = 1;
	pos = 0;
}

int Parser::dameUnTermino(std::string &termino) {
	if(file.eof())
		return -1;
	if(finish == 1) {
		actual.clear();
		file >> actual;
		if(file.eof())
			return -1;
		finish = 0;
	}
	if( (isalnum(actual[pos]) == 0) && (pos == (int)actual.length()+1)) {
		actual.clear();
		file >> actual;
		if(file.eof())
			return -1;
		finish = 0;
	}
	
	int av = pos;
	char aux;
	while((av < (int)actual.length()) || isalnum(actual[av])) {
		//std::cout << (bool)isalnum(actual[av]) << std::endl;
		aux = (char)tolower(actual[av]);
		actual[av] = aux;
		av++;
	}
	char* buffer = new char[av+1];
	int len = actual.copy(buffer, av-pos, pos);
	buffer[len] = '\0';
	if(av == (int)actual.length()) {
		finish = 1;
		pos = 0;
	}
	else {
		pos = av++;
	}
	termino.clear();
	termino = buffer;
	delete []buffer;
	return 0;
}

Parser::~Parser() {
	file.close();
}
