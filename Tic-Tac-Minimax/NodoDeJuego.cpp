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
    cout << tablero.mesa[0][0] << "|" << tablero.mesa[1][0] << "|" << tablero.mesa[2][0] << endl;
    cout << "-----" << endl;
    cout << tablero.mesa[0][1] << "|" << tablero.mesa[1][1] << "|" << tablero.mesa[2][1] << "  - Pago: " << pago << endl;
    cout << "-----" << endl;
    cout << tablero.mesa[0][2] << "|" << tablero.mesa[1][2] << "|" << tablero.mesa[2][2] << endl;
}

int NodoDeJuego::ganado(){
    return tablero.ganado();
}