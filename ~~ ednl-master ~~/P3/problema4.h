//
//  problema4.h
//  P3
//
//  Created by JM on 07/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema4_h
#define problema4_h
#include "../../agen.h"

void eliminarDescendencia(Agen<int> &A, Agen<int>::nodo padre)
{	
	while(A.hijoIzqdo(padre) != Agen<int>::NODO_NULO)
	{
		eliminarDescendencia(A, A.hijoIzqdo(padre));
		A.eliminarHijoIzqdo(padre);
	}
}

void eliminarNodo(Agen<int> &A, Agen<int>::nodo n)
{
	Agen<int>::nodo padre, hermano;
	
	padre = A.padre(n);
	if(padre == Agen<int>::NODO_NULO)
		A = Agen<int>();
	else
	{
		eliminarDescendencia(A, n);
		hermano = A.hijoIzqdo(padre);
		if(A.elemento(n) == A.elemento(hermano))
			A.eliminarHijoIzqdo(padre);
		else
		{
			while(A.elemento(n) != A.elemento(hermano))
				hermano = A.hermDrcho(hermano);
			A.eliminarHermDrcho(hermano);
		}
	}
}

void podarAgen_Rec(Agen<int> &A, Agen<int>::nodo n, int x)
{
	if(A.elemento(n) == x)
		eliminarNodo(A, n);
	else
	{
		n = A.hijoIzqdo(n);
		while(n != Agen<int>::NODO_NULO)
		{
			podarAgen_Rec(A, n, x);
			n = A.hermDrcho(n);
		}
	}
}

void podarAgen(Agen<int> &A, int x)
{
	return podarAgen_Rec(A, A.raiz(), x);
}

#endif /* problema4_h */
