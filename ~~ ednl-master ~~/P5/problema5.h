//
//  problema5.h
//  P5
//
//  Created by JM on 12/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema5_h
#define problema5_h
#include <vector>
#include <cmath>
#include "../../agen.h"
using std::vector;

typedef enum {BLANCO = 0, NEGRO} Color;

typedef struct
{
	int fila, columna;
} Posicion;

typedef struct
{
	Color color;
	Posicion inicio, fin;
} Cuadrante;

typedef vector<vector<Color>> Figura;

inline bool es_hoja(const Agen<Cuadrante> &A, Agen<Cuadrante>::nodo n)
{
	return A.hijoIzqdo(n) == Agen<Cuadrante>::NODO_NULO;
}

int alturaAgen_Rec(const Agen<Cuadrante> &A, Agen<Cuadrante>::nodo n)
{
	int altura;
	altura = 0;
	
	if(n != Agen<Cuadrante>::NODO_NULO)
	{
		altura = 1;
		n = A.hijoIzqdo(n);
		while(n != Agen<Cuadrante>::NODO_NULO)
		{
			altura = std::max(altura, 1 + alturaAgen_Rec(A, n));
			n = A.hermDrcho(n);
		}
	}
	
	return altura;
}

inline int alturaAgen(const Agen<Cuadrante> &A)
{
	return alturaAgen_Rec(A, A.raiz());
}

void Rellenar_cuadrante(const Cuadrante &c, Figura &F)
{
	int fila, columna;

	for(fila = c.inicio.fila; fila <= c.fin.fila; fila++)
		for(columna = c.inicio.columna; columna <= c.fin.columna; columna++)
			F[fila][columna] = c.color;
}

void Reconstruir_Rec(const Agen<Cuadrante> &A, Agen<Cuadrante>::nodo n, Figura &F)
{
	if(es_hoja(A, n))
		Rellenar_cuadrante(A.elemento(n), F);
	else
	{
		n = A.hijoIzqdo(n);
		while(n != Agen<Cuadrante>::NODO_NULO)
		{
			Reconstruir_Rec(A, n, F);
			n = A.hermDrcho(n);
		}
	}
}

Figura Reconstruir_figura(const Agen<Cuadrante> &A)
{
	int altura;
	
	altura = alturaAgen(A);
	assert(altura > 0);
	
	Figura F(pow(2, altura-1), vector<Color>(pow(2, altura-1)));
	Reconstruir_Rec(A, A.raiz(), F);
	return F;
}

std::ostream &operator<<(std::ostream &os, const Figura &F)
{
	/*for(auto &v : F)
	{
		for(auto &c : v)
			c == BLANCO ? os << "B " : os << "N ";
		os << '\n';
	}*/
	for(int i = 0; i < F.size(); i++)
	{
		for(int j = 0; j < F.size(); j++)
			F[i][j] == BLANCO ? os << "B " : os << "N ";
		os << '\n';
	}
	return os;
}

#endif /* problema5_h */
