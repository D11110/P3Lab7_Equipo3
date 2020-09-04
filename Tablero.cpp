#include <iostream>

#include "Alfil.cpp"
#include "Caballo.cpp"
#include "Dama.cpp"
#include "Peon.cpp"
#include "Rey.cpp"
#include "Torre.cpp"

using namespace std;

char letrasTablero[8][8];
string tablero[8][8];

void fichas(int i, int j, string color, char pieza)
{
    letrasTablero[i][j] = pieza;

    for (int iM = 0; iM < 8; iM++)
    {
        for (int jM = 0; jM < 8; jM++)
        {
            if (iM == i && jM == j)
            {
                string cadena = "";
                cadena += "____\n " + pieza;
                cadena += " |\n   |";

                tablero[iM][jM] = cadena;
            }
        }
    }
}

int main()
{
    bool isPlaying = true;
    while (isPlaying)
    {
        std::cout << "Menu" << std::endl;
        std::cout << "1. Jugar" << std::endl;
        std::cout << "2. Salir" << std::endl;

        int opcionIngresadaPJugador;
        cin >> opcionIngresadaPJugador;

        switch (opcionIngresadaPJugador)
        {
        case 1:
            fichas(0, 0, "negro", 'r');
            fichas(0, 1, "negro", 'n');
            fichas(0, 2, "negro", 'b');
            fichas(0, 3, "negro", 'q');
            fichas(0, 4, "negro", 'k');
            fichas(0, 5, "negro", 'b');
            fichas(0, 6, "negro", 'n');
            fichas(0, 7, "negro", 'r');

            fichas(1, 0, "negro", 'p');
            fichas(1, 1, "negro", 'p');
            fichas(1, 2, "negro", 'p');
            fichas(1, 3, "negro", 'p');
            fichas(1, 4, "negro", 'p');
            fichas(1, 5, "negro", 'p');
            fichas(1, 6, "negro", 'p');
            fichas(1, 7, "negro", 'p');

            //blancas

            fichas(7, 0, "blanco", 'R');
            fichas(7, 1, "blanco", 'N');
            fichas(7, 2, "blanco", 'B');
            fichas(7, 3, "blanco", 'Q');
            fichas(7, 4, "blanco", 'K');
            fichas(7, 5, "blanco", 'B');
            fichas(7, 6, "blanco", 'N');
            fichas(7, 7, "blanco", 'R');

            fichas(6, 0, "blanco", 'P');
            fichas(6, 1, "blanco", 'P');
            fichas(6, 2, "blanco", 'P');
            fichas(6, 3, "blanco", 'P');
            fichas(6, 4, "blanco", 'P');
            fichas(6, 5, "blanco", 'P');
            fichas(6, 6, "blanco", 'P');
            fichas(6, 7, "blanco", 'P');

            //vacíos

            fichas(2, 0, "vacio", ' ');
            fichas(2, 1, "vacio", ' ');
            fichas(2, 2, "vacio", ' ');
            fichas(2, 3, "vacio", ' ');
            fichas(2, 4, "vacio", ' ');
            fichas(2, 5, "vacio", ' ');
            fichas(2, 6, "vacio", ' ');
            fichas(2, 7, "vacio", ' ');

            fichas(3, 0, "vacio", ' ');
            fichas(3, 1, "vacio", ' ');
            fichas(3, 2, "vacio", ' ');
            fichas(3, 3, "vacio", ' ');
            fichas(3, 4, "vacio", ' ');
            fichas(3, 5, "vacio", ' ');
            fichas(3, 6, "vacio", ' ');
            fichas(3, 7, "vacio", ' ');

            fichas(4, 0, "vacio", ' ');
            fichas(4, 1, "vacio", ' ');
            fichas(4, 2, "vacio", ' ');
            fichas(4, 3, "vacio", ' ');
            fichas(4, 4, "vacio", ' ');
            fichas(4, 5, "vacio", ' ');
            fichas(4, 6, "vacio", ' ');
            fichas(4, 7, "vacio", ' ');

            fichas(5, 0, "vacio", ' ');
            fichas(5, 1, "vacio", ' ');
            fichas(5, 2, "vacio", ' ');
            fichas(5, 3, "vacio", ' ');
            fichas(5, 4, "vacio", ' ');
            fichas(5, 5, "vacio", ' ');
            fichas(5, 6, "vacio", ' ');
            fichas(5, 7, "vacio", ' ');

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    std::cout << tablero[i][j];
                }
                std::cout << std::endl;
            }
            
            break;

        default:
            break;
        }
    }
}