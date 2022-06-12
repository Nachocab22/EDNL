#ifndef problema4_h
#define problema4_h
#include <cmath>

template <typename T>
class Abin
{
public:
	typedef int nodo;
	static nodo NODO_NULO;
	
	Abin(int altura_max, T elto_nulo = T());
	Abin(const Abin<T>&);
	Abin<T> &operator=(const Abin<T>&);
	
	void insertarRaiz(const T&);
	void insertarHijoIzqdo(nodo, const T&);
	void insertarHijoDrcho(nodo, const T&);
	nodo padre(nodo) const;
	nodo hijoIzqdo(nodo) const;
	nodo hijoDrcho(nodo) const;
	bool arbolVacio() const;
	nodo raiz() const;
	const T &elemento(nodo) const;
	
	~Abin();
	
private:
	T *eltos;
	int alt;
	int tam;
	const T nulo;
	
	int profundidad(nodo) const;
	int profundidad_rec(nodo, nodo, nodo) const;
	bool esHijoIzqdo(nodo) const;
};

template <typename T>
typename Abin<T>::nodo Abin<T>::NODO_NULO(-1);

template <typename T>
inline Abin<T>::Abin(int altura_max, T nulo) : eltos(new T[pow(2, altura_max+1)-1]), alt(altura_max), tam(pow(2, altura_max+1)-1),
	nulo(nulo)
{
	for(int i = 0; i < tam; i++)
		eltos[i] = nulo;
}

template <typename T>
inline Abin<T>::Abin(const Abin<T> &A) : eltos(new T[A.tam]), alt(A.alt), tam(A.tam), nulo(A.nulo)
{
	for(int i = 0; i < tam; i++)
		eltos[i] = nulo;
}

template <typename T>
Abin<T> &Abin<T>::operator=(const Abin<T> &A)
{
	if(this != &A)
	{
		if(tam != A.tam)
		{
			tam = A.tam;
			alt = A.alt;
			delete[] eltos;
			eltos = new T[tam];
		}
		for(int i = 0; i < tam; i++)
			eltos[i] = A.eltos[i];
	}
	return *this;
}

template <typename T>
inline Abin<T>::~Abin()
{
	delete[] eltos;
}

template <typename T>
int Abin<T>::profundidad(nodo n) const
{
	return profundidad_rec(0, tam-1, n);
}

template <typename T>
int Abin<T>::profundidad_rec(nodo inicio, nodo fin, nodo n) const
{
	nodo mitad = (inicio + fin) / 2;
	if(mitad == n)
		return 0;
	else
	{
		if(n < mitad)
			return 1 + profundidad_rec(inicio, mitad, n);
		else
			return 1 + profundidad_rec(mitad, fin, n);
	}
}

template <typename T>
bool Abin<T>::esHijoIzqdo(nodo n) const
{
	int prof = profundidad(n);
	return (n % ((tam+1)/pow(2, prof-1))) == (((tam+1)/pow(2, prof+1))-1);
}

template <typename T>
void Abin<T>::insertarRaiz(const T &x)
{
	assert(eltos[tam/2] == nulo);
	eltos[tam/2] = x;
}

template <typename T>
void Abin<T>::insertarHijoIzqdo(nodo n, const T &x)
{
	assert(n != NODO_NULO);
	assert(n < tam);
	int prof = profundidad(n);
	assert(prof != alt);
	int hizq = n - (tam+1) / pow(2, prof+2);
	eltos[hizq] = x;
}

template <typename T>
void Abin<T>::insertarHijoDrcho(nodo n, const T &x)
{
	assert(n != NODO_NULO);
	assert(n < tam);
	int prof = profundidad(n);
	assert(prof != alt);
	int hder = n + (tam+1) / pow(2, prof+2);
	eltos[hder] = x;
}

template <typename T>
typename Abin<T>::nodo Abin<T>::padre(nodo n) const
{
	assert(n != tam/2);
	int prof = profundidad(n);
	if(esHijoIzqdo(n))
		return n + (tam+1) / pow(2, prof+1);
	else
		return n - (tam+1) / pow(2, prof+1);
}

template <typename T>
typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const
{
	assert(n != NODO_NULO);
	assert(n < tam);
	int prof = profundidad(n);
	assert(prof <= alt);
	nodo hijo =  n - (tam+1) / pow(2, prof+2);
	if(eltos[hijo] == nulo)
		return NODO_NULO;
	else
		return hijo;
}

template <typename T>
typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const
{
	assert(n != NODO_NULO);
	assert(n < tam);
	int prof = profundidad(n);
	assert(prof <= alt);
	nodo hijo = n + (tam+1) / pow(2, prof+2);
	if(eltos[hijo] == nulo)
		return NODO_NULO;
	else
		return hijo;
}

template <typename T>
bool Abin<T>::arbolVacio() const
{
	return eltos[tam/2] == nulo;
}

template <typename T>
typename Abin<T>::nodo Abin<T>::raiz() const
{
	return tam/2;
}

template <typename T>
const T &Abin<T>::elemento(nodo n) const
{
	assert(n != NODO_NULO);
	assert(n < tam);
	return eltos[n];
}

#endif /* problema4_h */
