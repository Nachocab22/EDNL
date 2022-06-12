//
//  problema2.h
//  P7
//
//  Created by JM on 10/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema2_h
#define problema2_h
#include "../../material/alg_grafoPMC.h"

typedef int paso;
typedef GrafoP<paso>::vertice nodo;
typedef struct
{
	int fila, columna;
} casilla;
typedef struct
{
	casilla a, b;
} Pared;

casilla nodo_a_casilla(const nodo &n, size_t N)
{
	casilla c;
	c.columna = (int)(n % N);
	c.fila = (int)(n / N);
	return c;
}

nodo casilla_a_nodo(const casilla &c, size_t N)
{
	return c.columna + N * c.fila;
}

vector<casilla> Rehacer_camino(const Lista<nodo> &solucion, size_t N)
{
	vector<casilla> camino;
	Lista<nodo>::posicion p;
	casilla aux;
	
	p = solucion.primera();
	while(p != solucion.fin())
	{
		aux = nodo_a_casilla(solucion.elemento(p), N);
		camino.push_back(aux);
		p = solucion.siguiente(p);
	}
	
	return camino;
}

inline bool Son_adyacentes(const casilla &c1, const casilla &c2)
{
	return abs(c1.fila - c2.fila) + abs(c1.columna - c2.columna) == 1;
}

void Actualizar_casillas_adyacentes(GrafoP<paso> &Laberinto, size_t N)
{
	nodo n1, n2;
	casilla c1, c2;
	size_t n;
	
	n = Laberinto.numVert();
	for(n1 = 0; n1 <= n-1; n1++)
		for(n2 = 0; n2 <= n-1; n2++)
		{
			if(n1 != n2)
			{
				c1 = nodo_a_casilla(n1, N);
				c2 = nodo_a_casilla(n2, N);
				if(Son_adyacentes(c1, c2))
					Laberinto[n1][n2] = 1;
				else
					Laberinto[n1][n2] = GrafoP<paso>::INFINITO;
			}
			else
				Laberinto[n1][n2] = 0;
		}
}

paso Resolver_laberinto(size_t dimension, const Lista<Pared> &Paredes,
						casilla entrada, casilla salida,
						vector<casilla> &solucion)
{
	Lista<Pared>::posicion p;
	vector<nodo> caminos;
	vector<paso> costes;
	size_t N;
	nodo i, j, nodo_entrada, nodo_salida;
	
	N = dimension * dimension;
	GrafoP<paso> Laberinto(N);
	
	Actualizar_casillas_adyacentes(Laberinto, dimension);
	
	p = Paredes.primera();
	while(p != Paredes.fin())
	{
		i = casilla_a_nodo(Paredes.elemento(p).a, dimension);
		j = casilla_a_nodo(Paredes.elemento(p).b, dimension);
		Laberinto[i][j] = Laberinto[j][i] = GrafoP<paso>::INFINITO;
		p = Paredes.siguiente(p);
	}
	
	nodo_entrada = casilla_a_nodo(entrada, dimension);
	nodo_salida = casilla_a_nodo(salida, dimension);
	costes = Dijkstra(Laberinto, nodo_entrada, caminos);
	
	solucion = Rehacer_camino(camino<paso>(nodo_entrada, nodo_salida,
										   caminos), dimension);
	
	return costes[nodo_salida];
}

#endif /* problema2_h */
