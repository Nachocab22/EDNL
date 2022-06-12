//
//  problema4.h
//  P8
//
//  Created by JM on 01/09/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema4_h
#define problema4_h
#include "problema3.h"

template <typename tCoste>
GrafoP<tCoste> Kruskall_modificado(const GrafoP<tCoste>& G)
// Devuelve un árbol generador de coste mínimo
// de un grafo no dirigido ponderado y conexo G.
{
   assert(!G.esDirigido());

   typedef typename GrafoP<tCoste>::vertice vertice;
   typedef typename GrafoP<tCoste>::arista arista;
   const tCoste INFINITO = GrafoP<tCoste>::INFINITO;
   const size_t n = G.numVert();
   GrafoP<tCoste> g(n);   // Árbol generador de coste máximo.
   Particion P(n);   // Partición inicial del conjunto de vértices de G.
   Apo_max<arista> A(n*n);    // Aristas de G ordenadas por costes.

   // Copiar aristas del grafo G en el APO A.
   for (vertice u = 0; u < n; u++)
      for (vertice v = u+1; v < n; v++)
         if (G[u][v] != INFINITO)
            A.insertar(arista(u, v, G[u][v]));

   size_t i = 1;
   while (i <= n-1) {   // Seleccionar n-1 aristas.
      arista a = A.cima(); // arista de mayor coste
      A.suprimir();
      vertice u = P.encontrar(a.orig);
      vertice v = P.encontrar(a.dest);
      if (u != v) { // Los extremos de a pertenecen a componentes distintas
         P.unir(u, v);
         // Incluir la arista a en el árbol g
         g[a.orig][a.dest] = g[a.dest][a.orig] = a.coste;
         i++;
      }
   }
   return g;
}

GrafoP<float> Calculas_canales_maximos(const GrafoP<float> &Jerte)
{
	return Kruskall_modificado(Jerte);
}

#endif /* problema4_h */
