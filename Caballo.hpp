#include <iostream>

#include "Pieza.hpp"

using namespace std;
#ifndef CABALLO_H
#define CABALLO_H
class Caballo : public Pieza
{
public:
    Caballo::Caballo() {}

    Caballo::Caballo(std::string x, std::string y, char representacion) : Pieza(x, y, representacion) {}

    std::string Caballo::getX()
    {
        return this->x;
    }
    std::string Caballo::getY()
    {
        return this->y;
    }

    Caballo::~Caballo()
    {
    }
};
#endif