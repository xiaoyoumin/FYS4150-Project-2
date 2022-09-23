

#include <iostream>
#include <string>
//#include <armadillo>

#include "Tester.h"
//#include "EigSym_JcbAgrm.h"

using namespace std;
using namespace arma;

int main()
{
	mat A = { {1,0,0,0.5},
			{0,1,-0.7,0},
			{0,-0.7,1,0},
			{0.5,0,0,1} };

	test_max_offdiag_symmetric(A);
	cout << endl << endl;
	test_jacobi_eigensolver();

	return 0;
}

