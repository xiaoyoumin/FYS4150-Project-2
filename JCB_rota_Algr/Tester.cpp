#include "Tester.h"
#include <iostream>

using namespace std;
using namespace arma;

void test_max_offdiag_symmetric(mat A) //question 3b
{
	int k, l;
	double max;
	
	max = max_offdiag_symmetric(A, k, l);

	A.print("Problem 3:\n test matrix =");
	cout << "The element with largest abs at upper diagonal is:" << "\n";
	cout << "A(" << k << ", " << l << ") = " << max << "\n";
}

void test_jacobi_eigensolver()
{
	int n = 6;
	double a = -1, d = 2;
	double eps = pow(10, -8);
	vec eigvals;
	mat eigvecs = mat(n, n, fill::eye);
	int maxiter = 1000, iterations = 0;
	bool converged;
	mat A = create_tridiagonal(n, a, d, a);
	A.print("A:");
	cout << endl << endl;

	jacobi_eigensolver(A, eps, eigvals, eigvecs, maxiter, iterations, converged);
	if (converged)
	{
		eigvecs.print("Self defined JCB rotation algr result: eigvecs");
		cout << endl;
		eigvals.print("eigvals:");
		cout << endl << endl;
	}
	else cout << "Unconverged within " << maxiter << "iterations\n";

	A = create_tridiagonal(n, a, d, a);
	eig_sym(eigvals, eigvecs, A);
	eigvecs.print("correct eigvecs from Armadillo:");
	cout << endl;
	eigvals.print("eigvals:");
	cout << endl << endl;

}

/*
void Tester::check_eig_match_anly(mat A) //question 2
{
	vec eigval;
	mat eigvec;
	eig_sym(eigval, eigvec, A);
}

void Tester::calc_anly_Sol(vec &eigval, mat &eigvec, double a, double d, mat A, int N) //question 2
{

}
*/