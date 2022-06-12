//
//  problema3.h
//  P7
//
//  Created by JM on 10/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema3_h
#define problema3_h
#include "../../material/alg_grafoPMC.h"

typedef GrafoP<double>::vertice ciudad;

GrafoP<double> Matriz_a_grafo(const matriz<double> &M)
{
	ciudad i;
	size_t n;
	
	n = M.dimension();
	GrafoP<double> G(n);
	for(i = 0; i <= n-1; i++)
		G[i] = M[i];
	
	return G;
}

ciudad Ciudad_mas_barata(const vector<double> &costes)
{
	ciudad i, mas_barata;
	size_t n;
	
	n = costes.size();
	mas_barata = 0;
	for(i = 1; i <= n-1; i++)
		if(costes[i] < costes[mas_barata])
			mas_barata = i;
	
	return mas_barata;
}

double Costes_de_distribucion(const matriz<double> &costes, ciudad centro,
							  const vector<int> &capacidad_ciudad,
							  const vector<float> &subvencion_ciudad,
							  int cantidad, vector<int> &almacenado_ciudad)
{
	double costes_dist;
	vector<double> costes_minimos;
	vector<ciudad> caminos;
	ciudad i;
	size_t n, ciudades_disponibles;
	int almacenado;
	
	costes_minimos = Dijkstra(Matriz_a_grafo(costes), centro, caminos);
	
	n = costes.dimension();
	for(i = 0; i <= n-1; i++)	// Actualizamos costes
		costes_minimos[i] *= (1 - subvencion_ciudad[i]);
	
	costes_minimos[centro] = GrafoP<double>::INFINITO;
	ciudades_disponibles = n;
	
	costes_dist = 0;
	while(cantidad > 0 && ciudades_disponibles > 0)
	{
		i = Ciudad_mas_barata(costes_minimos);
		
		if(cantidad > capacidad_ciudad[i])
			almacenado = capacidad_ciudad[i];
		else
			almacenado = cantidad;
		
		costes_dist += (almacenado * costes_minimos[i]);
		costes_minimos[i] = GrafoP<double>::INFINITO;
		almacenado_ciudad[i] = almacenado;
		cantidad -= almacenado;
		ciudades_disponibles--;
		i++;
	}
	
	return costes_dist;
}

#endif /* problema3_h */
