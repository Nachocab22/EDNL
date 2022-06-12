//
//  problema11.h
//  P7
//
//  Created by JM on 31/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema11_h
#define problema11_h

typedef GrafoP<float>::vertice ciudad;
typedef struct
{
	ciudad a, b;
} Puente;
typedef enum{NINGUNA, ISLA1, ISLA2, ISLA3} Isla;

Isla Determinar_isla(ciudad i, ciudad j, size_t N1, size_t N2, size_t N3)
{
	if(i <= N1-1 && j <= N1-1)
		return ISLA1;
	else
		if(i >= N1 && i <= N1+N2-1 && j >= N1 && j <= N1+N2-1)
			return ISLA2;
		else
			if(i >= N1+N2 && i <= N1+N2+N3-1 && j >= N1+N2 && j <= N1+N2+N3-1)
				return ISLA3;
			else
				return NINGUNA;
}

matriz<float> Costes_minimos(const GrafoP<float> &Isla1, const GrafoP<float> &Isla2,
							 const GrafoP<float> &Isla3, const vector<Puente> &Puentes)
{
	size_t N1, N2, N3;
	matriz<float> costes;
	matriz<ciudad> caminos;
	ciudad i, j;
	Puente p;
	
	N1 = Isla1.numVert();
	N2 = Isla2.numVert();
	N3 = Isla3.numVert();
	GrafoP<float> Combinados(N1 + N2 + N3);
	
	for(i = 0; i <= N1+N2+N3-1; i++)
		for(j = 0; j <= N1+N2+N3-1; j++)
			switch(Determinar_isla(i, j, N1, N2, N3))
			{
				case NINGUNA: 	Combinados[i][j] = GrafoP<float>::INFINITO; break;
				case ISLA1: 	Combinados[i][j] = Isla1[i][j]; break;
				case ISLA2: 	Combinados[i][j] = Isla2[i-N1][j-N2]; break;
				case ISLA3: 	Combinados[i][j] = Isla3[i-N1-N2][j-N1-N2]; break;
			}
	
	for(i = 0; i <= N1+N2+N3-1; i++)
		Combinados[i][i] = 0;
	
	for(i = 0; i <= Puentes.size()-1; i++)
	{
		p = Puentes[i];
		Combinados[p.a][p.b] = Combinados[p.b][p.a] = 0;
	}
	
	return Floyd(Combinados, caminos);
}

#endif /* problema11_h */
