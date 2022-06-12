//
//  problema13.h
//  P7
//
//  Created by JM on 31/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema13_h
#define problema13_h

typedef GrafoP<float>::vertice ciudad;
typedef struct
{
	ciudad c;
	int isla;
} Ciudad_isla;
typedef struct
{
	Ciudad_isla c1, c2;
} Puente;

GrafoP<float> Matriz_a_grafo(const matriz<float> &M)
{
	GrafoP<float> G(M.dimension());
	size_t N;
	ciudad i, j;
	
	N = G.numVert();
	for(i = 0; i <= N-1; i++)
		for(j = 0; j <= N-1; j++)
			G[i][j] = M[i][j];
	
	return G;
}

void Reconstruir_puentes(const matriz<float> &Isla1, const matriz<float> &Isla2,
						 const matriz<float> &Isla3, const vector<ciudad> &Costa1,
						 const vector<ciudad> &Costa2, const vector<ciudad> &Costa3, Puente &p1,
						 Puente &p2)
{
	matriz<float> Costes_isla1, Costes_isla2, Costes_isla3;
	matriz<ciudad> Caminos_isla1, Caminos_isla2, Caminos_isla3;
	ciudad costera;
	size_t i, N_ciudades, N_costa;
	float actual, menor, j;
	Ciudad_isla c1, c2, c3;
	
	N_ciudades = Isla1.dimension();
	N_costa = Costa1.size();
	menor = GrafoP<float>::INFINITO;
	for(i = 0; i <= N_costa-1; i++)
	{
		costera = Costa1[i];
		actual = 0;
		for(j = 0; j <= N_ciudades-1; j++)
			actual = suma(actual, Costes_isla1[actual][j]);
		if(actual < menor)
		{
			menor = actual;
			c1.c = costera;
		}
	}
	
	N_ciudades = Isla2.dimension();
	N_costa = Costa2.size();
	menor = GrafoP<float>::INFINITO;
	for(i = 0; i <= N_costa-1; i++)
	{
		costera = Costa2[i];
		actual = 0;
		for(j = 0; j <= N_ciudades-1; j++)
			actual = suma(actual, Costes_isla2[actual][j]);
		if(actual < menor)
		{
			menor = actual;
			c2.c = costera;
		}
	}
	
	N_ciudades = Isla3.dimension();
	N_costa = Costa3.size();
	menor = GrafoP<float>::INFINITO;
	for(i = 0; i <= N_costa-1; i++)
	{
		costera = Costa3[i];
		actual = 0;
		for(j = 0; j <= N_ciudades-1; j++)
			actual = suma(actual, Costes_isla3[actual][j]);
		if(actual < menor)
		{
			menor = actual;
			c3.c = costera;
		}
	}
	
	c1.isla = 1;
	c2.isla = 2;
	c3.isla = 3;
	p1.c1 = p2.c1 = c1;
	p1.c2 = c2;
	p2.c2 = c3;
}

#endif /* problema13_h */
