//
//  problema3.h
//  P6
//
//  Created by JM on 09/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema3_h
#define problema3_h
#include "../../material/alg_grafoPMC.h"

template <typename tCoste>
matriz<tCoste> Floyd_modificado(const GrafoP<tCoste> &G)
{
	typedef typename GrafoP<tCoste>::vertice vertice;
	const size_t n = G.numVert();
	matriz<tCoste> A(n);

	for (vertice i = 0; i < n; i++) {
		A[i] = G[i];
		A[i][i] = GrafoP<tCoste>::INFINITO;
	}
	
	for(vertice k = 0; k < n; k++)
		for(vertice i = 0; i < n; i++)
			for(vertice j = 0; j < n; j++)
				A[i][j] = std::min(suma(A[i][k], A[k][j]), A[i][j]);
	
	return A;
}

template <typename tCoste>
bool Grafo_aciclico(const GrafoP<tCoste> &G)
{
	matriz<tCoste> costes;
	typename GrafoP<tCoste>::vertice v;
	size_t n;
	bool es_aciclico;
	
	costes = Floyd_modificado(G);
	n = G.numVert();
	es_aciclico = true;
	v = 0;
	while(es_aciclico && v <= n-1)
	{
		es_aciclico = (costes[v][v] == GrafoP<tCoste>::INFINITO);
		v++;
	}
	
	return es_aciclico;
}

#endif /* problema3_h */
