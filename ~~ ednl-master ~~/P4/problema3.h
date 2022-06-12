//
//  problema3.h
//  P4
//
//  Created by JM on 11/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema3_h
#define problema3_h
#include "problema2.h"

typedef Abb<int> Conjunto;

void unionConjuntos_Rec(Conjunto &A, const Conjunto &B)
{
	if(!B.vacio())
	{
		unionConjuntos_Rec(A, B.izqdo());
		A.insertar(B.elemento());
		unionConjuntos_Rec(A, B.drcho());
	}
}

Conjunto unionConjuntos(const Conjunto &A, const Conjunto &B)
{
	Conjunto Sol;
	
	Sol = A;
	unionConjuntos_Rec(Sol, B);
	
	equilibrarAbb(Sol);
	return Sol;
}

#endif /* problema3_h */
