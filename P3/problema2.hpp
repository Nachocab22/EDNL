#ifndef PROBLEMA2_HPP
#define PROBLEMA2_HPP

#include "../agen.h"

//Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine la profundidad de éste nodo en el árbol. 

template <typename T>
int profundidadAgen(Agen<T> A, typename Agen<T>::nodo n)
{
    int prof = 0;

    if(A.arbolVacio())
        return 0;
    else
        while (n != A.raiz())
        {
            prof++;
            n = A.padre(n);
        }
    return 1 + prof;
}

#endif