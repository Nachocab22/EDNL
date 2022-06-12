//
//  problema3.hpp
//  P2
//
//  Created by JM on 05/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema3_hpp
#define problema3_hpp
#include "../../abin.h"

typedef struct
{
	double operador;
	char operando;
} elto;

typedef Abin<elto> Arbol_expresion;

double resolver(const Arbol_expresion&);

#endif /* problema3_hpp */
