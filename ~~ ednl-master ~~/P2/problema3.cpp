//
//  problema3.cpp
//  P2
//
//  Created by JM on 05/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#include "problema3.hpp"

template <typename T>
bool esHoja(const Abin<T> &A, typename Abin<T>::nodo n)
{
	return A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO;
}

double resolver_rec(const Arbol_expresion &A, Arbol_expresion::nodo n)
{
	elto e = A.elemento(n);
	typename Arbol_expresion::nodo hizq, hder;
	
	if(esHoja(A, n))
		return e.operador;
	else
	{
		hizq = A.hijoIzqdo(n);
		hder = A.hijoDrcho(n);
		switch(e.operando)
		{
			case '+': return resolver_rec(A, hizq) + resolver_rec(A, hder); break;
			case '-': return resolver_rec(A, hizq) - resolver_rec(A, hder); break;
			case 'x': return resolver_rec(A, hizq) * resolver_rec(A, hder); break;
			case '/': return resolver_rec(A, hizq) / resolver_rec(A, hder); break;
			default: return e.operador;
		}
	}
}

double resolver(const Arbol_expresion &A)
{
	return resolver_rec(A, A.raiz());
}
