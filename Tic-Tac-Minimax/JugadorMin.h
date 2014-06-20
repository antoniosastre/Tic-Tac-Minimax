//
//  JugadorMin.h
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#ifndef __Tic_Tac_Minimax__JugadorMin__
#define __Tic_Tac_Minimax__JugadorMin__

#include <iostream>
#include "Partida.h"

class JugadorMin {
    
private:
    
public:

    JugadorMin();
    
    void calcularPagos(Partida p, int nivel);
    
};

#endif /* defined(__Tic_Tac_Minimax__JugadorMin__) */
