#include <iostream>
#include <string>
#include "Pieza.hpp"

class Rey : public Pieza
{
public:
    Rey();
    Rey(std::string, std::string, char) : Pieza(x, y, representacion){};
    std::string getX();
    std::string getY();
    bool validarMovimiento(std::string, std::string,Pieza***);
    ~Rey();
};