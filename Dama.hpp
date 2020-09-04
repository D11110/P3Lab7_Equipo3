#include <iostream>
#include <string>
#include "Pieza.hpp"

class Reina : public Pieza
{
public:
    Reina();
    Reina(std::string, std::string, char) : Pieza(x, y, representacion){};
    std::string getX();
    std::string getY();
    bool validarMovimiento(std::string, std::string, Pieza ***);
    ~Reina();
};