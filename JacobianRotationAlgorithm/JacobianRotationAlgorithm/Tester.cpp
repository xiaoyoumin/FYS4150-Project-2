#include "Tester.h"
#include <iostream>

using namespace std;

void Tester::test_max_offdiag_symmetric(mat A) //question 3b
{
	int k, l;
	double max;
	try
	{
		EigSym_JcbAgrm eig = EigSym_JcbAgrm(A, 4);
		max = eig.max_offdiag_symmetric(k, l);
	}
	catch (exception& e)
	{
		cout << "ERROR: " << e.what() << "\n";
		exit(-1);
	}
	
	A.print("A:");
	cout << "The element with largest abs at upper diagonal is:" << "\n";
	cout << "A(" << k << ", " << l << ") = " << max << "\n";
}

void Tester::check_eig_match_anly(mat A) //question 2
{
	vec eigval;
	mat eigvec;
	//eig_sym(eigval, eigvec, A);
}

void Tester::calc_anly_Sol(vec &eigval, mat &eigvec, double a, double d, mat A, int N) //question 2
{

}