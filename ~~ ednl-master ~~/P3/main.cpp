//
//  main.cpp
//  P3
//
//  Created by JM on 07/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "problema4.h"
#include "../../agen_E-S.h"
using namespace std;

int main(int argc, const char * argv[]) {
	Agen<int> A, B;
	
	ifstream fe("agen.dat");
	rellenarAgen(fe, A);
	
	cout << "Antes de podar:\n";
	imprimirAgen(A);
	
	B = A;
	cout << "Podar 1";
	podarAgen(B, 2);
	imprimirAgen(B);
}
