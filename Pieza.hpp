#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include <string>
using namespace std;
class Pieza
{
protected:
    std::string x, y;
    char representacion;

public:
    Pieza()
    {
    }
    Pieza(string x, string y, char representacion)
    {
        this->x = x;
        this->y = y;
        this->representacion = representacion;
    }
    virtual bool validarMovimiento(string, string, Pieza ***) = 0;
    virtual string getX() = 0;
    virtual string getY() = 0;
    virtual int coordenada() = 0;
};
#endif