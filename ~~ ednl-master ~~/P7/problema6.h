//
//  problema6.h
//  P7
//
//  Created by JM on 16/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema6_h
#define problema6_h
typedef GrafoP<float>::vertice ciudad;

float coste_min(const matriz<float> &A, const matriz<float> &B, ciudad origen, ciudad destino,
				ciudad transbordo)
{
	float d, t;
	
	if(origen == destino)
		return 0;
	else
	{
		d = std::min(A[origen][destino], B[origen][destino]);
		t = std::min(suma(A[origen][transbordo], B[transbordo][origen]),
					 suma(B[origen][transbordo], A[transbordo][destino]));
		
		return std::min(d, t);
	}
}

matriz<float> Costes_entre_ciudades(const GrafoP<float> &costes_directos_tren,
									const GrafoP<float> &costes_directos_bus, ciudad trans)
{
	matriz<float> costes_minimos_tren, costes_minimos_bus, costes_minimos;
	matriz<ciudad> caminos;
	size_t n;
	ciudad i,j;
	
	n = costes_directos_tren.numVert();
	costes_minimos_tren = Floyd(costes_directos_tren, caminos);
	costes_minimos_bus = Floyd(costes_directos_bus, caminos);
	costes_minimos = matriz<float>(n);
	
	for(i = 0; i <= n-1; i++)
		for(j = 0; j <= n-1; j++)
			costes_minimos[i][j] = coste_min(costes_minimos_tren, costes_minimos_bus, i, j,
											 trans);
	
	return costes_minimos;
}

#endif /* problema6_h */
