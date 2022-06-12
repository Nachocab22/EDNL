//
//  problema4.h
//  P4
//
//  Created by JM on 11/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema4_h
#define problema4_h
#include "problema2.h"

typedef Abb<int> Conjunto;

inline bool esta(const Conjunto &C, int elto)
{
	return !C.buscar(elto).vacio();
}

void interseccionConjuntos_Rec(const Conjunto &A, const Conjunto &B, Conjunto &Inter)
{
	int elto;
	if(!A.vacio() && !B.vacio())
	{
		elto = A.elemento();
		if(esta(B, elto))
		{
			Inter.insertar(elto);
		}
		interseccionConjuntos_Rec(A.izqdo(), B, Inter);
		interseccionConjuntos_Rec(A.drcho(), B, Inter);
	}
}

Conjunto interseccionConjuntos(const Conjunto &A, const Conjunto &B)
{
	Conjunto Sol;
	
	interseccionConjuntos_Rec(A, B, Sol);
	equilibrarAbb(Sol);
	
	return Sol;
}

#endif /* problema4_h */
