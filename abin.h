//
//  aBin.h
//  arbolBinario
//
//  Created by JM on 26/02/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef aBin_h
#define aBin_h
#include <cassert>

template <typename T> class Abin {
	struct celda;
public:
	//DEFINICIONES PUBLICAS DE TIPOS
	typedef celda* nodo;
	static const nodo NODO_NULO;
	//CONSTRUCTORES Y COPIAS
	Abin();
	Abin(const Abin<T>&);
	Abin<T> &operator=(const Abin<T>&);
	
	//FUNCIONES MODIFICADORAS
	void insertarRaiz(const T&);
	void insertarHijoIzqdo(nodo, const T&);
	void insertarHijoDrcho(nodo, const T&);
	void eliminarHijoIzqdo(nodo);
	void eliminarHijoDrcho(nodo);
	void eliminarRaiz();
	T &elemento(nodo);
	
	//FUNCIONES CONSULTORAS
	bool arbolVacio() const;
	const T &elemento(nodo) const;
	nodo raiz() const;
	nodo padre(nodo) const;
	nodo hijoIzqdo(nodo) const;
	nodo hijoDrcho(nodo) const;
	
	//DESTRUCTOR
	~Abin();
	
private:
	//DEFINICIONES DE TIPOS PRIVADAS
	struct celda {
		inline celda(const T &x, nodo p = NODO_NULO) : elto(x), padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
		T elto;
		nodo padre, hizq, hder;
	};
	nodo r;
	
	//FUNCIONES PRIVADAS
	void destruirNodos(nodo&);
	nodo copiar(nodo);
};

template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(0);

template <typename T>
inline Abin<T>::Abin() : r(NODO_NULO) {}

template <typename T>
inline Abin<T>::Abin(const Abin<T> &a) : r(copiar(a.r)) {}
 
template <typename T>
Abin<T> &Abin<T>::operator=(const Abin<T> &a) {
	if(this != &a) {
		this->~Abin();
		r = copiar(a.r);
	}
	return *this;
}

template <typename T>
inline void Abin<T>::insertarRaiz(const T &x) {
	assert(r == NODO_NULO);
	r = new celda(x);
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T &x) {
	assert(n != NODO_NULO);
	assert(n->hizq == NODO_NULO);
	n->hizq = new celda(x, n);
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T &x) {
	assert(n != NODO_NULO);
	assert(n->hder == NODO_NULO);
	n->hder = new celda(x, n);
}

template <typename T>
inline void Abin<T>::eliminarHijoIzqdo(nodo n) {
	assert(n != NODO_NULO);
	assert(n->hizq != NODO_NULO);
	assert(n->hizq->hizq == NODO_NULO &&
		   n->hizq->hder == NODO_NULO);
	delete n->hizq;
	n->hizq = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarHijoDrcho(nodo n) {
	assert(n != NODO_NULO);
	assert(n->hder != NODO_NULO);
	assert(n->hder->hizq == NODO_NULO &&
		   n->hder->hder == NODO_NULO);
	delete n->hder;
	n->hder = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarRaiz() {
	assert(r != NODO_NULO);
	assert(r->hder == NODO_NULO && r->hizq == NODO_NULO);
	delete r;
	r = NODO_NULO;
}

template <typename T>
inline T &Abin<T>::elemento(nodo n) {
	assert(n != NODO_NULO);
	return n->elto;
}

template <typename T>
inline bool Abin<T>::arbolVacio() const {
	return r == NODO_NULO;
}

template <typename T>
inline const T &Abin<T>::elemento(nodo n) const {
	assert(n != NODO_NULO);
	return n->elto;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const {
	return r;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::padre(nodo n) const {
	assert(n != NODO_NULO);
	return n->padre;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const {
	assert(n != NODO_NULO);
	return n->hizq;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const {
	assert(n != NODO_NULO);
	return n->hder;
}

template <typename T>
void Abin<T>::destruirNodos(nodo &n) {
	if(n != NODO_NULO) {
		destruirNodos(n->hizq);
		destruirNodos(n->hder);
		delete n;
		n = NODO_NULO;
	}
}

template <typename T>
typename Abin<T>::nodo Abin<T>::copiar(nodo n) {
	nodo m = NODO_NULO;
	if(n != NODO_NULO) {
		m = new celda(n->elto);
		m->hizq = copiar(n->hizq);
		if(m->hizq != NODO_NULO)
			m->hizq->padre = m;
		m->hder = copiar(n->hder);
		if(m->hder != NODO_NULO)
			m->hder->padre = m;
	}
	return m;
}

template <typename T>
inline Abin<T>::~Abin() {destruirNodos(r);}

#endif /* aBin_h */
