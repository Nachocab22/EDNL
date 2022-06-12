//
//  problema1.h
//  P2
//
//  Created by JM on 05/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema1_h
#define problema1_h
#include "../../abin.h"

template <typename T>
bool AbinSimilares_Rec(const Abin<T> &A, const Abin<T> &B, typename Abin<T>::nodo a, typename Abin<T>::nodo b)
{
	const typename Abin<T>::nodo &nulo = Abin<T>::NODO_NULO;
	if(a == nulo)
	{
		if(b == nulo)
			return true;
		else	// b != nulo
			return false;
	}
	else		// a != nulo
	{
		if(b == nulo)
			return false;
		else	// a != nulo y b != nulo
			return AbinSimilares_Rec(A, B, A.hijoIzqdo(a), B.hijoIzqdo(b)) &&
				AbinSimilares_Rec(A, B, A.hijoDrcho(a), B.hijoDrcho(b));
	}
}

template <typename T>
bool AbinSimilares(const Abin<T> &A, const Abin<T> &B)
{
	return AbinSimilares_Rec(A, B, A.raiz(), B.raiz());
}

#endif /* problema1_h */
