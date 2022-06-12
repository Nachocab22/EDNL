#ifndef problema3_h
#define problema3_h
#include "../../abin.h"

template <typename T>
int profundidadNodoAbin(const Abin<T> &A, typename Abin<T>::nodo n)
{
	int prof = 0;
	assert(n != Abin<T>::NODO_NULO);
	while(n != A.raiz())
	{
		prof++;
		n = A.padre(n);
	}
	return prof;
}

#endif /* problema3_h */
