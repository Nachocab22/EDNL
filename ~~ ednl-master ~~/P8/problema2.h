//
//  problema2.h
//  P8
//
//  Created by JM on 31/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema2_h
#define problema2_h
#include "problema1.h"

int Contar_islas(Particion p, size_t N, vector<int> &relacion)
{
	int n_islas, i, rep;
	
	relacion = vector<int>(N);
	n_islas = 1;
	
	for(i = 0; i <= N-1; i++)
		relacion[i] = p.encontrar(i);
	
	rep = p.encontrar(0);
	for(i = 0; i <= N-1; i++)
	{
		if(rep != p.encontrar(i))
		{
			p.unir(0, i);
			n_islas++;
			rep = p.encontrar(0);
		}
	}
	
	return n_islas;
}

bool esta(const vector<int> &v, int x)
{
	bool encontrado;
	int i;
	
	i = 0;
	encontrado = false;
	while(i <= (int)v.size()-1 && !encontrado)
	{
		encontrado = v[i] == x;
		i++;
	}
	
	return encontrado;
}

vector<int> Relacionar_isla_rep(const vector<int> &ciudad_rep, size_t N)
{
	vector<int> isla_rep;
	int i;
	
	for(i = 0; i <= N-1; i++)
		if(!esta(isla_rep, ciudad_rep[i]))
			isla_rep.push_back(ciudad_rep[i]);
	
	return isla_rep;
}

int Buscar_isla(const vector<int> &isla_rep, int representante)
{
	bool encontrado;
	int i;
	
	i = 0;
	encontrado = false;
	while(i <= isla_rep.size()-1 && !encontrado)
		if(isla_rep[i] == representante)
			encontrado = true;
		else
			i++;
	
	return i;
}

matriz<int> Implantar_lineas(const matriz<bool> &Adyacentes, const vector<Coordenada> &Posiciones)
{
	Particion p(1);
	vector<int> ciudad_rep, isla_rep;
	size_t n, n_islas;
	int i;
	
	Calcular_costes(Posiciones, Adyacentes, p);
	
	n = Adyacentes.dimension();
	n_islas = Contar_islas(p, n, ciudad_rep);
	matriz<int> lineas(n_islas);
	isla_rep = Relacionar_isla_rep(ciudad_rep, n);
	
	//for(i = 0; i <= n_islas-1; i++)
		
	
	return lineas;
}

#endif /* problema2_h */
