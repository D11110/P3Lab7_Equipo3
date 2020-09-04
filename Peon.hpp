#include <iostream>
#include <string>
#include "Pieza.hpp"
#ifndef PEON_H
#define PEON_H
class Peon : public Pieza
{
public:
    Peon();
    Peon(std::string, std::string, char) : Pieza(x, y, representacion){};
    std::string getX();
    std::string getY();
    bool validarMovimiento(std::string, std::string, Pieza***);
    ~Peon();
};
#endif