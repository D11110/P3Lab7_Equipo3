#include <iostream>
#include <string>
#include "Pieza.hpp"

#ifndef TORRE_H
#define TORRE_H

class Torre : public Pieza
{
public:
    Torre();
    Torre(std::string, std::string, char) : Pieza(x, y, representacion){};
    std::string getX();
    std::string getY();
    bool validarMovimiento(int, int, Pieza ***);
    ~Torre();
};
#endif