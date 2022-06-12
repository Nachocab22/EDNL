#ifndef problema1_h
#define problema1_h
#include "../../abin.h"

template <typename T>
int contarHijos_Rec(const Abin<T> &A, typename Abin<T>::nodo n)
{
	if(n == Abin<T>::NODO_NULO)
		return 0;
	else
		return 1 + contarHijos_Rec(A, A.hijoIzqdo(n)) + contarHijos_Rec(A, A.hijoDrcho(n));
}

template <typename T>
int contarHijos(const Abin<T> &A)
{
	return contarHijos_Rec(A, A.raiz());
}

#endif /* problema1_h */
