#include "Tester.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include<math.h>

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

void test_jacobi_eigensolver() // problem 4b here
{
	int N = 6;
	int n = N + 1;
	double h = 1.0 / n;
	double a = -1 / pow(h, 2), d = 2 / pow(h, 2);
	double eps = pow(10, -8);
	vec eigvals;
	mat eigvecs = mat(N, N, fill::eye);
	int maxiter = 1000, iterations = 0;
	bool converged;
	mat A = create_tridiagonal(N, a, d, a);
	A.print("A:");
	cout << endl << endl;

	jacobi_eigensolver(A, eps, eigvals, eigvecs, maxiter, iterations, converged);
	if (converged)
	{
		eigvecs = normalise(eigvecs);
		eigvecs.print("Self defined JCB rotation algr result: normalized eigvecs");
		cout << endl;
		eigvals.print("eigvals:");
		cout << endl << endl;
	}
	else cout << "Unconverged within " << maxiter << "iterations\n";

	eig_sym(eigvals, eigvecs, A);
	eigvecs = normalise(eigvecs);
	eigvecs.print("correct normalized eigvecs from Armadillo:");
	cout << endl;
	eigvals.print("eigvals:");
	cout << endl << endl;


	AnalyticalSols(eigvals, eigvecs, a, d, N);
	eigvecs = normalise(eigvecs);
	eigvecs.print("Analytical normalized eigvecs:");
	cout << endl;
	eigvals.print("eigvals:");
	cout << endl << endl;
}

void AnalyticalSols(vec& eigval, mat& eigvec, double a, double d, int N)
{
	int i, j;
	int n = N + 1;
	for (i = 1; i <= N; i++)
	{
		eigval(i-1) = d + 2 * a*cos((i*M_PI) / n);
		for (j = 1; j <= N; j++) {
			eigvec(i - 1, j - 1) = sin((i*j*M_PI) / n);
		}
	}

}