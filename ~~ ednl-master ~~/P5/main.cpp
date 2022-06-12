//
//  main.cpp
//  P5
//
//  Created by JM on 12/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#include <iostream>
#include "problema5.h"
#include "../../agen_E-S.h"
using namespace std;

Posicion pos(int fila, int col)
{
	Posicion p;
	p.fila = fila;
	p.columna = col;
	return p;
}

Cuadrante nuevo(int fila_ini, int col_ini, int celdas, Color c)
{
	Cuadrante cuad;
	
	cuad.fin = cuad.inicio = pos(fila_ini, col_ini);
	cuad.color = c;
	
	if(celdas == 4)
	{
		cuad.fin.fila++;
		cuad.fin.columna++;
	}
	
	return cuad;
}

ostream &operator<<(ostream &os, const Cuadrante &c)
{
	os << "(" << c.inicio.fila << "," << c.inicio.columna << ") a ";
	os << "(" << c.fin.fila << "," << c.fin.columna << ") ";
	switch(c.color)
	{
		case BLANCO: os << "BLANCO"; break;
		case NEGRO: os << "NEGRO"; break;
	}
	return os;
}

int main(int argc, const char * argv[]) {
	Agen<Cuadrante> A;
	Agen<Cuadrante>::nodo n;
	
	A.insertarRaiz(nuevo(0, 0, 1, NEGRO));
	
	A.insertarHijoIzqdo(A.raiz(), nuevo(0, 0, 1, BLANCO));
	n = A.hijoIzqdo(A.raiz());
	
	A.insertarHermDrcho(n, nuevo(0, 1, 1, NEGRO));
	A.insertarHermDrcho(n, nuevo(1, 1, 1, BLANCO));
	A.insertarHermDrcho(n, nuevo(1, 0, 1, NEGRO));
	//imprimirAgen(A);
	
	Figura f = Reconstruir_figura(A);
	cout << f;
	return 0;
}
