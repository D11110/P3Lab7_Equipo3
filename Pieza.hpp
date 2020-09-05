#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include <string>
using namespace std;
class Pieza
{
protected:
    int x;
    int y;
    char representacion;

public:
    Pieza()
    {
    }
    Pieza(int x, int y, char representacion)
    {
        this->x = x;
        this->y = y;
        this->representacion = representacion;
    }
    virtual bool validarMovimiento(string, string, Pieza ***) = 0;

    char getRepresentacion()
    {
        return this->representacion;
    };
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