//
//  problema5.h
//  P4
//
//  Created by JM on 11/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema5_h
#define problema5_h
#include "problema3.h"
#include "problema4.h"

typedef Abb<int> Conjunto;

void romboConjuntos_Rec(const Conjunto &Union, const Conjunto &Inter, Conjunto &Sol)
{
	int elto;
	if(!Union.vacio())
	{
		elto = Union.elemento();
		if(!esta(Inter, elto))
			Sol.insertar(elto);
		romboConjuntos_Rec(Union.izqdo(), Inter, Sol);
		romboConjuntos_Rec(Union.drcho(), Inter, Sol);
	}
}

Conjunto romboConjuntos(const Conjunto &A, const Conjunto &B)
{
	Conjunto Sol, Inter, Union;
	
	Inter = interseccionConjuntos(A, B);
	Union = unionConjuntos(A, B);
	
	romboConjuntos_Rec(Union, Inter, Sol);
	equilibrarAbb(Sol);
	
	return Sol;
}

#endif /* problema5_h */
