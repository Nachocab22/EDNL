#ifndef problema7_h
#define problema7_h
#include "problema2.h"

template <typename T>
int contarHijos(const Abin<T> &A, typename Abin<T>::nodo n)
{
	return (int)(A.hijoIzqdo(n) != Abin<T>::NODO_NULO) + (int)(A.hijoDrcho(n) != Abin<T>::NODO_NULO);
}

template <typename T>
bool abinPseudocompleto_Rec(const Abin<T> &A, typename Abin<T>::nodo n)
{
	int altura = alturaAbin_Rec(A, n), altHizq, altHder;
	if(altura == 1)
		return contarHijos(A, n) == 2;
	else if(altura == 0)
		return true;
	else
	{
		altHizq = alturaAbin_Rec(A, A.hijoIzqdo(n));
		altHder = alturaAbin_Rec(A, A.hijoDrcho(n));
		if(altHizq == altHder)
			return abinPseudocompleto_Rec(A, A.hijoIzqdo(n)) && abinPseudocompleto_Rec(A, A.hijoDrcho(n));
		else if(altHizq > altHder)
			return abinPseudocompleto_Rec(A, A.hijoIzqdo(n));
		else
			return abinPseudocompleto_Rec(A, A.hijoDrcho(n));
	}
}

template <typename T>
bool abinPseudocompleto(const Abin<T> &A)
{
	return abinPseudocompleto_Rec(A, A.raiz());
}

#endif /* problema7_h */
