//
//  NodoDeJuego.cpp
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "NodoDeJuego.h"

NodoDeJuego::NodoDeJuego(){
    padre = -1;
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

void NodoDeJuego::ponerPadre(long papa, vector<NodoDeJuego> &partida){
    
    padre = papa;
    profundidad = partida[papa].profundidad+1;
    tablero = Tablero(partida[papa].tablero);
    pago = partida[papa].pago;
    visitado=false;
    
}

long NodoDeJuego::getPadre(){
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

void NodoDeJuego::imprimir(){
    tablero.imprimir();
}

int NodoDeJuego::ganado(){
    return tablero.ganado();
}