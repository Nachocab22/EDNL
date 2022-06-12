//
//  problema4.h
//  P6
//
//  Created by JM on 10/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema4_h
#define problema4_h
#include "../../material/alg_grafoPMC.h"

typedef double km;
typedef GrafoP<km>::vertice ciudad;
typedef struct
{
	ciudad a, b;
} Carretera;

matriz<km> Calcular_costes_zuelandia(const GrafoP<km> &Ciudades,
									 const vector<bool> &Ciudades_tomadas,
									 const Lista<Carretera> &Carreteras_tomadas,
									 ciudad capital)
{
	size_t n;
	ciudad i, j;
	Lista<Carretera>::posicion p;
	matriz<km> Costes_minimos;
	matriz<ciudad> Caminos;
	
	GrafoP<km> Estado_actual = Ciudades;
	n = Ciudades.numVert();
	
	for(i = 0; i <= n-1; i++)	// Tomamos ciudades
		if(Ciudades_tomadas[i])
			for(j = 0; j <= n-1; j++)
				Estado_actual[j][i] = Estado_actual[i][j] = GrafoP<km>::INFINITO;
	
	p = Carreteras_tomadas.primera();
	while(p != Carreteras_tomadas.fin())	// Tomamos carreteras
	{
		i = Carreteras_tomadas.elemento(p).a;
		j = Carreteras_tomadas.elemento(p).b;
		Estado_actual[i][j] = Estado_actual[j][i] = GrafoP<km>::INFINITO;
		p = Carreteras_tomadas.siguiente(p);
	}
	
	Costes_minimos = Floyd(Estado_actual, Caminos);
	
	for(i = 0; i <= n-1; i++)
		for(j = 0; j <= n-1; j++)
			if(i != j)
				Costes_minimos[i][j] = suma(Costes_minimos[i][capital],
											Costes_minimos[capital][j]);
	
	return Costes_minimos;
}

#endif /* problema4_h */
