//
//  problema7.h
//  P8
//
//  Created by JM on 01/09/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema7_h
#define problema7_h
#include <cmath>

typedef GrafoP<float>::vertice ciudad;
typedef struct
{
	float x, y;
} Coordenada;
typedef enum{FOBOS, DEIMOS} Isla;
typedef enum{PRIMERO, SEGUNDO, TERCERO, CUARTO} Cuadrante;

inline float Distancia_euclidea(Coordenada a, Coordenada b)
{
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

inline float distancia(Coordenada a, Coordenada b)
{
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

Cuadrante Determinar_cuadrante(ciudad i, ciudad j, size_t N)
{
	if(i <= N-1)
	{
		if(j <= N-1)
			return PRIMERO;
		else
			return SEGUNDO;
	}
	else
	{
		if(j <= N-1)
			return CUARTO;
		else
			return TERCERO;
	}
}

GrafoP<float> Combinar_costes(const GrafoP<float> &Distancias_fobos, const GrafoP<float> &Distancias_deimos)
{
	size_t N_fobos, N_deimos, N;
	ciudad i, j;
	
	N_fobos = Distancias_fobos.numVert();
	N_deimos = Distancias_deimos.numVert();
	N = N_fobos + N_deimos;
	GrafoP<float> Combinados(N);
	
	for(i = 0; i <= N-1; i++)
		for(j = 0; j <= N-1; j++)
			switch(Determinar_cuadrante(i, j, N_fobos))
			{
				case PRIMERO: Combinados[i][j] = Distancias_fobos[i][j]; break;
				case SEGUNDO: case CUARTO: Combinados[i][j] = GrafoP<float>::INFINITO; break;
				case TERCERO: Combinados[i][j] = Distancias_deimos[i-N_fobos][j-N_fobos]; break;
			}
	
	return Combinados;
}

GrafoP<float> Calcular_distancias(const vector<Coordenada> &Distancias)
{
	size_t N;
	ciudad i, j;
	
	N = Distancias.size();
	GrafoP<float> G(N);
	for(i = 0; i <= N-1; i++)
		for(j = 0; j <= N-1; j++)
			if(i == j)
				G[i][j] = 0;
			else
				G[i][j] = Distancia_euclidea(Distancias[i], Distancias[j]);
	
	return G;
}

float Coste_viajar(const vector<Coordenada> &Distancias_fobos, const vector<Coordenada> &Distancias_deimos,
				   const vector<bool> &Costa_fobos, const vector<bool> &Costa_deimos, ciudad origen, ciudad destino,
				   Isla isla_origen, Isla isla_destino)
{
	float minimo, aux;
	vector<float> costes_minimos;
	vector<ciudad> caminos;
	size_t N_fobos, N_deimos;
	ciudad i, j, puente1 = 0, puente2 = 0;
	
	N_fobos = Distancias_fobos.size();
	N_deimos = Distancias_deimos.size();
	GrafoP<float> Fobos_directos = Calcular_distancias(Distancias_fobos),
	Deimos_directos = Calcular_distancias(Distancias_deimos);
	
	//GrafoP<float> Combinados = Combinar_costes(Distancias_fobos, Distancias_deimos);
	GrafoP<float> Fobos_minimo = Kruskall(Fobos_directos),
	Deimos_minimo = Kruskall(Deimos_directos);
	
	// Crear el puente más barato
	minimo = GrafoP<float>::INFINITO;
	for(i = 0; i <= N_fobos-1; i++)
		if(Costa_fobos[i])
			for(j = 0; j <= N_deimos; j++)
				if(Costa_deimos[i])
				{
					aux = Distancia_euclidea(Distancias_fobos[i], Distancias_deimos[j]);
					if(aux < minimo)
					{
						minimo = aux;
						puente1 = i;
						puente2 = j + N_fobos;
					}
				}
	
	GrafoP<float> Combinados = Combinar_costes(Fobos_minimo, Deimos_minimo);
	Combinados[puente1][puente2] = Combinados[puente2][puente1] = Distancia_euclidea(Distancias_fobos[puente1],
																					 Distancias_deimos[puente2 - N_fobos]);
	
	if(isla_origen == DEIMOS)
		origen += N_fobos;
	if(isla_destino == DEIMOS)
		destino += N_fobos;
	
	return Dijkstra(Combinados, origen, caminos)[destino];
}

#endif /* problema7_h */
