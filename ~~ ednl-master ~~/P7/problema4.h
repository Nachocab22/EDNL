//
//  problema4.h
//  P7
//
//  Created by JM on 11/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema4_h
#define problema4_h
#include "../../material/alg_grafoPMC.h"

typedef float km;
typedef GrafoP<km>::vertice cliente;
typedef GrafoP<km>::vertice ciudad;

km Kilometraje_total(const GrafoP<km> &Zuelandia, const vector<int> &trabajo,
					 ciudad capital)
{
	km kilometraje;
	size_t n;
	vector<km> costes_ida, costes_vuelta;
	vector<ciudad> caminos_ida, caminos_vuelta;
	cliente i;
	
	n = Zuelandia.numVert();
	kilometraje = 0;
	costes_ida = Dijkstra(Zuelandia, capital, caminos_ida);
	costes_vuelta = Dijkstra_inv(Zuelandia, capital, caminos_vuelta);
	
	for(i = 0; i <= n-1; i++)
		kilometraje += trabajo[i] * suma(costes_ida[i], costes_vuelta[i]);
	
	return kilometraje;
}

#endif /* problema4_h */
