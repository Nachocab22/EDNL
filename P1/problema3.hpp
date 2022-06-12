#include "../abin.h"

//Implementa un subprograma que, dado un Abin y un nodo del mismo, determine la profundidad de este nodo en dicho arbol
template <typename T>
int profundidad(const Abin<T> A, typename Abin<T>::nodo n)
{
    if(n == A.raiz)
        return 0;
    else
        return 1 + profundidad(A, n->padre);
}