//
//  main.cpp
//  P7
//
//  Created by JM on 10/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#include <iostream>
#include "../../material/alg_grafo_E-S.h"
#include "../../material/alg_grafoPMC.h"
#include "problema13.h"
using namespace std;

int main(int argc, const char * argv[]) {
	size_t n = 5;
	GrafoP<int> costes(n);
	vector<int> trabajo;
	double inf = GrafoP<double>::INFINITO;
	
	vector<vector<double>> v = {
		{0, inf, inf, inf, 8},
		{inf, 0, 1, inf, 2},
		{inf, 3, 0, inf, inf},
		{inf, inf, 1, 0, inf},
		{8, inf, 7, 3, 0}
	};
	
	trabajo = {0, 20, 50, 6, 15};
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			costes[i][j] = v[i][j];
}
