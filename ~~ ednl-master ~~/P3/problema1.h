//
//  problema1.h
//  P3
//
//  Created by JM on 07/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema1_h
#define problema1_h
#include "../../agen.h"

template <typename T>
int contarHijos(const Agen<T> &A, typename Agen<T>::nodo n)
{
	int hijos;
	typename Agen<T>::nodo hijo;
	
	hijos = 0;
	hijo = A.hijoIzqdo(n);
	
	while(hijo != Agen<T>::NODO_NULO)
	{
		hijos++;
		hijo = A.hermDrcho(hijo);
	}
	
	return hijos;
}

template <typename T>
int gradoAgen_Rec(const Agen<T> &A, typename Agen<T>::nodo n)
{
	int grado_max;
	typename Agen<T>::nodo hijo;
	
	grado_max = contarHijos(A, n);
	hijo = A.hijoIzqdo(n);
	while(hijo != Agen<T>::NODO_NULO)
	{
		grado_max = std::max(grado_max, gradoAgen_Rec(A, hijo));
		hijo = A.hermDrcho(hijo);
	}
	
	return grado_max;
}

template <typename T>
int gradoAgen(const Agen<T> &A)
{
	assert(!A.arbolVacio());
	return gradoAgen_Rec(A, A.raiz());
}

#endif /* problema1_h */
