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
    
    //Obtener los nodos hijos del padre dado del vector de la partida actuando como el jugador "jugador".
    void sacarHijos(long nodopadre, int jugador=1);
    
    //Profundida máxima de las hojas del árbol.
    int maxProfundidad;
    
public:
    
    Partida();
    
    vector<NodoDeJuego> partida;

    
    //Calcular los todos los nodos de todas las jugadas posibles del juego del tres en raya.
    void desarrollar();
    
    //Número de nodos desarrollados.
    long nnodos();
    
    //Calcula los pagos para los nodos desarrollados. Desde las hojas hasta la raíz.
    void pagoMaxiMin();
    
    //Calcula los pagos del nivel "nivel" del árbol como jugador Max.
    void calcularPagoMax(int nivel);
    
    //Calcula los pagos del nivel "nivel" del árbol como jugador Min.
    void calcularPagoMin(int nivel);

    //Devuelve el pago del jugador en el nivel 0.
    int getPagoCero();
    
    //Imprime los pagos de los nodos por pantalla.
    void printPagos();
    
    //Imprime por pantalla una jugada.
    void printJugada();
    
};

#endif /* defined(__Tic_Tac_Minimax__Partida__) */
