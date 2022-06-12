//
//  problema5.h
//  P7
//
//  Created by JM on 14/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema5_h
#define problema5_h
#include "../../material/alg_grafoPMC.h"

typedef enum {TREN, AVION, COCHE} tipo_viaje;
typedef enum {PRIMERO, SEGUNDO, TERCERO, CUARTO} cuadrante;
typedef GrafoP<float>::vertice ciudad;

GrafoP<float> Combinar_costes(const GrafoP<float> &trans1,
							  const GrafoP<float> &trans2)
{
	size_t n;
	ciudad i, j;
	float infinito;
	
	n = trans1.numVert();
	infinito = GrafoP<float>::INFINITO;
	GrafoP<float> costes_combinados(n+n);
	
	for(i = 0; i <= n-1; i++)
		for(j = 0; j <= n-1; j++)
			costes_combinados[i][j] = std::min(trans1[i][j], trans2[i][j]);

	return costes_combinados;
}

vector<bool> Posibles_visitas(const GrafoP<float> &directos_tren,
							  const GrafoP<float> &directos_avion,
							  const GrafoP<float> &directos_coche,
							  float dinero_disponible, tipo_viaje alergia,
							  ciudad origen)
{
	size_t n;
	ciudad i;
	GrafoP<float> costes_combinados(1);
	vector<float> costes_minimos;
	vector<ciudad> caminos;
	float inf;
	
	n = directos_tren.numVert();
	vector<bool> posibles(n);
	inf = GrafoP<float>::INFINITO;
	switch (alergia) {
		case TREN:
			costes_combinados = Combinar_costes(directos_avion, directos_coche);
			break;
		case AVION:
			costes_combinados = Combinar_costes(directos_tren, directos_coche);
			break;
		case COCHE:
			costes_combinados = Combinar_costes(directos_tren, directos_avion);
			break;
	}
	
	costes_minimos = Dijkstra(costes_combinados, origen, caminos);
	
	for(i = 0; i <= n-1; i++)
		posibles[i] = costes_minimos[i] <= dinero_disponible;
	
	return posibles;
}

#endif /* problema5_h */
