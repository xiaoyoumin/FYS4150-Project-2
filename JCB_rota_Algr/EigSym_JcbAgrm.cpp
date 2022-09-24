#include "EigSym_JcbAgrm.h"
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

class UnSymException :public exception
{
public:
	UnSymException(string str) :exception(str.c_str()) {}
};



void sym_check(mat A, int n)
{
	int i, j;

	for (i = 0; i < n-1; i++)
		for (j = i + 1; j < n; j++)
			if (A(i, j) != A(j, i))
			{
				throw UnSymException("Only symmetric matrix is allowed");
				exit(-1);
			}
}


double max_offdiag_symmetric(const mat A, int& k, int &l)
{
	int i, j;
	int n = arma::size(A).n_rows;
	double max=0;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (abs(A(i, j)) > max)
			{
				max = abs(A(i, j));
				k = i; //row index
				l = j; //col index
			}
	return max;
}

mat create_tridiagonal(int n, double a, double d, double e)
{
	mat A = mat(n, n, fill::eye);
	int i;
	A(0, 0) = d;
	A(0, 1) = e;
	A(n - 1, n - 1) = d;
	A(n - 1, n - 2) = a;
	for (i = 1; i < n - 1; i++)
	{
		A(i, i) = d;
		A(i, i - 1) = a;
		A(i, i + 1) = e;
	}
	return A;
}

void jacobi_eigensolver(const mat& A, double eps, vec& eigenvalues, mat& eigenvectors,
	const int maxiter, int& iterations, bool& converged)
{
	try
	{
		sym_check(A, arma::size(A).n_rows);
	}
	catch (exception& e)
	{
		cout << "ERROR: " << e.what() << "\n";
		exit(-1);
	}

	int n = arma::size(A).n_rows;
	int k, l;  //row, col
	mat A_temp = A;

	eigenvectors = mat(n, n, fill::eye);
	eigenvalues = zeros(n);

	iterations = 0;

	while (max_offdiag_symmetric(A_temp, k, l) > eps && iterations < maxiter)
	{
		jacobi_rotate(A_temp, eigenvectors, k, l);
		iterations++;
	}

	if (iterations == maxiter) converged = false;
	else
	{
		converged = true;
		for (int i = 0; i < n; i++)
			eigenvalues(i) = A_temp(i, i);
	}
}

void jacobi_rotate(mat& A, mat& R, int k, int l)
{
	double tau, t, s, c;
	double temp; //to preserve element in previous A and R
	int n = arma::size(A).n_rows;
	int i;

	tau = (A(l, l) - A(k, k)) / (2 * A(k, l));

	t = (-tau + sqrt(1 + pow(tau, 2))) > (-tau - sqrt(1 + pow(tau, 2))) ?
		-tau - sqrt(1 + pow(tau, 2)) : -tau + sqrt(1 + pow(tau, 2));
	c = 1 / sqrt(1 + pow(t, 2));
	s = c * t;
	
	temp = A(k, k);
	A(k, k) = A(k, k)*pow(c, 2) - 2 * A(k, l)*c*s + A(l, l)*pow(s, 2);
	A(l, l) = A(l, l)*pow(c, 2) + 2 * A(k, l)*c*s + temp*pow(s, 2);
	A(k, l) = 0;
	A(l, k) = 0;

	for (i = 0; i < n; i++)
	{
		if (i != k && i != l)
		{
			temp = A(i, k);
			A(i, k) = A(i, k)*c - A(i, l)*s;
			A(k, i) = A(i, k);
			A(i, l) = A(i, l)*c + temp*s;
			A(l, i) = A(i, l);
		}
			
		temp = R(i, k);
		R(i, k) = R(i, k)*c - R(i, l)*s;
		R(i, l) = R(i, l)*c + temp*s;
	}

}