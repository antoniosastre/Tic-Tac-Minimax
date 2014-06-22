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
    
    cout << "Empieza..." << endl;
    
    miPartida.desarrollar();
    
    cout << "Desarrollados los números..." << endl;
    
    cout << "Nº de Nodos obtenidos: " << miPartida.nnodos() << endl;
    
    miPartida.pagoMaxiMin();
    
    cout << "Calculados los pagos. Pago máximo del jugador 0: " << miPartida.getPagoCero() << endl;

    
    return 0;
}

