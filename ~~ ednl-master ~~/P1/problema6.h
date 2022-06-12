#ifndef problema6_h
#define problema6_h
#include "problema2.h"

template <typename T>
int difAlturaPos(const Abin<T> &A, typename Abin<T>::nodo n)
{
	return abs(alturaAbin_Rec(A, A.hijoIzqdo(n)) - alturaAbin_Rec(A, A.hijoDrcho(n)));
}

template <typename T>
int desequilibrioAbin_Rec(const Abin<T> &A, typename Abin<T>::nodo n)
{
	if(n == Abin<T>::NODO_NULO)
		return 0;
	else
		return std::max(difAlturaPos(A, n),
						std::max(desequilibrioAbin_Rec(A, A.hijoIzqdo(n)),
								 desequilibrioAbin_Rec(A, A.hijoDrcho(n))));
}

template <typename T>
int desequilibrioAbin(const Abin<T> &A)
{
	return desequilibrioAbin_Rec(A, A.raiz());
}

#endif /* problema6_h */
