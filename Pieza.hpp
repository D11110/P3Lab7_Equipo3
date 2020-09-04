#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include <string>
class Pieza
{
protected:
    std::string x, y;
    char representacion;

public:
    Pieza::Pieza()
    {
    }
    Pieza::Pieza(std::string x, std::string y, char representacion)
    {
        this->x = x;
        this->y = y;
        this->representacion = representacion;
    }
    virtual bool validarMovimiento(std::string, std::string, Pieza ***) = 0;
    virtual std::string getX() = 0;
    virtual std::string getY() = 0;
    virtual int coordenada() = 0;
};
#endif