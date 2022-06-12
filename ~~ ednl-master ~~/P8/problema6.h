//
//  problema6.h
//  P8
//
//  Created by JM on 01/09/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema6_h
#define problema6_h

typedef GrafoP<float>::vertice ciudad;
typedef struct
{
	int longitud;
	int caudal_max;
} Canal;

matriz<Canal> Construir_canales(const matriz<float> &Distancias, const matriz<float> &Caudales,
								 float subvencion_caudal, float precio_km)
{
	size_t N;
	ciudad i,j;
	
	N = Distancias.dimension();
	GrafoP<float> Precios(N);
	matriz<Canal> Canales(N);
	
	for(i = 0; i <= N-1; i++)
		for(j = 0; j <= N-1; j++)
			Precios[i][j] = Distancias[i][j] * precio_km - Caudales[i][j] * subvencion_caudal;
	
	GrafoP<float> Precios_minimos = Kruskall(Precios);
	for(i = 0; i <= N-1; i++)
		for(j = 0; j <= N-1; j++)
			if(Precios_minimos[i][j] == GrafoP<float>::INFINITO)
			{
				Canales[i][j].longitud = GrafoP<float>::INFINITO;
				Canales[i][j].caudal_max = 0;
			}
			else
			{
				Canales[i][j].longitud = Distancias[i][j];
				Canales[i][j].caudal_max = Caudales[i][j];
			}
	
	return Canales;
}

#endif /* problema6_h */
