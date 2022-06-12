//
//  problema1.h
//  P5
//
//  Created by JM on 12/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema1_h
#define problema1_h
#include "../../abin.h"

Abin<int>::nodo buscarNodoAbin(const Abin<int> &A, Abin<int>::nodo n, int x) {
	Abin<int>::nodo pos = Abin<int>::NODO_NULO;
	if(n != Abin<int>::NODO_NULO) {
		if(A.elemento(n) == x)
			pos = n;
		else {
			if(A.hijoIzqdo(n) != Abin<int>::NODO_NULO)
				if(A.elemento(A.hijoIzqdo(n)) <= x)
					pos = buscarNodoAbin(A, A.hijoIzqdo(n), x);
			if(A.hijoDrcho(n) != Abin<int>::NODO_NULO && pos == Abin<int>::NODO_NULO)
				if(A.elemento(A.hijoDrcho(n)) <= x)
					pos = buscarNodoAbin(A, A.hijoDrcho(n), x);
		}
	}
	return pos;
}

inline bool es_nulo(const Abin<int> &A, Abin<int>::nodo n)
{
	return n == Abin<int>::NODO_NULO;
}

void eliminar_repetido(Abin<int> &A, Abin<int>::nodo n, int elto)
{
	Abin<int>::nodo hder, hizq;
	hder = A.hijoDrcho(n);
	hizq = A.hijoIzqdo(n);
	
	if(hizq != Abin<int>::NODO_NULO)
		if(A.elemento(hizq) == elto)
			A.eliminarHijoIzqdo(n);
	if(hder != Abin<int>::NODO_NULO)
		if(A.elemento(hder) == elto)
			A.eliminarHijoDrcho(n);
}

void elevar_max(Abin<int> &A, Abin<int>::nodo n)
{
	Abin<int>::nodo hizq, hder, hmax;
	int i, d;
	hizq = A.hijoIzqdo(n);
	hder = A.hijoDrcho(n);
	
	if(!es_nulo(A, hizq))
	{
		i = A.elemento(hizq);
		if(!es_nulo(A, hder))	// tiene dos hijos
		{
			d = A.elemento(hder);
			hmax = i < d ? hizq : hder;
			A.elemento(n) = A.elemento(hmax);
			elevar_max(A, hmax);
		}
		else					// solo hijo izqdo
		{
			A.elemento(n) = i;
			elevar_max(A, hizq);
		}
	}
	else
	{
		if(!es_nulo(A, hder))	// solo hijo drcho
		{
			A.elemento(n) = A.elemento(hder);
			elevar_max(A, hder);
		}
		else					// es hoja
			eliminar_repetido(A, A.padre(n), A.elemento(n));
	}
}

void eliminar_elto(Abin<int> &A, int elto)
{
	Abin<int>::nodo pos = buscarNodoAbin(A, A.raiz(), elto);
	if(pos != Abin<int>::NODO_NULO)
		elevar_max(A, pos);
}

#endif /* problema1_h */
