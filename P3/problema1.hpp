#ifndef PROBLEMA1_HPP
#define PROBLEMA1_HPP

#include "../agen.h"

//Implementa un subprograma que dado un árbol general nos calcule su grado.

template <typename T>
int contarHijos(Agen<T> A, typename Agen<T>::nodo n)
{
    int hijos = 0;
    typename Agen<T>::nodo hijo;

    hijo = A.hijoIzqdo(n);

    while(hijo != Agen<T>::NODO_NULO)
    {
        hijos++;
        hijo = A.hermDrcho(hijo);
    }

    return hijos;
}

template <typename T>
int gradoAgenRec(const Agen<T> A, typename Agen<T>::nodo n)
{
    int gradoMax = contarHijos(A, n);
    typename Agen<T>:: nodo hijo;

    hijo = A.hijoIzqdo(n);

    while(hijo != Agen<T>::NODO_NULO){
        gradoMax = std::max(gradoMax, gradoAgenRec(A, hijo));
        hijo = A.hermDrcho(hijo);
    }

    return gradoMax;
    
}

template <typename T>
int gradoAgen(const Agen<T> A)
{
    assert(!A.arbolVacio());
    return gradoAgenRec(A, A.raiz());

}

#endif