//
//  main.cpp
//  P4
//
//  Created by JM on 07/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#include <iostream>
#include <vector>
#include "problema5.h"
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Abb<T> &A)
{
	if(A.vacio())
		os << "Árbol vacío";
	else
	{
		os << A.elemento() << ' ';
		if(!A.drcho().vacio())
			os << A.drcho();
		if(!A.izqdo().vacio())
			os << A.izqdo();
	}
	return os;
}

int main(int argc, const char * argv[]) {
	Abb<int> A;
	int elto = 17;
	for(int x : {7, 5, 12, 9, 17, 8, 11, 10})
		A.insertar(x);
	
	return 0;
}
