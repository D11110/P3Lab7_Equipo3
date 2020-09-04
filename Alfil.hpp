#include <iostream>
#include <string>
#include "Pieza.hpp"

#ifndef ALFIL_H
#define ALFIL_H
class Alfil : public Pieza
{
public:
    Alfil();
    Alfil(std::string, std::string, char) : Pieza(x, y, representacion){};
    std::string getX();
    std::string getY();
    bool validarMovimiento(std::string, std::string, Pieza***);
    ~Alfil();
};
#endif