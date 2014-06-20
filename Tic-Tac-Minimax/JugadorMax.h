//
//  JugadorMax.h
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#ifndef __Tic_Tac_Minimax__JugadorMax__
#define __Tic_Tac_Minimax__JugadorMax__

#include <iostream>
#include "Partida.h"

class JugadorMax {
    
private:
    
public:
    
    JugadorMax();
    
    void calcularPagos(Partida p, int nivel);
    
};

#endif /* defined(__Tic_Tac_Minimax__JugadorMax__) */
