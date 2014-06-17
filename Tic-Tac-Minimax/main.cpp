//
//  main.cpp
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include <iostream>
#include "Partida.h"
#include "NodoDeJuego.h"

using namespace std;

int main(int argc, const char * argv[])
{

    Partida miPartida;
    
    NodoDeJuego primero;
    
    miPartida.desarrollar(&primero);
    
    cout << "Nº de Nodos obtenidos: " << miPartida.nnodos() << endl;
    
    
    return 0;
}

