//
//  problema2.h
//  P6
//
//  Created by JM on 09/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema2_h
#define problema2_h
#include "../../material/alg_grafoPMC.h"

template <typename tCoste>
tCoste Calcular_diametro_grafo(const GrafoP<tCoste> G)
{
	typedef typename GrafoP<tCoste>::vertice vertice;
	vertice pseudocentro, a, b, v, w;
	tCoste diametro, ca, cb, aux;
	size_t n;
	matriz<tCoste> costes;
	matriz<vertice> caminos;
	
	costes = Floyd(G, caminos);
	n = G.numVert();
	diametro = GrafoP<tCoste>::INFINITO;
	
	for(v = 0; v <= n-1; v++)
	{
		ca = cb = 0;
		for(w = 0; w <= n-1; w++)
		{
			if(costes[v][w] > ca)
			{
				cb = ca;
				b = a;
				ca = costes[v][w];
				a = w;
			}
			else if(costes[v][w] > cb)
			{
				cb = costes[v][w];
				b = w;
			}
		}
		aux = suma(ca, cb);
		if(aux < diametro)
		{
			diametro = aux;
			pseudocentro = v;
		}
	}
	
	return diametro;
}

#endif /* problema2_h */
