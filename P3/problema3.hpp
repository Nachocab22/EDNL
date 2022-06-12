#ifndef PROBLEMA3_HPP
#define PROBLEMA3_HPP

#include "../agen.h"

//Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas de los subárboles más bajo y más alto de cada nivel. 
//Implementa un subprograma que calcule el grado de desequilibrio de un árbol general. 

template <typename T>
int alturaNodo(const Agen<T> &A, typename Agen<T>::nodo n)
{
    int altura;
    typename Agen<T>::nodo hijo;

    if(n != Agen<T>::NODO_NULO){
        altura = 0;
        hijo = A.hijoIzqdo(n);
        while (hijo != Agen<T>::NODO_NULO)
        {
            altura = std::max(altura, 1 + alturaNodo(A, hijo));
            hijo = A.hermDrcho(hijo);
        } 
    }
    else
        altura = -1;
    
    return altura;
}

template <typename T>
int desequilibrioAgen(const Agen<T> &A)
{
    return desequilibrioAgenRec()
}

template <typename T>
int desequilibrioAgenRec(const Agen<T> &A, typename Agen<T>::nodo n)
{
    typename Agen<T>::nodo hijo;
    int alt_max, alt_min, alt_actual, dif_max;

    hijo = A.hijoIzqdo(n);
    dif_max = 0;
    alt_max = std::numeric_limits<int>::min()
    alt_min = std::numeric_limits<int>::max()

    while (hijo != Agen<T>::NODO_NULO)
    {
        alt_actual = alturaNodo(A, hijo);
        alt_max = std::max(alt_actual, alt_max);
        alt_min = std::min(alt_actual, alt_min);
        dif_max = std::max(alt_max - alt_min, desequilibrioAgenRec(A, hijo));
        hijo = A.hermDrcho(hijo);
    }
    return dif_max;
}

#endif