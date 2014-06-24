//
//  NodoDeJuego.h
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#ifndef __Tic_Tac_Minimax__NodoDeJuego__
#define __Tic_Tac_Minimax__NodoDeJuego__

#include <iostream>
#include "Tablero.h"
#include <vector>

using namespace std;

class NodoDeJuego {
    
private:
    
    Tablero tablero;
    
public:
    
    //Almacena si el nodo se ha visitado en la fase de transmisión de pagos.
    bool visitado;
    
    //Nivel del nodo.
    int profundidad;
    
    //Posición del padre del nodo en el vector de la partida.
    long padre;
    
    //Pago de este nodo.
    int pago;
    
    NodoDeJuego();
    NodoDeJuego(NodoDeJuego const &copia);
    
    //Establece el padre del nodo.
    void ponerPadre(long papa, vector<NodoDeJuego> &partida);
    
    bool estaLibre(int x, int y);
    
    bool colocar(int j, int x, int y);
    
    //Imprime el tablero y el pago del nodo.
    void imprimir();
    
    //Indica si el nodo tiene un ganador.
    int ganado();
    
};

#endif /* defined(__Tic_Tac_Minimax__NodoDeJuego__) */
