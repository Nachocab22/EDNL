//
//  problema2.h
//  P2
//
//  Created by JM on 05/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema2_h
#define problema2_h
#include "../../abin.h"

template <typename T>
void reflejarAbin_Rec(const Abin<T> &A, Abin<T> &B, typename Abin<T>::nodo a, typename Abin<T>::nodo b)
{
	if(A.hijoIzqdo(a) != Abin<T>::NODO_NULO)
	{
		B.insertarHijoDrcho(b, A.elemento(A.hijoIzqdo(a)));
		reflejarAbin_Rec(A, B, A.hijoIzqdo(a), B.hijoDrcho(b));
	}
	if(A.hijoDrcho(a) != Abin<T>::NODO_NULO)
	{
		B.insertarHijoIzqdo(b, A.elemento(A.hijoDrcho(a)));
		reflejarAbin_Rec(A, B, A.hijoDrcho(a), B.hijoIzqdo(b));
	}
}

template <typename T>
Abin<T> reflejarAbin(const Abin<T> &original)
{
	Abin<T> reflejado;
	if(!original.arbolVacio())
	{
		reflejado.insertarRaiz(original.elemento(original.raiz()));
		reflejarAbin_Rec(original, reflejado, original.raiz(), reflejado.raiz());
	}
	return reflejado;
}

#endif /* problema2_h */
