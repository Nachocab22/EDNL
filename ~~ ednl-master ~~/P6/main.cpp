//
//  main.cpp
//  P6
//
//  Created by JM on 09/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#include <iostream>
#include "problema4.h"
#include "../../material/alg_grafo_E-S.h"
using namespace std;

int main(int argc, const char * argv[]) {
	size_t n = 5;
	GrafoP<km> G(n);
	vector<bool> Ciudades_tomadas(n, false);
	Lista<Carretera> Carreteras_tomadas;
	ciudad capital = 4;
	km inf = GrafoP<km>::INFINITO;
	vector<vector<km>> v = {
		{0, inf, inf, inf, 8},
		{inf, 0, 1, inf, 2},
		{inf, 3, 0, inf, inf},
		{inf, inf, 1, 0, inf},
		{8, inf, 7, 3, 0}
	};
	
	for(int i = 0; i < n; i++)
		G[i] = v[i];
	
	cout << G << endl;
	
	Ciudades_tomadas[0] = true;
	Carretera tomada;
	tomada.a = 3;
	tomada.b = 4;
	Carreteras_tomadas.insertar(tomada, Carreteras_tomadas.fin());
	
	cout << "Después de la guerra:\n" << Calcular_costes_zuelandia(G, Ciudades_tomadas, Carreteras_tomadas, capital) << '\n';
	
	return 0;
}
