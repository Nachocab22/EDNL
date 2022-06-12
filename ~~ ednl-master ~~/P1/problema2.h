#ifndef problema2_h
#define problema2_h
#include "../../abin.h"

template <typename T>
int alturaAbin_Rec(const Abin<T> &A, typename Abin<T>::nodo n)
{
	if(n == Abin<T>::NODO_NULO)
		return 0;
	else
		return 1 + std::max(alturaAbin_Rec(A, A.hijoIzqdo(n)), alturaAbin_Rec(A, A.hijoDrcho(n)));
}

template <typename T>
int alturaAbin(const Abin<T> &A)
{
	return alturaAbin_Rec(A, A.raiz());
}

#endif /* problema2_h */
