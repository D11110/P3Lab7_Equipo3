#include <iostream>
#include <string>

// #include "Alfil.hpp"
// #include "Caballo.hpp"
// #include "Dama.hpp"
// #include "Peon.hpp"
// #include "Rey.hpp"
// #include "Torre.hpp"

using namespace std;

char letrasTablero[8][8];
string tablero[18][18];

void fichas(int i, int j, string color, char pieza)
{
    letrasTablero[i][j] = pieza;

    for (int iM = 0; iM < 8; iM++)
    {
        for (int jM = 0; jM < 8; jM++)
        {
            if (iM == i && jM == j)
            {
                string piezaEnCadena = "";
                piezaEnCadena += pieza;
                string cadena;
                cadena = " " + piezaEnCadena + " |";

                tablero[iM][jM] = cadena;
                cadena = "";
            }
        }
    }
}

void imprimirTablero()
{
    int filas = 2;
    string tableroJugar[18][9];
    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == 0 && j == 0)
            {
                std::cout << "______________________________";
            }
            else if (i == 1 && j == 0)
            {
                std::cout << "[8]";
            }
            else if(i==2 && j==){}
            else if (i == 3 && j == 0)
            {
                std::cout << "[7]";
            }
            else if (i % 2 == 0)
            {
                cout << "    ___|___|___|___|___|___|___|___|";
            }
        }
        cout << endl;
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

            imprimirTablero();

            break;

        default:
            isPlaying = false;
            break;
        }
    }
}