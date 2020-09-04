#include <iostream>
#include "Pieza.hpp"
#ifndef AJEDREZ_H
#define AJEDREZ_H

class Ajedrez
{
private:
    Pieza ***tablero;

public:
    Ajedrez();
    void crearTablero();
    void rellenarTablero();
    void jugar();
    ~Ajedrez();
};
#endif