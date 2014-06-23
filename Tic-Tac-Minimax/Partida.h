//
//  Partida.h
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#ifndef __Tic_Tac_Minimax__Partida__
#define __Tic_Tac_Minimax__Partida__

#include <iostream>
#include <vector>
#include "NodoDeJuego.h"

using namespace std;

class Partida {
    
private:    
    
    void sacarHijos(long nodopadre, int jugador=1);
    int maxProfundidad;
    
public:
    
    Partida();
    
    vector<NodoDeJuego> partida;
    
    bool ganado();
    
    void desarrollar();
    
    long nnodos();
    
    void pagoMaxiMin();
    void pagoMaxiMin2();
    
    void calcularPagoMax(int nivel);
    void calcularPagoMin(int nivel);
    
    void calcularPagoMax2(int nivel);
    void calcularPagoMin2(int nivel);
    
    int getPagoCero();
    
    void printCamino(int nivel);
    void printPagos();
    int buscarMaxHijoDe(int nodo);
    int buscarMinHijoDe(int nodo);
    void printJugada();
    
};

#endif /* defined(__Tic_Tac_Minimax__Partida__) */
