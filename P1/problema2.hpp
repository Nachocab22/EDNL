#include "../abin.h"

//Implementa un subprograma que calcule la altura de un arbol binario
template <typename T>
int alturaAbin(const Abin<T> A)
{
    if(A.arbolVacio)
        return -1;
    else
        return alturaAbinRec(A.raiz);
}

template <typename T>
int alturaAbinRec(typename Abin<T>::nodo n)
{  
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + std::max(alturaAbinRec(n->hizq), alturaAbinRec(n->hder));
}