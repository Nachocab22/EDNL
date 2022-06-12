#include <iostream>
#include <fstream>
#include "problema7.h"
#include "../../abin_E-S.h"
using namespace std;

int main(int argc, const char * argv[]) {
	Abin<char> A;
	Abin<char>::nodo n;
	ifstream is("abin.dat");
	rellenarAbin(is, A);
	
	n = A.raiz();			// a
	n = A.hijoIzqdo(n);		// b
	n = A.hijoDrcho(n);		// e
	n = A.hijoDrcho(n);		// f
	
	cout << "Es pseudocompleto: " << boolalpha << abinPseudocompleto(A) << '\n';
	
	return 0;
}
