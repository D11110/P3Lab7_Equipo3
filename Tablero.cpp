#include <iostream>
#include <string>

#include "Alfil.hpp"
#include "Caballo.hpp"
#include "Dama.hpp"
#include "Peon.hpp"
#include "Rey.hpp"
#include "Torre.hpp"
#include "Ajedrez.hpp"

using namespace std;

int main()
{

    cout << "A ver" << endl;
    Ajedrez *ac = new Ajedrez();
    ac->crearTablero();
    ac->imprimirTablero();
    ac->jugar();
}