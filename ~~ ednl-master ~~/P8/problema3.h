#ifndef prac8_prob3_hpp
#define prac8_prob3_hpp
#include <cassert>

template <typename T> class Apo_max {
public:
   explicit Apo_max(size_t maxNodos);       // constructor
   void insertar(const T& e);
   void suprimir();
   const T& cima() const;
   bool vacio() const;
   Apo_max(const Apo_max& A);                   // ctor. de copia
   Apo_max& operator =(const Apo_max& A);       // asignaciÛn de apo
   ~Apo_max();                              // destructor
private:
   typedef int nodo; // Ìndice de la matriz
                     // entre 0 y maxNodos-1
   T* nodos;      // vector de nodos
   int maxNodos;  // tamaÒo del vector
   nodo ultimo;   // ˙ltimo nodo del ·rbol

   nodo padre(nodo i) const { return (i-1)/2; }
   nodo hIzq(nodo i)  const { return 2*i+1; }
   nodo hDer(nodo i)  const { return 2*i+2; }
   void flotar(nodo i);
   void hundir(nodo i);
};

/*--------------------------------------------------------*/
/* clase Apo_max genÈrica: Vector de posiciones relativas.    */
/*    Un Apo_max de n nodos se almacena en celdas             */
/*    consecutivas del vector, desde 0 hasta n-1 (ultimo).*/
/*    La raÌz del APO se almacena en la celda 0 del       */
/*    vector. Al hijo izquierdo del nodo i le corresponde */
/*    la celda 2i+1 y al hijo derecho la celda 2i+2.      */
/*                                                        */
/* ImplementaciÛn de operaciones                          */
/*--------------------------------------------------------*/

template <typename T>
inline Apo_max<T>::Apo_max(size_t maxNodos) :
   nodos(new T[maxNodos]),
   maxNodos(maxNodos),
   ultimo(-1)   // Apo_max vacÌo
{}

template <typename T>
inline void Apo_max<T>::insertar(const T& e)
{
   assert(ultimo < maxNodos-1);   // Apo_max no lleno
   nodos[++ultimo] = e;
   flotar(ultimo);
}

template <typename T>
inline void Apo_max<T>::suprimir()
{
   assert(ultimo > -1);   // Apo_max no vacÌo
   if (--ultimo > -1) {     // Apo_max no queda vacÌo.
      nodos[0] = nodos[ultimo+1];
      if (ultimo > 0)     // Quedan dos o m·s elementos. Reordenar
         hundir(0);
   }
}

template <typename T>
inline const T& Apo_max<T>::cima() const
{
   assert(ultimo > -1);   // Apo_max no vacÌo
   return nodos[0];
}

template <typename T>
inline bool Apo_max<T>::vacio() const
{
   return (ultimo == -1);
}

template <typename T>
inline Apo_max<T>::~Apo_max()
{
   delete[] nodos;
}

template <typename T>
Apo_max<T>::Apo_max(const Apo_max<T>& A) :
   nodos(new T[A.maxNodos]),
   maxNodos(A.maxNodos),
   ultimo(A.ultimo)
{
   // copiar el vector
   for (nodo n = 0; n <= ultimo; n++)
      nodos[n] = A.nodos[n];
}

template <typename T>
Apo_max<T>& Apo_max<T>::operator =(const Apo_max<T>& A)
{
   if (this != &A) {   // evitar autoasignaciÛn
      // Destruir el vector y crear uno nuevo si es necesario
      if (maxNodos != A.maxNodos) {
         delete[] nodos;
         maxNodos = A.maxNodos;
         nodos = new T[maxNodos];
      }
      ultimo = A.ultimo;
      // Copiar el vector
      for (nodo n = 0; n <= ultimo; n++)
         nodos[n] = A.nodos[n];
   }
   return *this;
}

// MÈtodos privados

template <typename T>
void Apo_max<T>::flotar(nodo i)
{
   T e = nodos[i];
   while (i > 0 && nodos[padre(i)] < e) {
      nodos[i] = nodos[padre(i)];
      i = padre(i);
   }
   nodos[i] = e;   // colocar e
}

template <typename T>
void Apo_max<T>::hundir(nodo i)
{
   bool fin = false;
   T e = nodos[i];
   while (hIzq(i) <= ultimo && !fin) {   // hundir e
      nodo hMax;   // hijo mayor del nodo i
      if (hIzq(i) < ultimo && nodos[hIzq(i)] < nodos[hDer(i)])
         hMax = hDer(i);
      else
         hMax = hIzq(i);
      if (e < nodos[hMax]) { // subir el hijo mayor
         nodos[i] = nodos[hMax];
         i = hMax;
      }
      else   // e > hMax
         fin = true;
   }
   nodos[i] = e;   // colocar e
}

#endif /* prac8_prob3_hpp */
