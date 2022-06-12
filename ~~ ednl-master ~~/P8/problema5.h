//
//  problema5.h
//  P8
//
//  Created by JM on 01/09/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema5_h
#define problema5_h

typedef GrafoP<float>::vertice ciudad;

float Longitud_minima(const GrafoP<float> &Distancias)
{
	float distancia;
	ciudad i, j;
	size_t N;
	
	GrafoP<float> Conexiones_minimas = Kruskall(Distancias);
	
	N = Distancias.numVert();
	i = 0;
	distancia = 0;
	for(i = 0; i <= N-1; i++)
		for(j = 0; j <= N-1; j++)
			if(Conexiones_minimas[i][j] != GrafoP<float>::INFINITO)
			{
				distancia += Conexiones_minimas[i][j];
				conectado = true;
			}
	
	return distancia;
}

#endif /* problema5_h */
