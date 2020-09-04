#include <iostream>
#include <string>
#include "Pieza.hpp"
#ifndef CABALLO_H
#define CABALLO_H
class Caballo : public Pieza
{
public:
    Caballo();
    Caballo(std::string, std::string, char) : Pieza(x, y, representacion){};
    std::string getX();
    std::string getY();
    bool validarMovimiento(int, int, Pieza ***);
    ~Caballo();
};
#endif