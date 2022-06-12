#include "../abin.h"

//Implementa un subprograma que calcule el número de nodos de un árbol binario. 
template <typename T>
int numNodos(const Abin<T> A)
{
    if(A.arbolVacio)
        return 0;
    else
        return 1 + numNodosRec(A.raiz);
}

template <typename T>
int numNodosRec(typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + numNodosRec(n->hder) + numNodosRec(n->hizq);
}