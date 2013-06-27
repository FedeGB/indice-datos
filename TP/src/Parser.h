#ifndef PARSER_H
#define PARSER_H
#include <fstream>
#include <string>

class Parser {
  private:
    std::ifstream file;
    std::string actual;
    int finish;  // 1 = true, 0 = false
    int pos;  // Posicion en termino a procesar

  public:
    // Constructor de la clase
    Parser(const std::string &path);

    // Entrega un termino al string pasado por parametro
    // Post: Devuelve 0 en caso de que queden termino, y distinto de 0
    // en caso de que se haya terminado de procesar el archivo (EOF)
    int dameUnTermino(std::string &termino);

    // Destructor de la clase
    virtual ~Parser();
};

#endif
