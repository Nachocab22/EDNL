//
//  problema9.h
//  P7
//
//  Created by JM on 19/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema9_h
#define problema9_h

typedef GrafoP<float>::vertice ciudad;
typedef enum {PRIMERO, SEGUNDO, TERCERO, CUARTO} Cuadrante;

Cuadrante Determinar_cuadrante(size_t i, size_t j, size_t n)
{
	if(i <= n-1)
	{
		if(j <= n-1)
			return PRIMERO;
		else
			return SEGUNDO;
	}
	else
	{
		if(j <= n-1)
			return CUARTO;
		else
			return TERCERO;
	}
}

GrafoP<float> Combinar_costes(const GrafoP<float> &tren, const GrafoP<float> &bus,
							  float trasbordo)
{
	size_t n;
	ciudad i, j;
	
	n = tren.numVert();
	GrafoP<float> C(2*n);
	
	for(i = 0; i <= 2*n-1; i++)
		C[i][i] = 0;
	
	for(i = 0; i <= 2*n-1; i++)
		for(j = 0; j <= 2*n-1; j++)
			switch(Determinar_cuadrante(i, j, n))
			{
				case PRIMERO: C[i][j] = tren[i][j]; break;
				case TERCERO: C[i][j] = bus[i][j]; break;
				case SEGUNDO: case CUARTO: break;
			}
	
	for(i = 0; i <= 2*n-1; i++)
		for(j = 0; j <= 2*n-1; j++)
		{
			if(i == j + n || i + n == j)
				C[i][j] = trasbordo;
			else
				C[i][j] = GrafoP<float>::INFINITO;
		}
	return C;
}

float Generar_viaje(const GrafoP<float> &tren, const GrafoP<float> &bus, float trasbordo,
					ciudad origen1, ciudad destino1, Lista<ciudad> &Ruta)
{
	vector<float> costes_minimos1, costes_minimos2;
	vector<ciudad> caminos1, caminos2;
	ciudad origen2, destino2;
	size_t n;
	float minimo;
	
	GrafoP<float> G = Combinar_costes(tren, bus, trasbordo);
	n = tren.numVert();
	destino2 = destino1 + n;
	origen2 = origen1 + n;
	
	costes_minimos1 = Dijkstra(G, origen1, caminos1);
	costes_minimos2 = Dijkstra(G, origen2, caminos2);
	
	minimo = std::min(std::min(costes_minimos1[destino1], costes_minimos1[destino2]),
					  std::min(costes_minimos2[destino1], costes_minimos2[destino2]));
	
	if(minimo == costes_minimos1[destino1])
		Ruta = camino<float>(origen1, destino1, caminos1);
	else
		if(minimo == costes_minimos1[destino2])
			Ruta = camino<float>(origen1, destino2, caminos1);
		else
			if(minimo == costes_minimos2[destino1])
				Ruta = camino<float>(origen2, destino1, caminos2);
			else
				Ruta = camino<float>(origen2, destino2, caminos2);
	
	return minimo;
}

#endif /* problema9_h */
