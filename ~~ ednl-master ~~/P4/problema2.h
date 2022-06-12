//
//  problema2.h
//  P4
//
//  Created by JM on 07/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema2_h
#define problema2_h
#include "../../abb.h"
using std::vector;

template <typename T>
void recorridoInorden_Rec(const Abb<T> &A, vector<T> &eltos)
{
	if(!A.vacio())
	{
		recorridoInorden_Rec(A.izqdo(), eltos);
		eltos.push_back(A.elemento());
		recorridoInorden_Rec(A.drcho(), eltos);
	}
}

template <typename T>
vector<T> recorridoInorden(const Abb<T> &A)
{
	vector<T> eltos;
	recorridoInorden_Rec(A, eltos);
	return eltos;
}

template <typename T>
void equilibrarAbb_Rec(const vector<T> &eltos, Abb<T> &A, size_t inicio, size_t fin)
{
	size_t mitad;
	if(inicio <= fin)
	{
		mitad = (inicio + fin) / 2;
		A.insertar(eltos[mitad]);
		equilibrarAbb_Rec(eltos, A, inicio, mitad-1);
		equilibrarAbb_Rec(eltos, A, mitad+1, fin);
	}
}

template <typename T>
void equilibrarAbb(Abb<T> &A)
{
	vector<T> eltos;
	eltos = recorridoInorden(A);
	A = Abb<T>();
	equilibrarAbb_Rec(eltos, A, 0, eltos.size()-1);
}

#endif /* problema2_h */
