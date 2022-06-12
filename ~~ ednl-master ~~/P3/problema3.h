//
//  problema3.h
//  P3
//
//  Created by JM on 07/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema3_h
#define problema3_h
#include "../../agen.h"

template <typename T>
int alturaNodo(const Agen<T> &A, typename Agen<T>::nodo n)
{
	typename Agen<T>::nodo hijo;
	int alt;
	
	if(n != Agen<T>::NODO_NULO)
	{
		alt = 0;
		hijo = A.hijoIzqdo(n);
		while(hijo != Agen<T>::NODO_NULO)
		{
			alt = std::max(alt, 1 + alturaNodo(A, hijo));
			hijo = A.hermDrcho(hijo);
		}
	}
	else
		alt = -1;
	
	return alt;
}

template <typename T>
int desequilibrio_Rec(const Agen<T> &A, typename Agen<T>::nodo n)
{
	typename Agen<T>::nodo hijo;
	int alt_max, alt_min, dif_max, alt_actual;
	
	hijo = A.hijoIzqdo(n);
	dif_max = 0;
	alt_max = std::numeric_limits<int>::min();
	alt_min = std::numeric_limits<int>::max();
	
	while(hijo != Agen<T>::NODO_NULO)
	{
		alt_actual = alturaNodo(A, hijo);
		alt_max = std::max(alt_max, alt_actual);
		alt_min = std::min(alt_min, alt_actual);
		dif_max = std::max(alt_max - alt_min, desequilibrio_Rec(A, hijo));
		hijo = A.hermDrcho(hijo);
	}
	
	return dif_max;
}

template <typename T>
int desequilibrioAgen(const Agen<T> &A)
{
	return desequilibrio_Rec(A, A.raiz());
}

#endif /* problema3_h */
