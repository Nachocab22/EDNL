//
//  problema1.h
//  P7
//
//  Created by JM on 10/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema1_h
#define problema1_h
#include "../../material/alg_grafoPMC.h"

typedef double km;
typedef GrafoP<km>::vertice ciudad;
typedef struct
{
	ciudad origen, destino;
	km distancia;
} Viaje;

template <typename tCoste>
matriz<tCoste> Floyd_modificado(const GrafoP<tCoste> &G)
{
	typedef typename GrafoP<tCoste>::vertice vertice;
	const size_t n = G.numVert();
	matriz<tCoste> A(n);

	for (vertice i = 0; i < n; i++) {
		A[i] = G[i];
		A[i][i] = 0;
	}
	
	for (vertice k = 0; k < n; k++)
		for (vertice i = 0; i < n; i++)
			for (vertice j = 0; j < n; j++) {
				tCoste ikj = suma(A[i][k], A[k][j]);
				if(A[i][j] == GrafoP<tCoste>::INFINITO ||
				   (ikj > A[i][j] && ikj != GrafoP<tCoste>::INFINITO))
					A[i][j] = ikj;
			}
	
	return A;
}

Viaje Viaje_mas_caro(const GrafoP<km> &Costes_directos)
{
	Viaje v;
	matriz<km> Costes_encarecidos;
	ciudad i, j;
	size_t n;
	
	Costes_encarecidos = Floyd_modificado(Costes_directos);
	
	v.distancia = 0;
	n = Costes_directos.numVert();
	for(i = 0; i <= n-1; i++)
		for(j = 0; j <= n-1; j++)
			if(v.distancia < Costes_encarecidos[i][j] && Costes_encarecidos[i][j] != GrafoP<km>::INFINITO)
			{
				v.distancia = Costes_encarecidos[i][j];
				v.origen = i;
				v.destino = j;
			}
	
	return v;
}

#endif /* problema1_h */
