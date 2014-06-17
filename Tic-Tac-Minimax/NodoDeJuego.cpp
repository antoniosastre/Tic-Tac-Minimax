//
//  NodoDeJuego.cpp
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "NodoDeJuego.h"

NodoDeJuego::NodoDeJuego(){
    this->padre = NULL;
    this->profundidad = 0;
    this->tablero = Tablero();
}

NodoDeJuego::NodoDeJuego(NodoDeJuego* padre){
    
    this->padre = padre;
    this->profundidad = padre->profundidad+1;
    this->tablero = padre->tablero;
    
}

NodoDeJuego* NodoDeJuego::getPadre(){
    return padre;
}

bool NodoDeJuego::estaLibre(int x, int y){
    
    return tablero.estaLibre(x, y);
    
}

bool NodoDeJuego::colocar(int j, int x, int y){
    
    return tablero.insertar(j, x, y);
    
}

void NodoDeJuego::setPadre(NodoDeJuego *nodo){
    this->padre = nodo;
}

void NodoDeJuego::imprimir(){
    
    tablero.imprimir();
    
}