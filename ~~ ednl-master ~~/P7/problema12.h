//
//  problema12.h
//  P7
//
//  Created by JM on 31/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema12_h
#define problema12_h

typedef GrafoP<float>::vertice ciudad;
typedef struct
{
	ciudad ciudad_fobos, ciudad_deimos;
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

Puente Generar_puente(const matriz<float> &Deimos, const matriz<float> &Fobos,
					  const vector<ciudad> &Costa_deimos, const vector<ciudad> &Costa_fobos)
{
	Puente p;
	size_t N_deimos, N_fobos;
	ciudad i, j, actual;
	float coste_candidato, aux;
	matriz<float> costes_deimos, costes_fobos;
	matriz<ciudad> caminos_deimos, caminos_fobos;
	
	N_fobos = Fobos.dimension();
	N_deimos = Deimos.dimension();
	costes_deimos = Floyd(Matriz_a_grafo(Deimos), caminos_deimos);
	costes_fobos = Floyd(Matriz_a_grafo(Fobos), caminos_fobos);
	
	coste_candidato = GrafoP<float>::INFINITO;
	for(i = 0; i <= Costa_fobos.size()-1; i++)
	{
		actual = Costa_fobos[i];
		aux = 0;
		for(j = 0; j <= N_fobos-1; j++)
			aux = suma(aux, costes_fobos[actual][j]);
		if(aux < coste_candidato)
		{
			coste_candidato = aux;
			p.ciudad_fobos = actual;
		}
	}
	
	coste_candidato = GrafoP<float>::INFINITO;
	for(i = 0; i <= Costa_deimos.size()-1; i++)
	{
		actual = Costa_deimos[i];
		aux = 0;
		for(j = 0; j <= N_deimos-1; j++)
			aux = suma(aux, costes_deimos[actual][j]);
		if(aux < coste_candidato)
		{
			coste_candidato = aux;
			p.ciudad_deimos = actual;
		}
	}
	
	return p;
}

#endif /* problema12_h */
