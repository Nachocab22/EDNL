//
//  problema1.h
//  P8
//
//  Created by JM on 31/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema1_h
#define problema1_h
#include <cmath>

typedef GrafoP<float>::vertice ciudad;
typedef struct
{
	float x, y;
} Coordenada;

inline float distancia(Coordenada a, Coordenada b)
{
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

matriz<float> Calcular_costes(const vector<Coordenada> &Posiciones, const matriz<bool> &Adyacentes,
							  Particion &p)
{
	int N, i, j, rep1, rep2;
	matriz<ciudad> caminos;
	
	N = (int)Posiciones.size();
	p = Particion(N);
	GrafoP<float> costes_minimos(N);
	
	for(i = 0; i <= N-1; i++)
	{
		rep1 = p.encontrar(i);
		for(j = 0; j <= N-1; j++)
			if(Adyacentes[i][j])
			{
				rep2 = p.encontrar(j);
				if(rep1 != rep2)
					p.unir(rep1, rep2);
			}
	}
	
	for(i = 0; i <= N-1; i++)
		for(j = 0; j <= N-1; j++)
			if(Adyacentes[i][j])
				costes_minimos[i][j] = distancia(Posiciones[i], Posiciones[j]);
			else
				costes_minimos[i][j] = GrafoP<float>::INFINITO;
	
	return Floyd(costes_minimos, caminos);
}

#endif /* problema1_h */
