//
//  problema2.h
//  P3
//
//  Created by JM on 07/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema2_h
#define problema2_h
#include "../../agen.h"

template <typename T>
int profundidadNodo(const Agen<T> &A, typename Agen<T>::nodo n)
{
	int prof;
	
	prof = 0;
	while(A.padre(n) != Agen<T>::NODO_NULO)
	{
		prof++;
		n = A.padre(n);
	}
	
	return prof;
}

#endif /* problema2_h */
