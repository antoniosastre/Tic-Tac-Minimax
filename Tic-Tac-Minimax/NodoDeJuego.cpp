//
//  NodoDeJuego.cpp
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "NodoDeJuego.h"

NodoDeJuego::NodoDeJuego(){
    padre = NULL;
    profundidad = 0;
    tablero = Tablero();
    pago=0;
    visitado = false;
}

NodoDeJuego::NodoDeJuego(NodoDeJuego const &copia){
    
    padre = copia.padre;
    profundidad = copia.profundidad;
    tablero = Tablero(copia.tablero);
    pago=copia.pago;
    visitado = false;
    
}

void NodoDeJuego::ponerPadre(NodoDeJuego & papa){
    
    padre = &papa;
    profundidad = papa.profundidad+1;
    tablero = Tablero(papa.tablero);
    pago = papa.pago;
    visitado=false;
    
    
}

NodoDeJuego* NodoDeJuego::getPadre(){
    return padre;
}

bool NodoDeJuego::estaLibre(int x, int y){
    
    return tablero.estaLibre(x, y);
    
}

bool NodoDeJuego::colocar(int j, int x, int y){
    
    if (tablero.insertar(j, x, y)) {
        if (ganado()==1) {
            pago=1;
        }else if (ganado()==2){
            pago=-1;
        }
        
        return true;
    }
    
    return false;
    
}

void NodoDeJuego::setPadre(NodoDeJuego *nodo){
    this->padre = nodo;
}

void NodoDeJuego::imprimir(){
    tablero.imprimir();
}

int NodoDeJuego::ganado(){
    return tablero.ganado();
}