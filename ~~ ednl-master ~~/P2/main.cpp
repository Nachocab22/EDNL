//
//  main.cpp
//  P2
//
//  Created by JM on 05/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#include <iostream>
#include "problema4.h"
#include "../../abin_E-S.h"
using namespace std;

int main(int argc, const char * argv[]) {
	Abin<char> A(4, '-');
	
	A.insertarRaiz('h');
	Abin<char>::nodo n = 15;
	
	A.insertarHijoIzqdo(n, 'a');
	A.insertarHijoDrcho(n, 'm');
	
	imprimirAbin(A);
	
	return 0;
}
