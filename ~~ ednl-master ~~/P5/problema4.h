//
//  problema4.h
//  P5
//
//  Created by JM on 12/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema4_h
#define problema4_h
#include "../../agen.h"

template <typename T>
bool nodo_ternario(const Agen<T> &A, typename Agen<T>::nodo n)
{
	int hijos;
	
	hijos = 0;
	n = A.hijoIzqdo(n);
	while(n != Agen<T>::NODO_NULO)
	{
		hijos++;
		n = A.hermDrcho(n);
	}
	
	return hijos == 3 || hijos == 0;
}

template <typename T>
bool es_ternario_Rec(const Agen<T> &A, typename Agen<T>::nodo n)
{
	bool es_ternario;
	
	es_ternario = nodo_ternario(A, n);
	n = A.hijoIzqdo(n);
	while(n != Agen<T>::NODO_NULO && es_ternario)
	{
		es_ternario = es_ternario && es_ternario_Rec(A, n);
		n = A.hermDrcho(n);
	}
	
	return es_ternario;
}

template <typename T>
inline bool es_ternario(const Agen<T> &A)
{
	return A.arbolVacio() ? true : es_ternario_Rec(A, A.raiz());
}

#endif /* problema4_h */
