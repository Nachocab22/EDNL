//
//  problema1.h
//  P6
//
//  Created by JM on 09/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema1_h
#define problema1_h
#include "../../material/grafoPMC.h"

template <typename tCoste>
vector<tCoste> Dijkstra_inv(const GrafoP<tCoste>& G,
							typename GrafoP<tCoste>::vertice destino,
							vector<typename GrafoP<tCoste>::vertice>& P)
{
   typedef typename GrafoP<tCoste>::vertice vertice;
   vertice v, w;
   const size_t n = G.numVert();
   vector<bool> S(n, false);                  // Conjunto de vértices vacío.
   vector<tCoste> D;                          // Costes mínimos desde origen.

   // Iniciar D y P con caminos directos desde el vértice origen.
	for(v = 0; v <= n-1; v++)
		D[v] = G[v][destino];
   D[destino] = 0;                             // Coste origen-origen es 0.
   P = vector<vertice>(n, destino);

   // Calcular caminos de coste mínimo hasta cada vértice.
   S[destino] = true;                          // Incluir vértice origen en S.
   for (size_t i = 1; i <= n-2; i++) {
      // Seleccionar vértice w no incluido en S
      // con menor coste desde origen.
      tCoste costeMin = GrafoP<tCoste>::INFINITO;
      for (v = 0; v < n; v++)
         if (!S[v] && D[v] <= costeMin) {
            costeMin = D[v];
            w = v;
         }
      S[w] = true;                          // Incluir vértice w en S.
      // Recalcular coste hasta cada v no incluido en S a través de w.
      for (v = 0; v < n; v++)
         if (!S[v]) {
            tCoste vwD = suma(G[v][w], D[w]);
            if (vwD < D[v]) {
               D[v] = vwD;
               P[v] = w;
            }
         }
   }
   return D;
}

#endif /* problema1_h */
