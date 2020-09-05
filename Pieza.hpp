#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include <string>
using namespace std;
class Pieza
{
protected:
    char x;
    string y;
    char representacion;

public:
    Pieza()
    {
    }
    Pieza(char x, string y, char representacion)
    {
        this->x = x;
        this->y = y;
        this->representacion = representacion;
    }
    virtual bool validarMovimiento(string, string, Pieza ***) = 0;
    virtual char getX() = 0;
    virtual string getY() = 0;
    virtual char getRepresentacion()=0;
    int coordenadaXs(string posicionAConvertir)
    {
        int x = 0;
        switch (posicionAConvertir.at(0))
        {
        case 'a':
            x = 1;
            break;
        case 'b':
            x = 2;
            break;
        case 'c':
            x = 3;
            break;
        case 'd':
            x = 4;
            break;
        case 'e':
            x = 5;
            break;
        case 'f':
            x = 6;
            break;
        case 'g':
            x = 7;
            break;
        case 'h':
            x = 8;
            break;
        default:
            break;
        }
        return x;
    }
    int coordenadasY(string posicionAconvertir)
    {
        std::string aux = "";
        aux += posicionAconvertir.at(1);
        int y = stoi(aux);
        return y;
    }
};
#endif